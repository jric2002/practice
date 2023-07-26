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
    case "custom":
      header("Content-Type: application/json");
      echo json_encode(json_decode($_POST["datos"]));
      if (isset($_POST["datos"])) {
        $min = 2000;
        $max = 6000;
        $cifras = 0;
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
        }
      }
      exit();
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
        padding: 0;
        margin: 0;
      }
      :root {
        --black-color: #000000;
        --gray-color: #0f0f12;
        --second-color-gray: #8b949e;
        --green-color: #98ca3f;
        --yellow-color: #fcee0a;
        --sky-blue-color: #2490fc;
        --white-color: #ffffff;
        --border-radius-g: 10px;
      }
      .gen-rep {
        color: var(--white-color);
        background-color: rgba(0, 0, 0, 0.5);
        border-radius: var(--border-radius-g);
        display: grid;
        grid-template-areas: "title"
                              "consulta";
        margin: 1rem;
      }
      .gen-rep h1 {
        grid-area: title;
        font-size: 1.5rem;
        border-bottom: 1px solid var(--white-color);
        text-align: center;
        padding: 0.5rem;
      }
      .gen-rep .consulta {
        grid-area: consulta;
        display: grid;
        grid-template-areas: "tbs cps agrp";
      }
      .gen-rep .consulta .tbs select {
        border-radius: var(--border-radius-g);
        padding: 0.25rem 0.5rem;
        margin: 1rem 0;
      }
      .gen-rep .consulta .tbs .tablas-seleccionadas > div {
        background-color: var(--gray-color);
        border-radius: var(--border-radius-g);
        padding: 0.75rem;
        margin: 0.25rem 0;
      }
      .tbs {
        grid-area: tbs;
      }
      .cps {
        grid-area: cps;
      }
      .agrp {
        grid-area: agrp;
      }
      .tbs, .cps, .agrp {
        background-color: rgba(0, 0, 0, 0.25);
        border-radius: var(--border-radius-g);
        padding: 1rem;
        margin: 0.5rem;
      }
      .gen-rep .consulta .cps .campos {
        margin: 0.75rem 0;
      }
      .gen-rep .consulta .cps .campos > div {
        background-color: var(--sky-blue-color);
        border-radius: var(--border-radius-g);
        padding: 0.75rem;
        margin: 0.25rem 0;
      }
      .gen-rep .consulta .agrp .campo-opcion {
        border-radius: var(--border-radius-g);
        margin: 0.75rem 0;
      }
      .gen-rep .consulta .agrp .campo-opcion .cp-agrp {
        display: flex;
        justify-content: center;
        align-items: center;
        background-color: var(--sky-blue-color);
        border-radius: var(--border-radius-g) 0 0 var(--border-radius-g);
        padding: 0.75rem;
        margin: 0.25rem 0;
      }
      .gen-rep .consulta .agrp .campo-opcion .opcion {
        color: var(--white-color);
        background-color: var(--gray-color);
        border-radius: 0 var(--border-radius-g) var(--border-radius-g) 0;
        border: none;
        margin: 0 0 0 0.5rem;
      }
      .gen-rep input[type="submit"] {
        color: var(--white-color);
        background-color: var(--sky-blue-color);
        font-weight: bold;
        border: none;
        border-radius: 0 0 var(--border-radius-g) var(--border-radius-g);
        padding: 0.75rem;
        transition: background-color 0.25s linear;
      }
      .gen-rep input[type="submit"]:hover {
        background-color: var(--green-color);
      }
      .resultado {
        margin: 1rem;
      }
    </style>
  </head>
  <body>
    <form class="gen-rep" class="form" id="form" action=".<?php echo $_SERVER["PHP_SELF"];?>" method="post">
      <h1>GENERADOR DE REPORTE</h1>
      <div class="consulta">
        <div class="tbs">
          <h1>Tablas</h1>
          <select name="tablas" id="tablas">
          </select>
          <div class="tablas-seleccionadas" id="tablas-seleccionadas"></div>
        </div>
        <div class="cps">
          <h1>Campos</h1>
          <div class="campos" id="campos" ondrop="drop(event)" ondragover="allowDrop(event)"></div>
        </div>
        <div class="agrp">
          <h1>Agrupación</h1>
          <div class="campo-opcion" id="campo-opcion" ondrop="drop(event)" ondragover="allowDrop(event)"></div>
        </div>
      </div>
      <input type="submit" value="ACEPTAR">
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
      const TABLA = document.getElementById("tablas");
      const TABLAS_SELECT = document.getElementById("tablas-seleccionadas");
      const CAMPOS = document.getElementById("campos");
      const CAMPO_OPCION = document.getElementById("campo-opcion");
      let datos_tc;
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
        datos_tc = JSON.parse(r["value"]);
        // console.log(datos_tc);
        let tabla_contenido = ``;
        for (tn in datos_tc) {
          tabla_contenido += `<option value="${tn}">${tn}</option>`;
        }
        TABLA.innerHTML = tabla_contenido;
      }).catch((e) => {
        console.log(e);
      });
      TABLA.addEventListener("change", () => {
        TABLAS_SELECT.innerHTML += `<div table="${TABLA.value}">${TABLA.value}</div>`;
        for (c of datos_tc[TABLA.value]) {
          CAMPOS.innerHTML += `<div draggable="true" ondragstart="drag(event)" cp-agrp="" class="cp-agrp" table="${TABLA.value}" col="${c}">${TABLA.value}.${c}</div>`
        }
      });
      function allowDrop(event) {
        event.preventDefault();
      }
      let current_co;
      function drag(event) {
        // event.dataTransfer.setData("campo", event.target.outerHTML);
        current_co = event.target;
        CAMPO_OPCION.style.padding = `0 0 ${(current_co.offsetHeight + "px")} 0`;
        CAMPO_OPCION.style.backgroundColor = "rgba(0, 0, 0, 0.5)";
        current_co.style.backgroundColor = "var(--green-color)";
      }
      function drop(event) {
        event.preventDefault();
        if (current_co.hasAttribute("cp-agrp") != event.target.hasAttribute("cp-agrp")) {
          // current_co.removeAttribute("draggable");
          current_co.innerHTML += `<select name="opcion" class="opcion" id="opcion">
                                    <option value="SUM">SUM</option>
                                    <option value="COUNT">COUNT</option>
                                    <option value="AVG">AVG</option>
                                  </select>`;
          event.target.innerHTML += current_co.outerHTML;
          current_co.remove();
        }
        CAMPO_OPCION.style.padding = "0 0 0 0";
        CAMPO_OPCION.style.backgroundColor = "transparent";
        current_co.style.backgroundColor = "var(--sky-blue-color)";
      }
      FORM.addEventListener("submit", function(event) {
        event.preventDefault();
        let datos = {};
        let tls = TABLAS_SELECT.querySelectorAll("div[table]");
        tls.forEach((e, i, a) => {
          datos[e.getAttribute("table")] = {};
        });
        let agrupacion = CAMPO_OPCION.querySelectorAll("div");
        agrupacion.forEach((e, i, a) => {
          let opt = e.querySelector("select");
          datos[e.getAttribute("table")][e.getAttribute("col")] = opt.value;
        });
        // console.log(datos);
        const REQUEST = new XMLHttpRequest();
        REQUEST.open("POST", URL + (FORM.getAttribute("action")).slice(1));
        REQUEST.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
        REQUEST.addEventListener("load", function(e) {
          if (REQUEST.status === 200) {
            console.log(JSON.parse(REQUEST.responseText));
            RESULTADO.innerHTML = `<embed src="./reporte_pdf.pdf" class="pdf-viewer" id="pdf-viewer" type="application/pdf" width="100%" height="720px"/>`;
          }
          else {
            console.log("Error en la solicitud");
          }
        });
        let d = "consulta=custom&datos=" + encodeURIComponent(JSON.stringify(datos));
        // console.log(d);
        REQUEST.send(d);
      });
    </script>
  </body>
</html>