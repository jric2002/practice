<?php
$host = "localhost";
$nombrebd = "nota";
$usuario = "root";
$contrasena = "";
try {
    $bd = new PDO(
        "mysql:host={$host};
        dbname={$nombrebd}",
        $usuario,
        $contrasena,
        array(PDO::MYSQL_ATTR_INIT_COMMAND => "SET NAMES utf8")
    );
}
catch (Exception $error) {
    echo "Error de conexión {$error->getMessage()}";
}
?>