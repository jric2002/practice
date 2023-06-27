<?php
if (isset($_COOKIE["user"])) {
  if (isset($_GET["logout"])) {
    setcookie("user", "", time() - 3600);
    header("Location: ./index.php");
    exit();
  }
}
else {
  header("Location: ./index.php");
  exit();
}
?>
<!DOCTYPE html>
  <html lang="es">
  <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Bolsa Virtual</title>
    <meta name="author" content="Simulador de Bolsa de Valores"/>
    <meta name="author" content="Simulador de Bolsa de Valores es un mercado de compra y venta de acciones de una empresa."/>
    <meta name="keywords" content="Bolsa de valores, stock exchange, trading"/>
    <link rel="icon" sizes="32x32" type="image/png" href="https://open.spotifycdn.com/cdn/images/favicon32.b64ecc03.png"/>
    <link rel="icon" sizes="16x16" type="image/png" href="https://open.spotifycdn.com/cdn/images/favicon16.1c487bff.png"/>
    <link rel="icon" href="https://open.spotifycdn.com/cdn/images/favicon.0f31d2ea.ico"/>
    <!-- CSS -->
    <link rel="stylesheet" type="text/css" href="./css/colors.css"/>
    <link rel="stylesheet" type="text/css" href="./css/home.css"/>
    <script defer type="text/javascript" src="./js/home.js"></script>
  </head>
  <body>
    <header class="header">
      <h2>Bolsa Virtual</h2>
      <form action=".<?php echo $_SERVER["PHP_SELF"]?>" method="post">
        <input type="search" name="search" class="search" id="search" placeholder="Buscar"/>
        <input type="submit" value="submit"/>
      </form>
      <div>
        <h1 class="user"><?php echo $_COOKIE["user"];?></h1>
        <a href="<?php echo ".".$_SERVER["PHP_SELF"]."?logout";?>">Cerrar sesión</a>
      </div>
    </header>
    <section class="datos">
      <div class="empresa">
        <h1 class="nombre"></h1>
        <p class="precio_accion"></p>
        <p class="variacion"></p>
        <p class="tiempo"></p>
      </div>
    </section>
  </body>
</html>