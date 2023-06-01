<div class="container-fluid bg-light bg-opacity-75">
  <div class="d-flex flex-wrap justify-content-between align-content-center px-2 py-4">
    <h1 class="print">Lista de detalles</h1>
    <!-- Button trigger modal -->
    <div class="btn-group d-flex justify-content-around align-content-center flex-wrap no-print">
      <a href="/detalles/reporte-detalles-pdf">
        <button type="button" class="btn btn-outline-danger m-2 rounded-pill">
          <i class="fas fa-cloud-download-alt"></i>
          Descargar en PDF
        </button>
      </a>
      <a href="/detalles/reporte-detalles-xls">
        <button type="button" class="btn btn-outline-success m-2 rounded-pill">
          <i class="fas fa-cloud-download-alt"></i>
          Descargar en XLS
        </button>
      </a>
      <button type="button" class="btn btn-outline-primary m-2 rounded-pill" id="btn-print">
          <i class="fas fa-print"></i>
          Imprimir
      </button>
    </div>
  </div>
  <table class="table table-striped table-light cell-border hover print" id="tabla-detalles" style="text-align: center; vertical-align: middle;">
    <thead>
      <tr>
        <th scope="col">ID</th>
        <th scope="col">ID venta</th>
        <th scope="col">Fecha de venta</th>
        <th scope="col">Fecha de registro</th>
        <th scope="col">Cliente</th>
        <th scope="col">Producto</th>
        <th scope="col">Precio</th>
        <th scope="col">Cantidad</th>
      </tr>
    </thead>
    <tbody>
      <?php
        foreach ($detalles as $detalle) {
          echo "<tr>";
          echo "<td>".$detalle["id_detalle"]."</td>";
          echo "<td>".$detalle["id_venta"]."</td>";
          echo "<td>".$detalle["fecha_venta"]."</td>";
          echo "<td>".$detalle["fecha_registro_venta"]."</td>";
          echo "<td>".$detalle["cliente"]."</td>";
          echo "<td>".$detalle["producto"]."</td>";
          echo "<td>".$detalle["precio"]."</td>";
          echo "<td>".$detalle["cantidad"]."</td>";
          echo "</tr>";
        }
      ?>
    </tbody>
  </table>
</div>