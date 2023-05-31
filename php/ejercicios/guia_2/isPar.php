<?php
/* GUIA 2 */
/* Ejercicio 1 */
require("../response.php");
function is_par($number) {
  if (($number % 2) == 0) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}
$print_result = (is_par($_POST["numero"]) == TRUE) ? "<strong>Si es par</strong>" : "<strong>No es par</strong>";
response("Guía 2 - Ejerciio 2", $print_result);
?>