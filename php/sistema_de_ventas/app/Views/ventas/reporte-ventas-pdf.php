<?php
  namespace App\ThirdParty;
  use FPDF;
  $pdf = new FPDF("P","mm","A4");
  $pdf->AddPage();
  $pdf->SetFont("Arial","B", 12);
  $pdf->Cell(190, 5, "Reporte de Ventas", 0, 1, "C");
  // Encabezados de la tabla
  $pdf->Cell(10, 6, "ID", 1, 0, "C");
  $pdf->Cell(55, 6, "Nombres y apellidos", 1, 0, "C");
  $pdf->Cell(50, 6, "Fecha de la venta", 1, 0, "C");
  // Ponemos salto de línea para que no se pongan en serie con lo que se inserte debajo
  $pdf->Cell(50, 6, "Fecha de registro", 1, 0, "C");
  $pdf->Cell(25, 6, "Venta total", 1, 1, "C");
  $pdf->SetFont("Arial","", 12);
 // $fila -> Nos permitirá obtener los datos fila por fila mediante el while
  // fetch_assoc() -> Asocia las filas para poder usarlos asi:
  // $fila['id'];
  foreach ($datos as $fila) {
    $pdf->Cell(10, 6, $fila['id_venta'], 1, 0, "C");
    $pdf->Cell(55, 6, $fila['nombres']." ".$fila["apellidos"], 1, 0, "C");
    $pdf->Cell(50, 6, $fila['fecha_venta'], 1, 0, "C");
    $pdf->Cell(50, 6, $fila['fecha_registro_venta'], 1, 0, "C");
    $pdf->Cell(25, 6, $fila['venta_total'], 1, 1, "C");
  }
  $pdf->Output("I", "Reporte_de_ventas.pdf", true);
?>