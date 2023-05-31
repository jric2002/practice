<?php
define("HOST", "localhost");
define("DB_USER", "root");
define("DB_PASSWORD", "admin");
define("DB_NAME", "ejemplo_db");

$conexion = mysqli_connect(HOST, DB_USER, DB_PASSWORD, DB_NAME);
?>