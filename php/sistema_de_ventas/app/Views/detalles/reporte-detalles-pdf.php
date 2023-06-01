<?php
  namespace App\ThirdParty;
  use FPDF;
  $pdf = new FPDF("P","mm","A4");
  $pdf->AddPage('L', 'A4');
  $pdf->SetFont("Arial","B", 10);
  $pdf->Cell(277.5, 5, "Detalles de las ventas", 0, 1, "C");
  // Encabezados de la tabla
  $pdf->Cell(20, 6, "ID", 1, 0, "C");
  $pdf->Cell(20, 6, "ID venta", 1, 0, "C");
  $pdf->Cell(30, 6, "Fecha de venta", 1, 0, "C");
  $pdf->Cell(45, 6, "Fecha de registro", 1, 0, "C");
  $pdf->Cell(62.5, 6, "Cliente", 1, 0, "C");
  $pdf->Cell(60, 6, "Producto", 1, 0, "C");
  $pdf->Cell(20, 6, "Precio", 1, 0, "C");
  // Ponemos salto de línea para que no se pongan en serie con lo que se inserte debajo
  $pdf->Cell(20 , 6, "Cantidad", 1, 1, "C");
  $pdf->SetFont("Arial","", 10);
 // $fila -> Nos permitirá obtener los datos fila por fila mediante el while
  // fetch_assoc() -> Asocia las filas para poder usarlos asi:
  // $fila['id'];
  foreach ($datos as $fila) {
    $pdf->Cell(20, 6, $fila['id_detalle'], 1, 0, "C");
    $pdf->Cell(20, 6, $fila['id_venta'], 1, 0, "C");
    $pdf->Cell(30, 6, $fila['fecha_venta'], 1, 0, "C");
    $pdf->Cell(45, 6, $fila['fecha_registro_venta'], 1, 0, "C");
    $pdf->Cell(62.5, 6, $fila['cliente'], 1, 0, "C");
    $pdf->Cell(60, 6, $fila['producto'], 1, 0, "C");
    $pdf->Cell(20, 6, $fila['precio'], 1, 0, "C");
    $pdf->Cell(20, 6, $fila['cantidad'], 1, 1, "C");
  }
  $pdf->Output("I", "Detalles_de_las_ventas.pdf", true);
?>