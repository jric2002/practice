<?php
require_once("./fpdf/fpdf.php");
const HOSTNAME = "localhost";
const USERNAME = "root";
const PASSWORD = "admin";
const DATABASE_NAME = "empresa";
$connection = new mysqli(HOSTNAME, USERNAME, PASSWORD, DATABASE_NAME);
$r = NULL;
$estado = NULL;
if (isset($_POST["min"]) && isset($_POST["max"])) {
  $min = intval($_POST["min"]);
  $max = intval($_POST["max"]);
  $query = $connection->prepare("SELECT nombre, apellido FROM empleado WHERE salario BETWEEN ? AND ?");
  $query->bind_param("ii", $min, $max);
  if ($query->execute()) {
    $r = $query->get_result();
    $fields = $r->fetch_fields();
    $r = $r->fetch_all(MYSQLI_ASSOC);
    $estado = TRUE;
    // Genera el Reporte en PDF
    $pdf = new FPDF();
    $ancho_celda = 40;
    $alto_celda = 10;
    $pdf->AddPage();
    // Título del documento
    $pdf->SetFont('Arial','B',20);
    $pdf->Cell(0,10,'Reporte de la Consulta',0,1,'C');
    $pdf->Ln(10);
    // Encabezado de la tabla
    $pdf->SetFont('Arial','B',16);
    $pdf->Cell($ancho_celda, $alto_celda,'Nombre',1,0,'C');
    $pdf->Cell($ancho_celda, $alto_celda,'Apellido',1,0,'C');
    $pdf->Ln();
    // Datos de la tabla
    $pdf->SetFont('Arial','',14);
    foreach($r as $row){
      foreach($row as $k => $v) {
        $pdf->Cell($ancho_celda, $alto_celda, $v,1,0,'C');
      }
      $pdf->Ln();
    }
    $pdf->Output();
  }
}
?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Generador de Reporte</title>
    <style>
      * {
        font-family: sans-serif;
      }
      h1 {
        text-align: center;
      }
      input {
        font-size: 1rem;
        padding
      }
      table {
        border-collapse: collapse;
      }
      th, td {
        border: 1px solid black;
        padding: 0.5rem;
      }
      section.resultado {
        padding: 2rem 1rem;
      }
      div.parametros {
        display: flex;
        justify-content: flex-start;
        align-items: center;
      }
    </style>
  </head>
  <body>
    <form action="<?php echo $_SERVER["PHP_SELF"]?>" method="post">
      <h1>GENERADOR DE REPORTE</h1>
      <label for="min">Mínimo</label>
      <input type="text" name="min" id="min">
      <label for="max">Máximo</label>
      <input type="text" name="max" id="max">
      <input type="submit" value="Buscar">
    </form>
    <section class="resultado">
      <div class="parametros">
      <?php if ($estado):?>
        <h3>Mínimo: <?php echo $min;?></h3>
      <?php endif;?>&nbsp;&nbsp;&nbsp;&nbsp;
      <?php if ($estado):?>
        <h3>Máximo: <?php echo $max;?></h3>
      </div>
      <?php endif;?>
      </div>
      <table>
        <?php if ($estado):?>
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
        <?php endif;?>
      </table>
    </section>
  </body>
</html>