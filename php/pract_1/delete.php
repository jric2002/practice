<?php
$filename = $_POST["archivo"];
unlink($filename);
echo "El archivo ".$filename." jas sido eliminado con exito";
?>