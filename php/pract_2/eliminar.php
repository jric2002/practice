<?php if (!isset($_GET['id']))
{
    exit();
}
$codigo = $_GET['id'];
include 'conexion.php';
$sentencia = $bd->prepare("DELETE FROM alumno WHERE id_alumno = ?;");
$resultado = $sentencia->execute([$codigo]);
if ($resultado === true)
{
    header('Location: listado.php');
}
else
{
    echo "Error";
} ?>
