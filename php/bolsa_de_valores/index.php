<?php
if (isset($_COOKIE["user"])) {
  header("Location: ./home.php");
  exit();
}
include_once("./connection.php");
if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $query = $connection->prepare("SELECT EXISTS(SELECT 1 FROM users WHERE username = ? OR email = ?) AS 'exists'");
  $query->bind_param("ss", $_POST["user"], $_POST["user"]);
  $query->execute();
  $r = $query->get_result();
  $r = $r->fetch_all(MYSQLI_ASSOC);
  if (($r[0])["exists"] == "1") {
    $query = $connection->prepare("SELECT password FROM users WHERE username = ? OR email = ?");
    $query->bind_param("ss", $_POST["user"], $_POST["user"]);
    $query->execute();
    $r = $query->get_result();
    $r = $r->fetch_all(MYSQLI_ASSOC);
    $hash = ($r[0])["password"];
    if (password_verify($_POST["password"], $hash)) {
      setcookie("user", $_POST["user"], time() + 3600);
      header("Location: ./home.php");
      exit();
    }
    else {
      $invalid_credentials = TRUE;
    }
  }
  else {
    $invalid_credentials = TRUE;
  }
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
    <link rel="stylesheet" type="text/css" href="./css/login.css"/>
  </head>
  <body>
    <header class="header">
      <h1>Bolsa Virtual</h1>
    </header>
    <section class="login">
      <form action="<?php echo ".".$_SERVER["PHP_SELF"];?>" method="post">
        <h1>Inicia sesión</h1>
        <?php if (isset($invalid_credentials)):?>
          <p style="color: var(--red-color);"><?php echo "Usuario o contraseña invalido"; ?></p>
        <?php endif;?>
        <div>
          <label for="user">Correo Electrónico o nombre de usuario</label><br/>
          <input type="text" name="user" id="user" placeholder="Correo Electrónico o nombre de usuario" required/>
        </div>
        <div>
          <label for="password">Contraseña</label><br/>
          <input type="password" name="password" id="password" placeholder="Contraseña" required/>
        </div>
        <div>
          <input type="submit" value="Iniciar Sesión"/><br/>
        </div>
        <a href="./register.php">Crear cuenta</a>
      </form>
    </section>
  </body>
</html>