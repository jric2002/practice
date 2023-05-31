<?php
/* GUIA 2 */
/* Ejercico 3 */
require("../response.php");
function esPrimo($n): bool {
  for ($i = 2; $i <= ($n / 2); $i++):
    if (($n % $i) == 0):
      return FALSE;
    endif;
  endfor;
  return TRUE;
}
$result = (esPrimo((int)$_POST["numero-3"]) == TRUE) ? "<strong>SI es primo</strong>" : "<strong>NO es primo</strong>";
response("Guía 2 - Ejerciio 2", $result);
?>