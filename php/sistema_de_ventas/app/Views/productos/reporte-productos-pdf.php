<?php
  namespace App\ThirdParty;
  use FPDF;
  $pdf = new FPDF("P","mm","A4");
  $pdf->AddPage();
  $pdf->SetFont("Arial","B", 12);
  $pdf->Cell(190, 5, "Reporte de Productos", 0, 1, "C");
  // Encabezados de la tabla
  $pdf->Cell(10, 6, "ID", 1, 0, "C");
  $pdf->Cell(90, 6, "Producto", 1, 0, "C");
  $pdf->Cell(90, 6, "Precio", 1, 1, "C");
  // Ponemos salto de línea para que no se pongan en serie con lo que se inserte debajo
  $pdf->SetFont("Arial","", 12);
 // $fila -> Nos permitirá obtener los datos fila por fila mediante el while
  // fetch_assoc() -> Asocia las filas para poder usarlos asi:
  // $fila['id'];
  foreach ($datos as $fila) {
    $pdf->Cell(10, 6, $fila['id_producto'], 1, 0, "C");
    $pdf->Cell(90, 6, $fila['nombre'], 1, 0, "C");
    $pdf->Cell(90, 6, $fila['precio'], 1, 1, "C");
  }
  $pdf->Output("I", "Reporte_de_productos.pdf", true);
?>