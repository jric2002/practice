<?php
require("conexion.php");
require("../response.php");
$query = "SELECT user, pass FROM datos";
$datos = $conexion->query($query);
function validar($datos) {
  while ($fila = $datos->fetch_assoc()) {
    if (($fila["user"] == $_POST["usuario"]) and ($fila["pass"] == $_POST["password"])) {
      return TRUE;
    }
  }
  return FALSE;
}
$result = (validar($datos) == TRUE) ? "Usted SI esta registrado" : "Usted NO esta registrado";
response("Guía 3 - Ejercicio 1", "<strong>{$result}</strong>")
?>