<!DOCTYPE html>
  <html lang="es">
  <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="./page.css">
    <link rel="stylesheet" href="./header.css">
    <link rel="stylesheet" href="./publicar.css">
    <link rel="stylesheet" href="./footer.css">
    <title>Sistema de Gestión de Anuncios - SGA</title>
  </head>
  <body>
<?php
include_once("./header.php");
?>
    <section>
      <div class="post">
        <svg xmlns="http://www.w3.org/2000/svg" class="icon icon-tabler icon-tabler-user" width="44" height="44" viewBox="0 0 24 24" stroke-width="1.5" stroke="#2c3e50" fill="none" stroke-linecap="round" stroke-linejoin="round">
          <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
          <circle cx="12" cy="7" r="4" />
          <path d="M6 21v-2a4 4 0 0 1 4 -4h4a4 4 0 0 1 4 4v2" />
        </svg>
        <input type="text" name="" id="" placeholder="¿Qué quieres publicar?">
        <svg xmlns="http://www.w3.org/2000/svg" class="icon icon-tabler icon-tabler-photo" width="44" height="44" viewBox="0 0 24 24" stroke-width="1.5" stroke="#2c3e50" fill="none" stroke-linecap="round" stroke-linejoin="round">
          <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
          <line x1="15" y1="8" x2="15.01" y2="8" />
          <rect x="4" y="4" width="16" height="16" rx="3" />
          <path d="M4 15l4 -4a3 5 0 0 1 3 0l5 5" />
          <path d="M14 14l1 -1a3 5 0 0 1 3 0l2 2" />
        </svg>
      </div>
      <div class="mis-publicaciones">
        <div class="mis-publicaciones-header">
          <h3>Mis publicaciones</h3>
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
        </div>
      </div>
    </section>
<?php
include_once("./footer.php");
?>