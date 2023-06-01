<?php
  namespace App\ThirdParty;
  use FPDF;
  $pdf = new FPDF("P","mm","A4");
  $pdf->AddPage();
  $pdf->SetFont("Arial","B", 12);
  $pdf->Cell(190, 5, "Reporte de Clientes", 0, 1, "C");
  // Encabezados de la tabla
  $pdf->Cell(10, 6, "ID", 1, 0, "C");
  $pdf->Cell(60, 6, "Nombres", 1, 0, "C");
  $pdf->Cell(60, 6, "Apellidos", 1, 0, "C");
  // Ponemos salto de línea para que no se pongan en serie con lo que se inserte debajo
  $pdf->Cell(60, 6, "Dirección", 1, 1, "C");
  $pdf->SetFont("Arial","", 12);
 // $fila -> Nos permitirá obtener los datos fila por fila mediante el while
  // fetch_assoc() -> Asocia las filas para poder usarlos asi:
  // $fila['id'];
  foreach ($clientes as $fila) {
    $pdf->Cell(10, 6, $fila['id_cliente'], 1, 0, "C");
    $pdf->Cell(60, 6, $fila['nombres'], 1, 0, "C");
    $pdf->Cell(60, 6, $fila['apellidos'], 1, 0, "C");
    $pdf->Cell(60, 6, $fila['direccion'], 1, 1, "C");
  }
  $pdf->Output("I", "Reporte_de_clientes.pdf", true);
?>