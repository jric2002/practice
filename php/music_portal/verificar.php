<?php
define("ROUTE", $_SERVER["REQUEST_URI"]);
const ROUTES = array(
  "/" => "index.php",
  "/login" => "login.php",
  "/404" => "404.php"
);
$error_404 = TRUE;
foreach (ROUTES as $key => $value) {
  if (ROUTE == $key) {
    header("Location: ./$value");
    $error_404 = FALSE;
    break;
  }
}
if ($error_404) {
  header("Location: ./${$ROUTES["/404"]}");
}
?>