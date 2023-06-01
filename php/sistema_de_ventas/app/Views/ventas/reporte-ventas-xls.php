<?php
  use Composer\vendor;
  use PhpOffice\PhpSpreadsheet\Spreadsheet;
  use PhpOffice\PhpSpreadsheet\IOFactory;
  $excel= new Spreadsheet();
  $hojaActiva = $excel->getActiveSheet();
  $hojaActiva->setTitle("Reporte de Ventas");
  //Medidas de las Celdas
  $hojaActiva->getColumnDimension('A')->setWidth(10);
  $hojaActiva->getColumnDimension('B')->setWidth(35);
  $hojaActiva->getColumnDimension('C')->setWidth(35);
  $hojaActiva->getColumnDimension('D')->setWidth(35);
  $hojaActiva->getColumnDimension('E')->setWidth(10);
  //Encabezado
  $hojaActiva->setCellValue('A1', 'ID');
  $hojaActiva->setCellValue('B1', 'Nombres y apellidos');
  $hojaActiva->setCellValue('C1', 'Fecha de venta');
  $hojaActiva->setCellValue('D1', 'Fecha de registro');
  $hojaActiva->setCellValue('E1', 'Venta total');
  $fila = 2;
  foreach ($datos as $dato) {
    $hojaActiva->setCellValue('A'.$fila, $dato['id_venta']);
    $hojaActiva->setCellValue('B'.$fila, $dato['nombres']." ".$dato["apellidos"]);
    $hojaActiva->setCellValue('C'.$fila, $dato['fecha_venta']);
    $hojaActiva->setCellValue('D'.$fila, $dato['fecha_registro_venta']);
    $hojaActiva->setCellValue('E'.$fila, $dato['venta_total']);
    $fila++;
  }
  header('Content-Type: application/vnd.openxmlformats-officedocument.spreadsheetml.sheet');
  header('Content-Disposition: attachment;filename="Reporte_de_ventas.xlsx"');
  header('Cache-Control: max-age=5');
  $writer = IOFactory::createWriter($excel, 'Xlsx');
  $writer->save('php://output');
  exit;
?>