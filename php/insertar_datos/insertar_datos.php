<?php
const HOSTNAME = "localhost";
const USERNAME = "root";
const PASSWORD = "admin";
const DATABASE_NAME = "empresa1";
const TABLE_NAME = "empleados2";
$connection = new mysqli(HOSTNAME, USERNAME, PASSWORD, DATABASE_NAME);
$connection->query("TRUNCATE TABLE ".TABLE_NAME);
for ($i = 1; $i <= 10; $i++) {
  $nombre = "nombre".$i;
  $apellido = "apellido".$i;
  $q = "INSERT INTO ".TABLE_NAME." (ci, nombre, apellido) VALUES (?, ?, ?)";
  $query = $connection->prepare($q);
  $query->bind_param("iss", $i, $nombre, $apellido);
  $query->execute();
}
echo "Se han registrado los datos en la tabla "
?>