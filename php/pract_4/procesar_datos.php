<?php
$nombre_completo = $_POST["nombre"]." ".$_POST["apellidos"];
$edad = $_POST["edad"];
$salario = $_POST["salario"];
if ($salario == "a") {
  $salario = 930;
}
else if ($salario == "b") {
  $salario = 1000;
}
else if ($salario == "c") {
  $salario = 3000;
}
else if ($salario == "d") {
  $salario = 5000;
}
else {
  $salario = NULL;
}
$desempeno = $_POST["desempeno"];
if ($desempeno == "pesimo") {
  $desempeno = "1";
}
else if ($desempeno == "regular") {
  $desempeno = "5";
}
else if ($desempeno == "excelente") {
  $desempeno = "10";
}
else {
  $desempeno = null;
}
$status = "no cumple";
if (($salario == 1000 or $salario == 3000) and ($desempeno != "1") and ((int)$edad < 45)) {
  $status = "sí cumple satisfactoriamente";
}
?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Resultados</title>
    <link rel="stylesheet" href="./resultados.css">
  </head>
  <body>
    <div class="resultado">
      <p>Sr(a) <?php echo $nombre_completo ?><br/>
        en base a su edad <?php echo $edad ?> y sus aspiraciones<br/>
        económicas y su auto estimación hemos determinado que:<br/>
        Salario deseado: <?php echo $salario ?><br/>
        Su desempeño elegido: <?php echo $desempeno ?><br/>
        Usted <?php echo $status ?> nuestras aspiraciones
      </p>
    </div>
  </body>
</html>