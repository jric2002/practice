<?php
  require "./fpdf/fpdf.php";
  $pdf = new fpdf("p","mm","letter");
  $pdf -> AddPage();
  $pdf -> SetFont("Arial","B", 12);
  $pdf -> Cell(100, 5, "Mi reporte en PDF", 1, 0, "C");
  $pdf -> Output();
?>