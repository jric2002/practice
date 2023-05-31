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
      table {
        border-collapse: collapse;
      }
      th, td {
        border: 1px solid black;
        padding: 0.5rem 1rem;
      }
    </style>
  </head>
  <body>
    <h1>Buscar Artista</h1>
    <form action="<?php echo $_SERVER["PHP_SELF"];?>" method="post">
      <label for="artista">Artista</label>
      <input type="search" name="artista" id="artista"/>
      <input type="submit" value="Buscar"/>
    </form>
    <?php if ($estado):?>
    <section class="resultado">
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
    </section>
    <?php endif;?>
  </body>
</html>