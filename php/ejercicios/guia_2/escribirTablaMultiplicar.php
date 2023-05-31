<?php
/* GUIA 2 */
/* Ejercico 2 */
require("../response.php");
function escribirTablaMultiplicar($n): string {
  $r = "";
  for ($i = 1; $i <= 10; $i++) {
    $producto = $n * $i;
    $r .= "<strong>{$n} x {$i} = {$producto}</strong><br/>";
  }
  return $r;
}
response("Guía 2 - Ejerciio 2", escribirTablaMultiplicar((int)$_POST["numero-2"]));
?>