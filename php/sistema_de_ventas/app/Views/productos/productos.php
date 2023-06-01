<div class="container-fluid bg-light bg-opacity-75">
  <div class="d-flex justify-content-between align-content-center px-2 py-4">
    <h1>Lista de productos</h1>
    <!-- Button trigger modal -->
    <div class="btn-group d-flex justify-content-around align-content-center flex-wrap no-print">
      <button type="button" class="btn btn-success m-2 rounded-pill" data-bs-toggle="modal" data-bs-target="#crear">
      <i class="fas fa-plus-circle"></i>
        Agregar producto
      </button>
      <a href="/productos/reporte-productos-pdf">
        <button type="button" class="btn btn-outline-danger m-2 rounded-pill">
          <i class="fas fa-cloud-download-alt"></i>
          Descargar en PDF
        </button>
      </a>
      <a href="/productos/reporte-productos-xls">
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
  <!-- Modal para crear un nuevo producto -->
  <div class="modal fade" id="crear" data-bs-backdrop="static" data-bs-keyboard="false" tabindex="-1" aria-labelledby="staticBackdropLabel" aria-hidden="true">
    <form class="modal-dialog" enctype="multipart/form-data" action="/productos/crear" method="post">
      <div class="modal-content">
        <div class="modal-header">
          <h5 class="modal-title" id="staticBackdropLabel">Nuevo producto</h5>
          <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
        </div>
        <div class="modal-body">
          <div class="my-3">
            <label for="nombre">Nombre del producto:</label>
            <input type="text" class="form-control" name="nombre" id="nombre" required>
          </div>
          <div class="my-3">
            <label for="precio">Precio:</label>
            <input type="number" class="form-control" name="precio" id="precio" step="0.01" required>
          </div>
          <div class="my-3">
            <label for="imagen">Imagen:</label>
            <input type="file" class="form-control" name="imagen" id="imagen" required>
          </div>
        </div>
        <div class="modal-footer">
          <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Cerrar</button>
          <button type="submit" class="btn btn-primary">Agregar</button>
        </div>
      </div>
    </form>
  </div>
  <table class="table table-striped table-light cell-border hover" id="tabla-productos" style="text-align: center; vertical-align: middle;">
    <thead>
      <tr>
        <th scope="col">ID</th>
        <th scope="col">Producto</th>
        <th scope="col">Precio</th>
        <th scope="col">Imagen</th>
        <th scope="col">Actualizar</th>
        <th scope="col">Eliminar</th>
      </tr>
    </thead>
    <tbody>
      <?php
        foreach ($productos as $producto) {
          echo "<tr>";
          echo "<td>".$producto["id_producto"]."</td>";
          echo "<td id-producto=\"".$producto["id_producto"]."\">".$producto["nombre"]."</td>";
          echo "<td id-producto=\"".$producto["id_producto"]."\">".$producto["precio"]."</td>";
          echo "<td><img src=\"/images/".$producto["imagen"]."\" alt=\"imagen de producto\" width=\"100px\"/></td>";
          echo "<td><button type=\"button\" class=\"btn btn-warning rounded-pill\" id-p=\"".$producto["id_producto"]."\" id=\"actualizar-datos\"data-bs-toggle=\"modal\" data-bs-target=\"#actualizar\">Editar</button></td>";
          echo "<td><a href=\"/productos/eliminar/".$producto["id_producto"]."\"><button type=\"button\" class=\"btn btn-danger rounded-pill\">Eliminar</button</td>";
          echo "</tr>";
        }
      ?>
    </tbody>
  </table>
  <!-- Modal para actualizar datos de un producto -->
  <div class="modal fade" id="actualizar" data-bs-backdrop="static" data-bs-keyboard="false" tabindex="-1" aria-labelledby="staticBackdropLabel" aria-hidden="true">
    <form class="modal-dialog" enctype="multipart/form-data" action="/productos/actualizar/" method="post" id="form-actualizar-datos">
      <div class="modal-content">
        <div class="modal-header">
          <h5 class="modal-title" id="staticBackdropLabel">Actualizar datos</h5>
          <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
        </div>
        <div class="modal-body">
          <div class="my-3">
            <label for="nombre">Nombre del producto:</label>
            <input type="text" class="form-control" name="nombre" id="nombre">
          </div>
          <div class="my-3">
            <label for="precio">Precio:</label>
            <input type="text" class="form-control" name="precio" id="precio">
          </div>
          <div class="my-3">
            <label for="imagen">Imagen:</label>
            <input type="file" class="form-control" name="imagen" id="imagen">
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