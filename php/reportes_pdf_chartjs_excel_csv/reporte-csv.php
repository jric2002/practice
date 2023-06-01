<?php
  require './vendor/autoload.php';
  use PhpOffice\PhpSpreadsheet\Spreadsheet;
  use \PhpOffice\PhpSpreadsheet\IOFactory;
  $spreadsheet= new Spreadsheet();
  $spreadsheet -> getProperties()->setCreator("Jefer Apaza") -> setTitle("Reporte en CSV");
  $hojaActiva = $spreadsheet -> getActiveSheet();
  $hojaActiva -> setCellValue('A1', 'Codigos de Programación');
  $hojaActiva -> setCellValue('B2', 15.264);
  $hojaActiva -> setCellValue('C1', 'Hernan Apaza')->setCellValue('D1', 'cdp');
  header('Content-Type: application/vnd.openxmlformats-officedocument.spreadsheetml.sheet');
  header('Content-Disposition: attachment;filename="Reporte en CSV.Csv"');
  header('Cache-Control: max-age=0');
  $writer = IOFactory::createWriter($spreadsheet, 'Csv');
  $writer->save('php://output');
?>