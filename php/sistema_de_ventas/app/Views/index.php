<div class="container-flex p-3">
  <div class="row d-flex flex-wrap justify-content-center align-items-center p-2">
    <div class="card col-md-4 m-3 border-0 border-start border-primary border-5 rounded shadow">
      <div class="card-body d-flex justify-content-between align-items-center">
        <div>
          <p class="card-title text-primary text-">TOTAL DE CLIENTES</p>
          <h1 class="card-text"><?php echo $datos[0]["cantidad_clientes"] ?></h1>
        </div>
        <div>
          <i class="fas fa-user text-secondary fs-5"></i>
        </div>
      </div>
    </div>
    <div class="card col-md-4 m-3 border-0 border-start border-success border-5 rounded shadow">
      <div class="card-body d-flex justify-content-between align-items-center">
        <div>
          <p class="card-title text-success">TOTAL DE VENTAS</p>
          <h1 class="card-text"><?php echo $datos[1]["cantidad_ventas"] ?></h1>
        </div>
        <div>
          <i class="fas fa-dollar-sign text-secondary fs-5"></i>
        </div>
      </div>
    </div>
    <div class="card col-md-4 m-3 border-0 border-start border-info border-5 rounded shadow">
      <div class="card-body d-flex justify-content-between align-items-center">
        <div>
          <p class="card-title text-success">TOTAL DE PRODUCTOS</p>
          <h1 class="card-text"><?php echo $datos[2]["cantidad_productos"] ?></h1>
        </div>
        <div>
          <i class="fas fa-store text-secondary fs-5"></i>
        </div>
      </div>
    </div>
  </div>
  <div class="row d-flex justify-content-around align-items-center">
    <div class="card shadow m-2" style="width: 400px;">
      <div class="card-body">
        <h5 class="card-title">Ventas por Dia</h5>
        <div class="card-text">
          <canvas id="ventas-por-dia"></canvas>
        </div>
      </div>
    </div>
    <div class="card shadow m-2" style="width: 400px;">
      <div class="card-body">
        <h5 class="card-title">Clientes por Ventas</h5>
        <div class="card-text">
          <canvas id="clientes-por-ventas"></canvas>
        </div>
      </div>
    </div>
  </div>
</div>