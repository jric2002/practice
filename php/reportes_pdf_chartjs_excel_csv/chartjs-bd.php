<?php require './conexion.php'; ?>
<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Charts</title>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.9.4/Chart.js"></script>
  </head>
  <body>
    <h1> Reportes con chart.js con Base de Datoss </h1>
    <canvas id="myChart" style="width:100%;max-width:700px"></canvas>
    <!--Código js-->
  <script>
    var xValues = [<?php
    $sql = "SELECT * FROM estudiantes";
    $result = mysqli_query($mysqli,$sql);
    while($registros = mysqli_fetch_array($result)){
    ?>
    '<?php echo $registros["nombre"] ?>',
    <?php } ?>];
    var yValues = [9, 8, 6, 9, 7,10,0];
    var barColors = ["red", "green","blue","orange","black"];
    new Chart("myChart", {
      type: "bar",
      data: {
        labels: xValues,
        datasets: [{
          backgroundColor: barColors,
          data: yValues
        }]
      },
      options: {
        legend: {display: true},
        title: {
          display: true,
          text: "Asistencia de Estudiantes de ING Sistemas"
        }
      }
    });
  </script>
</body>
</html>