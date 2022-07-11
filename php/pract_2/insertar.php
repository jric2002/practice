<?php if (!isset($_POST['oculto']))
{
    exit();
}
include 'conexion.php';
$paterno = $_POST['txtPaterno'];
$materno = $_POST['txtMaterno'];
$nombre = $_POST['txtNombre'];
$parcial = $_POST['txtParcial'];
$final = $_POST['txtFinal'];
$sentencia = $bd->prepare("INSERT INTO alumno(ap_paterno,ap_materno,nombre,ex_parcial,ex_final) VALUES (?,?,?,?,?);");
$resultado = $sentencia->execute([$paterno, $materno, $nombre, $parcial, $final]);
if ($resultado === true)
{ //echo "Insertado correctamente";
    header('Location: listado.php');
}
else{
    echo "Error";
}
?>