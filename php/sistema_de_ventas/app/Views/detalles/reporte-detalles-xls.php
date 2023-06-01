<?php
  use Composer\vendor;
  use PhpOffice\PhpSpreadsheet\Spreadsheet;
  use PhpOffice\PhpSpreadsheet\IOFactory;
  $excel= new Spreadsheet();
  $hojaActiva = $excel->getActiveSheet();
  $hojaActiva->setTitle("Detalles de las ventas");
  //Medidas de las Celdas
  $hojaActiva->getColumnDimension('A')->setWidth(10);
  $hojaActiva->getColumnDimension('B')->setWidth(10);
  $hojaActiva->getColumnDimension('C')->setWidth(20);
  $hojaActiva->getColumnDimension('D')->setWidth(30);
  $hojaActiva->getColumnDimension('E')->setWidth(35);
  $hojaActiva->getColumnDimension('F')->setWidth(35);
  $hojaActiva->getColumnDimension('G')->setWidth(10);
  $hojaActiva->getColumnDimension('H')->setWidth(10);
  //Encabezado
  $hojaActiva->setCellValue('A1', 'ID');
  $hojaActiva->setCellValue('B1', 'ID venta');
  $hojaActiva->setCellValue('C1', 'Fecha de venta');
  $hojaActiva->setCellValue('D1', 'Fecha de registro');
  $hojaActiva->setCellValue('E1', 'Cliente');
  $hojaActiva->setCellValue('F1', 'Producto');
  $hojaActiva->setCellValue('G1', 'Precio');
  $hojaActiva->setCellValue('H1', 'Cantidad');
  $fila = 2;
  foreach ($datos as $detalle) {
    $hojaActiva->setCellValue('A'.$fila, $detalle['id_detalle']);
    $hojaActiva->setCellValue('B'.$fila, $detalle['id_venta']);
    $hojaActiva->setCellValue('C'.$fila, $detalle['fecha_venta']);
    $hojaActiva->setCellValue('D'.$fila, $detalle['fecha_registro_venta']);
    $hojaActiva->setCellValue('E'.$fila, $detalle['cliente']);
    $hojaActiva->setCellValue('F'.$fila, $detalle['producto']);
    $hojaActiva->setCellValue('G'.$fila, $detalle['precio']);
    $hojaActiva->setCellValue('H'.$fila, $detalle['cantidad']);
    $fila++;
  }
  header('Content-Type: application/vnd.openxmlformats-officedocument.spreadsheetml.sheet');
  header('Content-Disposition: attachment;filename="Detalles_de_las_ventas.xlsx"');
  header('Cache-Control: max-age=5');
  $writer = IOFactory::createWriter($excel, 'Xlsx');
  $writer->save('php://output');
  exit;
?>