<?php
  use Composer\vendor;
  use PhpOffice\PhpSpreadsheet\Spreadsheet;
  use PhpOffice\PhpSpreadsheet\IOFactory;
  $excel= new Spreadsheet();
  $hojaActiva = $excel->getActiveSheet();
  $hojaActiva->setTitle("Reporte de productos");
  //Medidas de las Celdas
  $hojaActiva->getColumnDimension('A')->setWidth(10);
  $hojaActiva->getColumnDimension('B')->setWidth(20);
  $hojaActiva->getColumnDimension('C')->setWidth(10);
  //Encabezado
  $hojaActiva->setCellValue('A1', 'ID');
  $hojaActiva->setCellValue('B1', 'Producto');
  $hojaActiva->setCellValue('C1', 'Precio');
  $fila = 2;
  foreach ($datos as $producto) {
    $hojaActiva->setCellValue('A'.$fila, $producto['id_producto']);
    $hojaActiva->setCellValue('B'.$fila, $producto['nombre']);
    $hojaActiva->setCellValue('C'.$fila, $producto['precio']);
    $fila++;
  }
  header('Content-Type: application/vnd.openxmlformats-officedocument.spreadsheetml.sheet');
  header('Content-Disposition: attachment;filename="Reporte_de_productos.xlsx"');
  header('Cache-Control: max-age=5');
  $writer = IOFactory::createWriter($excel, 'Xlsx');
  $writer->save('php://output');
  exit;
?>