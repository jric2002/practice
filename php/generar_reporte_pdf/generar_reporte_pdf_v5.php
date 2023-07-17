<?php
require_once("./fpdf/fpdf.php");
const HOSTNAME = "localhost";
const USERNAME = "root";
const PASSWORD = "admin";
const DATABASE_NAME = "empresa";
$database_name = DATABASE_NAME;
$connection = new mysqli(HOSTNAME, USERNAME, PASSWORD, DATABASE_NAME);
$fields = NULL;
$r = NULL;
if (isset($_POST["consulta"])) {
  switch ($_POST["consulta"]) {
    case "tc":
      $query = $connection->prepare("SELECT TABLE_NAME AS table_name FROM information_schema.tables WHERE table_schema=?");
      $query->bind_param("s", $database_name);
      if ($query->execute()) {
        $tablas = $query->get_result();
        $tablas = $tablas->fetch_all(MYSQLI_ASSOC);
        $tc = array();
        foreach ($tablas as $t) {
          foreach ($t as $k => $v) {
            $tc[$v]= array();
            $query = $connection->prepare("SELECT COLUMN_NAME AS column_name FROM information_schema.columns WHERE TABLE_SCHEMA = ? AND TABLE_NAME = ?");
            $query->bind_param("ss", $database_name, $v);
            if ($query->execute()) {
              $cols = $query->get_result();
              $cols = $cols->fetch_all(MYSQLI_ASSOC);
              foreach ($cols as $cl) {
                foreach ($cl as $kc => $vc) {
                  $tc[$v][] = $vc;
                }
              }
            }
          }
        }
        header("Content-Type: application/json");
        echo json_encode($tc);
      }
      exit();
      break;
    case "salario":
      if (isset($_POST["min"]) && isset($_POST["max"]) && isset($_POST["cifras"])) {
        $min = intval($_POST["min"]);
        $max = intval($_POST["max"]);
        $cifras = intval($_POST["cifras"]);
        $query = $connection->prepare("SELECT nombre, apellido, salario FROM empleado WHERE salario BETWEEN ? AND ?");
        $query->bind_param("ii", $min, $max);
        if ($query->execute()) {
          $r = $query->get_result();
          $fields = $r->fetch_fields();
          $r = $r->fetch_all(MYSQLI_ASSOC);
          // Genera el Reporte en PDF
          $pdf = new FPDF();
          $ancho_celda = 62;
          $alto_celda = 10;
          $pdf->AddPage();
          // Título del documento
          $pdf->SetFont("Arial", "B", 20);
          $pdf->Cell(0, 10, "Reporte de la Consulta", 0, 1, "C");
          $pdf->Ln(10);
          // Encabezado de la tabla
          $pdf->SetFont("Arial", "B", 16);
          $pdf->Cell($ancho_celda, $alto_celda, "Nombre", 1, 0, "C");
          $pdf->Cell($ancho_celda, $alto_celda, "Apellido", 1, 0, "C");
          $pdf->Cell($ancho_celda, $alto_celda, "Salario", 1, 0, "C");
          $pdf->Ln();
          // Datos de la tabla
          $pdf->SetFont("Arial", "", 14);
          $s_total = 0;
          foreach($r as $row){
            foreach($row as $k => $v) {
              if ($k == "salario") {
                $s_total += $v;
                $v = str_pad($v, $cifras, "0", STR_PAD_LEFT);
              }
              $pdf->Cell($ancho_celda, $alto_celda, $v, 1, 0, "C");
            }
            $pdf->Ln();
          }
          // Total de salario
          $pdf->SetFont("Arial", "B", 14);
          $pdf->Cell($ancho_celda * 2, $alto_celda, "Total de salario", 1, 0, "C");
          $s_total = str_pad($s_total, $cifras, "0", STR_PAD_LEFT);
          $pdf->SetFont("Arial", "", 14);
          $pdf->Cell($ancho_celda, $alto_celda, $s_total, 1, 0, "C");
          $pdf->Output("F", "./reporte_pdf.pdf");
          exit();
        }
      }
      else {
        echo "Salario mínimo y máximo no esta definido";
      }
      break;
    case "fn":
      if (isset($_POST["fmin"]) && isset($_POST["fmax"])) {
        $fmin = $_POST["fmin"];
        $fmax = $_POST["fmax"];
        $query = $connection->prepare("SELECT nombre, apellido, fecha_n FROM empleado WHERE fecha_n BETWEEN ? AND ?");
        $query->bind_param("ss", $fmin, $fmax);
        if ($query->execute()) {
          $r = $query->get_result();
          $fields = $r->fetch_fields();
          $r = $r->fetch_all(MYSQLI_ASSOC);
          // Genera el Reporte en PDF
          $pdf = new FPDF();
          $ancho_celda = 62;
          $alto_celda = 10;
          $pdf->AddPage();
          // Título del documento
          $pdf->SetFont("Arial", "B", 20);
          $pdf->Cell(0, 10, "Reporte de la Consulta", 0, 1, "C");
          $pdf->Ln(10);
          // Encabezado de la tabla
          $pdf->SetFont("Arial", "B", 16);
          $pdf->Cell($ancho_celda, $alto_celda, "Nombre", 1, 0, "C");
          $pdf->Cell($ancho_celda, $alto_celda, "Apellido", 1, 0, "C");
          $pdf->Cell($ancho_celda, $alto_celda, "Fecha de nacimiento", 1, 0, "C");
          $pdf->Ln();
          // Datos de la tabla
          $pdf->SetFont("Arial", "", 14);
          foreach($r as $row){
            foreach($row as $k => $v) {
              $pdf->Cell($ancho_celda, $alto_celda, $v, 1, 0, "C");
            }
            $pdf->Ln();
          }
          $pdf->Output("F", "reporte_pdf.pdf");
          exit();
        }
      }
      else {
        echo "Fecha de nacimiento mínimo y máximo no esta definido";
      }
      break;
    default:
      echo "Esa consulta no es válida";
      break;
  }
}
?>
<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Generador de Reporte</title>
    <style>
      * {
        font-family: sans-serif;
        font-size: 1rem;
      }
      :root {
        --black-color: #000000;
        --gray-color: #0f0f12;
        --second-color-gray: #8b949e;
        --green-color: #98ca3f;
        --yellow-color: #fcee0a;
        --sky-blue-color: #2490fc;
        --white-color: #ffffff;
      }
      h1 {
        text-align: center;
      }
      form select.consulta, form div.datos-entrada, form input[type="submit"] {
        margin: 0 0 1rem;
      }
      form input {
        font-size: 1rem;
      }
      form input[type="text"] {
        width: 6rem;
      }
      form input[type="number"] {
        width: 3rem;
      }
      form input[type="submit"] {
        color: var(--white-color);
        background-color: var(--sky-blue-color);
        transition: background-color 0.25s linear;
      }
      form input[type="submit"]:hover {
        color: var(--white-color);
        background-color: var(--green-color);
      }
    </style>
  </head>
  <body>
    <div class="consulta">
      <div class="tablas">
        <h1>Tablas</h1>
        <select name="tabla" id="tabla">
        </select>
      </div>
      <div class="campos"></div>
      <div class="agrupacion">
        <div class="campo-opcion">
        </div>
      </div>
    </div>
    <form action="./<?php echo $_SERVER["PHP_SELF"];?>" method="post" class="form" id="form">
      <h1>GENERADOR DE REPORTE</h1>
      <label for="consulta">Consulta:</label>
      <select name="consulta" class="consulta" id="consulta">
        <option value="salario" selected>Salario</option>
        <option value="fn">Fecha de nacimiento</option>
      </select>
      <div class="datos-entrada" id="datos-entrada"></div>
      <input type="submit" value="Buscar" id="buscar">
    </form>
    <section class="resultado" id="resultado">
      <!-- <div class="parametros"></div> -->
    </section>
    <script type="text/javascript">
      const PROTOCOL = window.location.protocol;
      const HOST = window.location.host;
      const PATHNAME = window.location.pathname;
      const URL = PROTOCOL + "//" + HOST;
      const FORM = document.getElementById("form");
      const DATOS_ENTRADA = document.getElementById("datos-entrada");
      const CONSULTA = document.getElementById("consulta");
      const RESULTADO = document.getElementById("resultado");
      const TABLA = document.getElementById("tabla");
      var consultas = {
        salario: {
          contenido_form: `
            <label for="min">Mínimo:</label>
            <input type="text" name="min" id="min" value="3000">
            <label for="max">Máximo:</label>
            <input type="text" name="max" id="max" value="5000">
            <label for="cifras">Cifras:</label>
            <input type="number" name="cifras" class="cifras" id="cifras" min="0" value="0">`,
          data: function() {
            const MIN = document.getElementById("min");
            const MAX = document.getElementById("max");
            const CIFRAS = document.getElementById("cifras");
            return ("min=" + encodeURIComponent(MIN.value) + "&max=" + encodeURIComponent(MAX.value) + "&cifras=" + encodeURIComponent(CIFRAS.value));
          }
        },
        fn: {
          contenido_form: `
            <label for="fmin">Mínimo:</label>
            <input type="date" name="fmin" id="fmin" value="1950-01-01">
            <label for="fmax">Máximo:</label>
            <input type="date" name="fmax" id="fmax" value="1960-01-01">`,
          data: function() {
            const FMIN = document.getElementById("fmin");
            const FMAX = document.getElementById("fmax");
            return ("fmin=" + encodeURIComponent(FMIN.value) + "&fmax=" + encodeURIComponent(FMAX.value));
          }
        }
      };
      DATOS_ENTRADA.innerHTML = consultas[CONSULTA.value]["contenido_form"];
      CONSULTA.addEventListener("change", function() {
        DATOS_ENTRADA.innerHTML = consultas[CONSULTA.value]["contenido_form"];
      });
      async function requestTC(url, data) {
        return await new Promise((resolve, reject) => {
          const REQUEST = new XMLHttpRequest();
          REQUEST.open("POST", url);
          REQUEST.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
          REQUEST.addEventListener("load", function(e) {
            if (REQUEST.status === 200) {
              resolve({
                error: false,
                value: REQUEST.responseText
              });
            }
            else {
              reject({
                error: true,
                message: "Ha ocurrido un error en la solicitud"
              });
            }
          });
          // console.log(d);
          REQUEST.send(data);
        });
      }
      requestTC(URL + (FORM.getAttribute("action")).slice(1), "consulta=tc").then((r) => {
        let d = JSON.parse(r["value"]);
        let tabla_contenido = ``;
        for (tn in d) {
          tabla_contenido += `<option value="${tn}" selected>${tn}</option>`;
        }
        TABLA.innerHTML = tabla_contenido;
      }).catch((e) => {
        console.log(e);
      })
      FORM.addEventListener("submit", function(event) {
        event.preventDefault();
        const REQUEST = new XMLHttpRequest();
        REQUEST.open("POST", URL + (FORM.getAttribute("action")).slice(1));
        REQUEST.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
        REQUEST.addEventListener("load", function(e) {
          if (REQUEST.status === 200) {
            RESULTADO.innerHTML = `<embed src="./reporte_pdf.pdf" class="pdf-viewer" id="pdf-viewer" type="application/pdf" width="100%" height="720px"/>`;
          }
          else {
            console.log("Error en la solicitud");
          }
        });
        let d = "consulta=" + encodeURIComponent(CONSULTA.value) + "&" + consultas[CONSULTA.value]["data"]();
        // console.log(d);
        REQUEST.send(d);
      });
    </script>
  </body>
</html>