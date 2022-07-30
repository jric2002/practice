<?php
  // Include the database connection file
  include_once("config.php");
  // Query
  $result = $mysqli->query("SELECT * FROM personas");
  while ($row = $result->fetch_assoc()) {
    var_dump($row);
    echo "<br>";
  }
?>