<div class="container-fluid bg-light bg-opacity-75">
  <div class="d-flex flex-wrap justify-content-between align-content-center px-2 py-4">
    <h1 class="print">Lista de clientes</h1>
    <!-- Button trigger modal -->
    <div class="btn-group d-flex justify-content-around align-content-center flex-wrap no-print">
      <button type="button" class="btn btn-success m-2 rounded-pill" data-bs-toggle="modal" data-bs-target="#crear">
        <i class="fas fa-plus-circle"></i>
        Agregar cliente
      </button>
      <a href="/clientes/reporte-clientes-pdf">
        <button type="button" class="btn btn-outline-danger m-2 rounded-pill">
          <i class="fas fa-cloud-download-alt"></i>
          Descargar en PDF
        </button>
      </a>
      <a href="/clientes/reporte-clientes-xls">
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
  <!-- Modal para crear un nuevo cliente -->
  <div class="modal fade" id="crear" data-bs-backdrop="static" data-bs-keyboard="false" tabindex="-1" aria-labelledby="staticBackdropLabel" aria-hidden="true">
    <form class="modal-dialog" action="/clientes/crear" method="post">
      <div class="modal-content">
        <div class="modal-header">
          <h5 class="modal-title" id="staticBackdropLabel">Nuevo Cliente</h5>
          <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
        </div>
        <div class="modal-body">
          <div class="my-3">
            <label for="nombres">Nombres:</label>
            <input type="text" class="form-control" name="nombres" id="nombres">
          </div>
          <div class="my-3">
            <label for="apellidos">Apellidos:</label>
            <input type="text" class="form-control" name="apellidos" id="apellidos">
          </div>
          <div class="my-3">
            <label for="direccion">Dirección:</label>
            <input type="text" class="form-control" name="direccion" id="direccion">
          </div>
        </div>
        <div class="modal-footer">
          <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Cerrar</button>
          <button type="submit" class="btn btn-primary">Agregar</button>
        </div>
      </div>
    </form>
  </div>
  <table class="table table-light table-striped cell-border hover print" id="tabla-clientes" style="text-align: center; vertical-align: middle;">
    <thead>
      <tr>
        <th scope="col">ID</th>
        <th scope="col">Nombres</th>
        <th scope="col">Apellidos</th>
        <th scope="col">Dirección</th>
        <th scope="col">Actualizar</th>
        <th scope="col">Eliminar</th>
      </tr>
    </thead>
    <tbody>
      <?php
        foreach ($clientes as $cliente) {
          echo "<tr>";
          echo "<td>".$cliente["id_cliente"]."</td>";
          echo "<td id-cliente=\"".$cliente["id_cliente"]."\">".$cliente["nombres"]."</td>";
          echo "<td id-cliente=\"".$cliente["id_cliente"]."\">".$cliente["apellidos"]."</td>";
          echo "<td id-cliente=\"".$cliente["id_cliente"]."\">".$cliente["direccion"]."</td>";
          echo "<td><button type=\"button\" class=\"btn btn-warning rounded-pill\" id-c=\"".$cliente["id_cliente"]."\" id=\"actualizar-datos\" data-bs-toggle=\"modal\" data-bs-target=\"#actualizar\">Editar</button></td>";
          echo "<td><a href=\"/clientes/eliminar/".$cliente["id_cliente"]."\"><button type=\"button\" class=\"btn btn-danger rounded-pill\">Eliminar</button</td>";
          echo "</tr>";
        }
      ?>
    </tbody>
  </table>
  <!-- Modal para actualizar datos de un cliente -->
  <div class="modal fade" id="actualizar" data-bs-backdrop="static" data-bs-keyboard="false" tabindex="-1" aria-labelledby="staticBackdropLabel" aria-hidden="true">
    <form class="modal-dialog" action="/clientes/actualizar/" method="post" id="form-actualizar-datos">
      <div class="modal-content">
        <div class="modal-header">
          <h5 class="modal-title" id="staticBackdropLabel">Actualizar datos</h5>
          <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
        </div>
        <div class="modal-body">
          <div class="my-3">
            <label for="nombres">Nombres:</label>
            <input type="text" class="form-control" name="nombres" id="nombres">
          </div>
          <div class="my-3">
            <label for="apellidos">Apellidos:</label>
            <input type="text" class="form-control" name="apellidos" id="apellidos">
          </div>
          <div class="my-3">
            <label for="direccion">Dirección:</label>
            <input type="text" class="form-control" name="direccion" id="direccion">
          </div>
        </div>
        <div class="modal-footer">
          <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Cerrar</button>
          <button type="submit" class="btn btn-primary">Actualizar</button>
        </div>
      </div>
    </form>
  </div>
</div>