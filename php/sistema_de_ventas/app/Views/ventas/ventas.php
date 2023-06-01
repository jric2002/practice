<div class="container-fluid bg-light bg-opacity-75">
  <div class="d-flex flex-wrap justify-content-between align-content-center px-2 py-4">
    <h1 class="print">Lista de ventas</h1>
    <!-- Button trigger modal -->
    <div class="btn-group d-flex justify-content-around align-content-center flex-wrap no-print">
      <button type="button" class="btn btn-success m-2 rounded-pill" data-bs-toggle="modal" data-bs-target="#crear" id="registrar-venta">
        <i class="fas fa-plus-circle"></i>
        Registar venta
      </button>
      <a href="/ventas/reporte-ventas-pdf">
        <button type="button" class="btn btn-outline-danger m-2 rounded-pill">
          <i class="fas fa-cloud-download-alt"></i>
          Descargar en PDF
        </button>
      </a>
      <a href="/ventas/reporte-ventas-xls">
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
  <!-- Modal para crear una nueva venta -->
  <div class="modal fade" id="crear" data-bs-backdrop="static" data-bs-keyboard="false" tabindex="-1" aria-labelledby="staticBackdropLabel" aria-hidden="true">
    <div class="modal-dialog d-flex">
      <div class="modal-content">
        <div class="modal-header">
          <h5 class="modal-title" id="staticBackdropLabel">Registrar Venta</h5>
          <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
        </div>
        <div class="modal-body">
          <div class="my-3">
            <label for="cliente">Cliente:</label>
            <select name="cliente" id="cliente">
            </select>
          </div>
          <div class="my-3">
            <label for="fecha-venta">Fecha de la venta:</label>
            <input type="date" name="fecha-venta" id="fecha-venta">
          </div>
          <div class="my-3">
            <div class="d-flex justify-content-between align-items-center">
              <span>Producto</span>
              <button type="button" class="btn btn-success m-2 rounded-pill" id="agregar-producto">
                <i class="fas fa-plus-circle"></i>
                Agregar producto
              </button>
            </div>
            <table class="table" id="productos" style="text-align: center; vertical-align: middle;">
              <thead>
                <tr>
                  <th>Nombre</th>
                  <th>Precio unitario (P.U)</th>
                  <th>Cantidad</th>
                  <th>P.U * Cantidad</th>
                  <th>Eliminar</th>
                </tr>
              </thead>
              <tbody>
                <tr class="total" id="total">
                  <th colspan="3">Total</th>
                  <th colspan="2">0</th>
                </tr>
              </tbody>
            </table>
          </div>
        </div>
        <div class="modal-footer">
          <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Cerrar</button>
          <button type="submit" class="btn btn-primary" id="enviar-datos">Agregar</button>
        </div>
      </div>
    </div>
  </div>
  <table class="table table-striped table-light cell-border hover" id="tabla-ventas" style="text-align: center; vertical-align: middle;">
    <thead>
      <tr>
        <th scope="col">ID</th>
        <th scope="col">Nombres y apellidos</th>
        <th scope="col">Fecha de la venta</th>
        <th scope="col">Fecha de registro</th>
        <th scope="col">Vental total</th>
        <th scope="col">Actualizar</th>
        <th scope="col">Eliminar</th>
      </tr>
    </thead>
    <tbody>
      <?php
        foreach ($datos as $fila) {
          echo "<tr>";
          echo "<td>".$fila["id_venta"]."</td>";
          echo "<td>".$fila["nombres"]." ".$fila["apellidos"]."</td>";
          echo "<td>".$fila["fecha_venta"]."</td>";
          echo "<td>".$fila["fecha_registro_venta"]."</td>";
          echo "<td>".$fila["venta_total"]."</td>";
          echo "<td><button type=\"button\" class=\"btn btn-warning rounded-pill\">Editar</button></td>";
          echo "<td><button type=\"button\" class=\"btn btn-danger rounded-pill\">Eliminar</button</td>";
          echo "</tr>";
        }
      ?>
    </tbody>
  </table>
</div>