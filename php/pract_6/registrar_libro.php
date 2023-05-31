<?php
require_once "./conexion.php";
$title = $_POST["titulo"];
$des = $_POST["descripcion"];
$query = $connection->prepare('INSERT INTO libro (titulo, descripcion) VALUES (:title, :descripcion)');
$query->bindParam(":title", $title);
$query->bindParam(":descripcion", $des);
$status = $query->execute();
if ($status) {
  header("Location: ./estado_ok.php");
}
else {
  header("Location: ./estado_mal.php");
}

?>