<?php
$name = $_POST["name"];
$age = $_POST["age"];
$fi = fopen("datos.txt", "a") or die("problemas al crear el archivo");
fwrite($fi, "Nombre: ".$name);
fwrite($fi, "\nEdad: ".$age."\n");
fclose($fi);
echo "Datos guardados";
$fi = fopen("datos.txt", "r") or die("problemas al abrir el archivo");
while (!feof($fi)) {
    $get_file = fgets($fi);
    $line = nl2br($get_file);
    echo $line;
}
?>