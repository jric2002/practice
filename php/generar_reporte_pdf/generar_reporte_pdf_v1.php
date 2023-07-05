<?php
require_once("./fpdf/fpdf.php");
const HOSTNAME = "localhost";
const USERNAME = "root";
const PASSWORD = "admin";
const DATABASE_NAME = "empresa";
$connection = new mysqli(HOSTNAME, USERNAME, PASSWORD, DATABASE_NAME);
$estado = NULL;
$fields = NULL;
$r = NULL;
$mensaje = NULL;
if (isset($_POST["consulta"])) {
  switch ($_POST["consulta"]) {
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
          $estado = TRUE;
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
          $pdf->Output();
        }
      }
      else {
        $mensaje = "Salario mínimo y máximo no esta definido";
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
          $estado = TRUE;
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
          $pdf->Output();
        }
      }
      else {
        $mensaje = "Fecha de nacimiento mínimo y máximo no esta definido";
      }
      break;
    default:
      $mensaje = "Esa consulta no es válida";
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
      select.consulta {
        font-size: 1rem;
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
        background-color: var(--green-color);
        transition: background-color 0.25s linear;
      }
      form input[type="submit"]:hover {
        color: var(--black-color);
        background-color: var(--white-color);
      }
      section.resultado table {
        border-collapse: collapse;
      }
      section.resultado table thead tr th, section.resultado table tbody tr td {
        border: 1px solid black;
        padding: 0.5rem;
      }
      section.resultado {
        padding: 2rem 1rem;
      }
      section.resultado div.parametros {
        display: flex;
        justify-content: flex-start;
        align-items: center;
      }
    </style>
  </head>
  <body>
    <form action="<?php echo $_SERVER["PHP_SELF"]?>" method="post" class="form" id="form">
      <h1>GENERADOR DE REPORTE</h1>
      <label for="consulta">Consulta:</label>
      <select name="consulta" class="consulta" id="consulta">
        <option value="salario" selected>Salario</option>
        <option value="fn">Fecha de nacimiento</option>
      </select>
      <div class="datos-entrada" id="datos-entrada"></div>
    </form>
    <section class="resultado">
      <div class="parametros">
      <?php if (isset($_POST["consulta"])):?>
        <?php if ($_POST["consulta"] == "salario"):?>
          <h3>Mínimo: <?php echo $min;?></h3>&nbsp;&nbsp;&nbsp;&nbsp;
          <h3>Máximo: <?php echo $max;?></h3>
        <?php else:?>
          <h3>Mínimo: <?php echo $fmin;?></h3>&nbsp;&nbsp;&nbsp;&nbsp;
          <h3>Máximo: <?php echo $fmax;?></h3>
        <?php endif;?>
      <?php endif;?>
      </div>
      <?php if ($estado):?>
      <table>
        <thead>
          <tr>
          <?php foreach($fields as $f):?>
            <th><?php print_r($f->name);?></th>
          <?php endforeach;?>
          </tr>
        </thead>
        <tbody>
        <?php foreach($r as $row):?>
          <tr>
            <?php foreach($row as $k => $v):?>
              <td><?php echo $v;?></td>
            <?php endforeach;?>
          </tr>
        <?php endforeach;?>
        </tbody>
      </table>
      <?php endif;?>
    </section>
    <script type="text/javascript">
      const DATOS_ENTRADA = document.getElementById("datos-entrada");
      const CONSULTA = document.getElementById("consulta");
      var consultas = {
        salario: `
          <label for="min">Mínimo:</label>
          <input type="text" name="min" id="min">
          <label for="max">Máximo:</label>
          <input type="text" name="max" id="max">
          <label for="cifras">Cifras:</label>
          <input type="number" name="cifras" class="cifras" id="cifras" min="0" value="0">
          <input type="submit" value="Buscar" id="buscar">`,
        fn: `
          <label for="fmin">Mínimo:</label>
          <input type="date" name="fmin" id="fmin" value="1950-01-01">
          <label for="fmax">Máximo:</label>
          <input type="date" name="fmax" id="fmax" value="1960-01-01">
          <input type="submit" value="Buscar" id="buscar">`
      }
      DATOS_ENTRADA.innerHTML = consultas[CONSULTA.value];
      CONSULTA.addEventListener("change", function() {
        DATOS_ENTRADA.innerHTML = consultas[CONSULTA.value];
      });
    </script>
  </body>
</html>