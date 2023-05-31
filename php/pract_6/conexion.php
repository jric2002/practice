<?php
$host = "localhost";
$db_user = "root";
$db_password = "admin";
$db_name = "biblioteca";

$connection = new PDO(
  "mysql:host=localhost;dbname=biblioteca",
  $db_user,
  $db_password
);
?>