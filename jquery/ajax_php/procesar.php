<?php
  //conectamos a la base de datos
  $mysqli = new mysqli("localhost", "root", "admin", "ajaxbd");
  if ($mysqli->connect_errno) die($mysqli->connect_error);
  //Recibimos datos del formulario y lo guardamos en la base de datos
  $nombres = $_POST['nombres'];
  $apellidos = $_POST['apellidos'];
  $sql = "INSERT INTO personas(nombres,apellidos) VALUES('{$nombres}','{$apellidos}')";
  if(!$mysqli->query($sql))die($mysqli->error);
  die("Guardado con exito");
?>