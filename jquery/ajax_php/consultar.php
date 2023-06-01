<?php
  //conectamos a la base de datos
  $mysqli = new mysqli("localhost", "root", "admin", "ajaxbd");
  if ($mysqli->connect_errno) die($mysqli->connect_error);
  //Consultamos datos de la base de datos y lo imprimimos en formato json
  $query = "SELECT * FROM personas";
  $datos = [];
  if ($result = $mysqli->query($query)) {
    while ($row = $result->fetch_assoc()) {
      $datos[] = [$row["id"], $row["nombres"], $row['apellidos']];
    }
    $result->free();
  }
  echo json_encode($datos);
?>