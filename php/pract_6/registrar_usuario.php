<?php
require_once "./conexion.php";
$user = $_POST["usuario"];
$pass = $_POST["password"];
$query = $connection->prepare('INSERT INTO usuario (usuario, password) VALUES (:user, :password)');
$query->bindParam(":user", $user);
$query->bindParam(":password", $pass);
$status = $query->execute();
if ($status) {
  header("Location: ./estado_ok.php");
}
else {
  header("Location: ./estado_mal.php");
}

?>