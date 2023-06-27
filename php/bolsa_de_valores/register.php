<?php
if (isset($_COOKIE["user"])) {
  header("Location: ./home.php");
  exit();
}
if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $name = trim($_POST["name"]);
  $username = trim($_POST["username"]);
  $email = trim($_POST["email"]);
  $password = $_POST["password"];
  $hash = password_hash($password, PASSWORD_DEFAULT);
  $error = FALSE;
  $error_msg = "";
  if (strlen($name) < 2 && !$error) {
    $error = TRUE;
    $error_msg = "El nombre debe tener al menos 3 caracteres";
  }
  if ((strlen($username) < 2 or strpos($username, " ") != FALSE) && !$error) {
    $error = TRUE;
    $error_msg = "El nombre de usuario debe tener al menos 3 caracters";
  }
  if (!filter_var($email, FILTER_VALIDATE_EMAIL) && !$error) {
    $error = TRUE;
    $error_msg = "El correo electrónico no es valido";
  }
  if (strlen($password) < 2 && !$error) {
    $error = TRUE;
    $error_msg = "La contraseña debe tener al menos 3 caracteres";
  }
  // Buscar en la base de datos si el usuario o email ya esta registrado
  include_once("./connection.php");
  if ($error == FALSE) {
    $query = "SELECT EXISTS(SELECT 1 FROM users WHERE username = '".$username."') AS 'exists'";
    $r = $connection->query($query);
    $r = $r->fetch_all(MYSQLI_ASSOC);
    if (($r[0])["exists"] == "1") {
      $error = TRUE;
      $error_msg = "El nombre de usuario <strong>".$username."</strong> ya existe, eligue otro nombre de usuario";
    }
    $query = "SELECT EXISTS(SELECT 1 FROM users WHERE email = '".$email."') AS 'exists'";
    $r = $connection->query($query);
    $r = $r->fetch_all(MYSQLI_ASSOC);
    if (($r[0])["exists"] == "1" && !$error) {
      $error = TRUE;
      $error_msg = "El correo <strong>".$email."</strong> ya esta registrado en otra cuenta, ingresa otro correo electrónico";
    }
  }
  if ($error == FALSE) {
    $query = $connection->prepare("INSERT INTO users (name, gender, email, username, password) VALUES (?, NULL, ?, ?, ?)");
    $query->bind_param("ssss", $name, $email, $username, $hash);
    $r = $query->execute();
    // if ($query->affected_rows > 0) {
    if ($r) {
      header("Location: ./index.php");
      exit();
    }
    else {
      $sv_error = "ALGO SALIO MAL, VUELVE A INTENTARLO MAS TARDE";
    }
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
    <link rel="stylesheet" type="text/css" href="./css/register.css"/>
  </head>
  <body>
    <header class="header">
      <h1>Bolsa Virtual</h1>
    </header>
    <section class="login">
      <form action="./<?php echo ".".$_SERVER["PHP_SELF"];?>" method="post">
        <h1>Regístrate gratis</h1>
        <?php if (isset($error)):?>
          <p style="color: var(--red-color);"><?php echo $error_msg; ?></p>
        <?php endif;?>
        <?php if (isset($sv_error)):?>
          <p style="color: var(--red-color);"><?php echo $sv_error; ?></p>
        <?php endif;?>
        <div>
          <label for="name">Nombre</label><br/>
          <input type="text" name="name" id="name" placeholder="Nombre" required/>
        </div>
        <div>
          <label for="username">Nombre de usuario</label><br/>
          <input type="text" name="username" id="username" placeholder="Nombre de usuario" required/>
        </div>
        <div>
          <label for="email">Correo Electrónico</label><br/>
          <input type="email" name="email" id="email" placeholder="Correo Electrónico" required/>
        </div>
        <div>
          <label for="password">Contraseña</label><br/>
          <input type="password" name="password" id="password" placeholder="Contraseña" required/>
        </div>
        <div class="note">
          <p>Los campos <strong>Nombre</strong>, <strong>Nombre de usuario</strong> y <strong>Contraseña</strong> deben ser de al menos 3 caracteres.</p>
        </div>
        <div>
          <input type="submit" value="Iniciar Sesión"/><br/>
        </div>
        <a href="./index.php">Iniciar sesión</a>
      </form>
    </section>
  </body>
</html>