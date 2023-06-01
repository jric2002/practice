<?php
  $page = $page;
  function activateItem($page, $item) {
    if ($page == $item) {
      echo "active";
    }
  }
?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?php echo $head["title"] ?></title>
    <meta name="description" content="<?php echo $head["description"] ?>">
    <link rel="icon" type="image/jpeg" href="/images/logo.jpg">
    <!-- Font Awesome -->
    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.15.2/css/all.css" integrity="sha384-vSIIfh2YWi9wW0r9iZe7RJPrKwp6bG+s9QZMoITbCckVJqGCCRhc+ccxNcdpHuYu" crossorigin="anonymous">
    <!-- CSS -->
    <?php if (in_array($page, ["inicio", "clientes", "productos", "ventas", "detalles", "acerca_de"])): ?>
    <link rel="stylesheet" href="/css/background.css">
    <?php endif; ?>
    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <?php if (in_array($page, ["clientes", "productos", "ventas", "detalles"])): ?>
    <!-- DataTable - CSS -->
    <link rel="stylesheet" type="text/css" href="https://cdn.datatables.net/1.12.1/css/jquery.dataTables.css">
    <!-- CSS Files -->
    <link rel="stylesheet" type="text/css" href="/css/print.css">
    <?php endif; ?>
  </head>
  <body class="<?php if (in_array($page, ["inicio", "clientes", "productos", "ventas", "detalles", "acerca_de"])) {echo "background-image";} ?>">
    <nav class="navbar navbar-dark bg-dark bg-opacity-75 navbar-expand-md <?php if (in_array($page, ["clientes", "productos", "ventas", "detalles"])): echo "no-print"; endif; ?>">
      <div class="container-fluid">
        <a class="navbar-brand">
          <img src="/images/logo.jpg" class="rounded-circle" alt="Logo" width="45px">
          Sistema de ventas
        </a>
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavDropdown" aria-controls="navbarNavDropdown" aria-expanded="false" aria-label="Toggle navigation">
          <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse justify-content-end" id="navbarNavDropdown">
          <ul class="navbar-nav nav-pills">
            <li class="nav-item">
              <a class="nav-link <?php activateItem($page, "inicio"); ?>" aria-current="page" href="/">Inicio</a>
            </li>
            <li class="nav-item">
              <a class="nav-link <?php activateItem($page, "clientes"); ?>" href="/clientes">Clientes</a>
            </li>
            <li class="nav-item">
              <a class="nav-link <?php activateItem($page, "productos"); ?>" href="/productos">Produtos</a>
            </li>
            <li class="nav-item">
              <a class="nav-link <?php activateItem($page, "ventas"); ?>" href="/ventas">Ventas</a>
            </li>
            <li class="nav-item">
              <a class="nav-link <?php activateItem($page, "detalles"); ?>" href="/detalles">Detalles</a>
            </li>
            <li class="nav-item">
              <a class="nav-link <?php activateItem($page, "acerca_de"); ?>" href="/acerca_de">Acerca de</a>
            </li>
          </ul>
        </div>
      </div>
    </nav>