<?php
/* GUIA 2 */
/* Ejercico 3 */
require("../response.php");
function dibujarTriangulo($n): string {
  $triangulo = "";
  for ($i = 1; $i <= $n; $i++) {
    $ast = str_repeat("* ", $i);
    $triangulo .= "{$ast}<br/>";
  }
  return $triangulo;
}
response("Guía 2 - Ejerciio 3", dibujarTriangulo((int)$_POST["numero-4"]));
?>