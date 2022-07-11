<?php
session_start();
include_once 'conexion.php';
$usuario = $_POST['txtUsu'];
$contrasena = $_POST['txtPass'];
$sentencia = $bd->prepare('select * from t_usuario where nombre_usu = ? and password_usu = ?;');
$sentencia->execute([$usuario, $contrasena]);
$datos = $sentencia->fetch(PDO::FETCH_OBJ);
if ($datos === false)
{
    header('Location: login.php');
}
elseif ($sentencia->rowCount() == 1)
{
    $_SESSION['nombre'] = $datos->nombre_usu;
    header('Location: listado.php');
}
?>
