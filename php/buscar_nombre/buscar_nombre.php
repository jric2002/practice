<?php
const HOSTNAME = "localhost";
const USERNAME = "root";
const PASSWORD = "admin";
const DATABASE_NAME = "music";
$connection = new mysqli(HOSTNAME, USERNAME, PASSWORD, DATABASE_NAME);
$rs = NULL;
$fs = NULL;
$estado = FALSE;
if (isset($_POST["artista"])) {
  $b = $_POST["artista"];
  $pb = "%{$b}%";
  $query = $connection->prepare("SELECT * FROM artists WHERE name LIKE ?");
  $query->bind_param("s", $pb);
  if ($query->execute()) {
    $rs = $query->get_result();
    $fs = $rs->fetch_fields();
    $rs = $rs->fetch_all(MYSQLI_ASSOC);
    $estado = TRUE;
  }
}
?>
<?php if (!isset($_POST["realtime"])):?>
<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Buscar</title>
    <style>
      * {
        font-family: sans-serif;
      }
      h1 {
        text-align: center;
      }
      form input {
        padding: 0.5rem;
      }
      section.resultado table {
        border-collapse: collapse;
      }
      section.resultado table thead tr th, section.resultado table tbody tr td {
        border: 1px solid black;
        padding: 0.5rem 1rem;
      }
    </style>
  </head>
  <body>
    <h1>BUSCAR ARTISTA</h1>
    <form action=".<?php echo $_SERVER["PHP_SELF"]?>" method="post" class="form" id="form">
      <label for="artista">Artista:</label>
      <input type="search" name="artista" id="artista" placeholder="Buscar"/>
      <input type="submit" value="Buscar"/>
    </form>
    <section class="resultado" id="resultado">
      <?php endif;?>
      <?php if ($estado):?>
      <p>Resultado de búsqueda "<strong><?php echo $b;?></strong>"</p>
      <p>Cantidad de resultados: <strong><?php echo count($rs);?></strong></p>
      <?php if (count($rs) != 0):?>
      <table>
        <thead>
          <tr>
          <?php foreach ($fs as $f):?>
            <th><?php echo $f->name;?></th>
          <?php endforeach;?>
          </tr>
        </thead>
        <tbody>
        <?php foreach ($rs as $r):?>
          <tr>
          <?php foreach ($r as $k => $v):?>
            <td><?php echo $v;?></td>
          <?php endforeach;?>
          </tr>
        <?php endforeach;?>
        </tbody>
      </table>
      <?php endif;?>
      <?php endif;?>
<?php if (!isset($_POST["realtime"])):?>
    </section>
    <script type="text/javascript">
      const FORM = document.getElementById("form");
      const ARTISTA = document.getElementById("artista");
      const RESULTADO = document.getElementById("resultado");
      const PROTOCOL = window.location.protocol;
      const HOST = window.location.host;
      const PATHNAME = window.location.pathname;
      const URL = PROTOCOL + "//" + HOST;
      function requestPost() {
        const REQUEST = new XMLHttpRequest();
        REQUEST.open("POST", URL + PATHNAME);
        REQUEST.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
        REQUEST.onload = function() {
          if (REQUEST.status === 200) {
            RESULTADO.innerHTML = REQUEST.responseText;
          }
          else {
            console.log("Error en la solicitud");
          }
        };
        REQUEST.send("artista=" + encodeURIComponent(ARTISTA.value) + "&realtime=" + encodeURIComponent("1"));
      }
      ARTISTA.addEventListener("input", requestPost);
    </script>
  </body>
</html>
<?php endif;?>