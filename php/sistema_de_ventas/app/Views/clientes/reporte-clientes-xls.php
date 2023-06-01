<?php
  use Composer\vendor;
  use PhpOffice\PhpSpreadsheet\Spreadsheet;
  use PhpOffice\PhpSpreadsheet\IOFactory;
  $excel= new Spreadsheet();
  $hojaActiva = $excel->getActiveSheet();
  $hojaActiva->setTitle("Reporte de clientes");
  //Medidas de las Celdas
  $hojaActiva->getColumnDimension('A')->setWidth(10);
  $hojaActiva->getColumnDimension('B')->setWidth(30);
  $hojaActiva->getColumnDimension('C')->setWidth(30);
  $hojaActiva->getColumnDimension('D')->setWidth(30);
  //Encabezado
  $hojaActiva->setCellValue('A1', 'ID');
  $hojaActiva->setCellValue('B1', 'Nombres');
  $hojaActiva->setCellValue('C1', 'Apellidos');
  $hojaActiva->setCellValue('D1', 'Dirección');
  $fila = 2;
  foreach ($clientes as $cliente) {
    $hojaActiva->setCellValue('A'.$fila, $cliente['id_cliente']);
    $hojaActiva->setCellValue('B'.$fila, $cliente['nombres']);
    $hojaActiva->setCellValue('C'.$fila, $cliente['apellidos']);
    $hojaActiva->setCellValue('D'.$fila, $cliente['direccion']);
    $fila++;
  }
  header('Content-Type: application/vnd.openxmlformats-officedocument.spreadsheetml.sheet');
  header('Content-Disposition: attachment;filename="Reporte_de_clientes.xlsx"');
  header('Cache-Control: max-age=5');
  $writer = IOFactory::createWriter($excel, 'Xlsx');
  $writer->save('php://output');
  exit;
?>