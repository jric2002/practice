<?php
const HOSTNAME = "localhost";
const USERNAME = "root";
const PASSWORD = "admin";
const DATABASE_NAME = "empresa";
switch ($_SERVER["REQUEST_METHOD"]) {
  case "POST":
    $connection = new mysqli(HOSTNAME, USERNAME, PASSWORD, DATABASE_NAME);
    if ($connection) {
      $query = trim(json_decode(file_get_contents("php://input"), TRUE)["query"]);
      if ($query != "") {
        $r = $connection->query($query);
        $response = array("fields" => $r->fetch_fields());
        $response["data"] = $r->fetch_all(MYSQLI_ASSOC);
      }
      else {
        $response = "";
      }
      echo json_encode($response);
    }
    else {
      echo json_encode(array("Error" => "Ha ocurrido un problema"));
      exit();
    }
    $connection->close();
    break;
  default:
    echo "No hay datos";
    break;
}
?>