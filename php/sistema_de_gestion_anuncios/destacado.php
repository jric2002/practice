<!DOCTYPE html>
  <html lang="es">
  <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="./page.css">
    <link rel="stylesheet" href="./header.css">
    <link rel="stylesheet" href="./destacado.css">
    <link rel="stylesheet" href="./footer.css">
    <title>Sistema de Gestión de Anuncios - SGA</title>
  </head>
  <body>
<?php
include_once("./header.php");
?>
    <section>
      <div class="recomendaciones">
        <h3>Recomendaciones</h3>
        <input type="search" name="" id="" placeholder="Buscar">
        <div class="filtrar">
          <p>Filtrar</p>
          <svg xmlns="http://www.w3.org/2000/svg" class="icon icon-tabler icon-tabler-sort-descending" width="44" height="44" viewBox="0 0 24 24" stroke-width="1.5" stroke="#2c3e50" fill="none" stroke-linecap="round" stroke-linejoin="round">
            <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
            <line x1="4" y1="6" x2="13" y2="6" />
            <line x1="4" y1="12" x2="11" y2="12" />
            <line x1="4" y1="18" x2="11" y2="18" />
            <polyline points="15 15 18 18 21 15" />
            <line x1="18" y1="6" x2="18" y2="18" />
          </svg>
        </div>
      </div>
      <hr>
      <div class="publicaciones">
        <div class="pub">
          <div class="datos">
            <h4 class="titulo">CC. Real Plaza Juliaca / Ejecutivo Atencion y ventas</h4>
            <p class="autor">Nexxo Servicios Comerciales</p>
            <p class="descripcion">Grupo Empresarial líder en el Sector de las Telecomunicaciones, se encuentra en la ... ver más</p>
            <p class="ubicacion">Puno, Perú</p>
            <p class="tiempo">Hace 1 minuto</p>
          </div>
          <img src="./img/imagen-pub1.png" alt="">
        </div>
        <div class="pub">
          <div class="datos">
            <h4 class="titulo">Delivery Motorizado PedidosYa</h4>
            <p class="autor">Nexxo Servicios Comerciales</p>
            <p class="descripcion">PedidosYa, la empresa de tecnología líder en delivery con presencia en más de 15 países en la región ... ver más</p>
            <p class="ubicacion">Juliaca, Perú</p>
            <p class="tiempo">Hace 1 hora</p>
          </div>
          <img src="./img/imagen-pub2.jpg" alt="">
        </div>
        <div class="pub">
          <div class="datos">
            <h4 class="titulo">VENDEDORES CAMPAÑA NAVIDEÑA - JULIACA</h4>
            <p class="autor">Nexxo Servicios Comerciales</p>
            <p class="descripcion">Grupo Empresarial líder en el Sector de las Telecomunicaciones, se encuentra en la ... ver más</p>
            <p class="ubicacion">Puno, Perú</p>
            <p class="tiempo">Hace 2 hora</p>
          </div>
          <img src="./img/imagen-pub3.jfif" alt="">
        </div>
      </div>
    </section>
<?php
include_once("./footer.php");
?>