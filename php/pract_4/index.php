<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Datos del Postulante - Formulario</title>
    <link rel="stylesheet" href="./main.css">
  </head>
  <body>
    <div class="datos">
      <h1>Datos del Postulante</h1>
      <form action="./procesar_datos.php" method="post" class="formulario">
        <div class="part-1">
          <div class="nombre">
            <label for="nombre">Nombres:</label>
            <input type="text" name="nombre" id="nombre" placeholder="Juan">
          </div>
          <div class="apellidos">
            <label for="apellidos">Apellidos:</label>
            <input type="text" name="apellidos" id="apellidos" placeholder="Perez">
          </div>
          <div class="edad">
            <label for="edad">Edad:</label>
            <input type="number" min="0" max="150" name="edad" id="edad" placeholder="34">
          </div>
        </div>
        <div class="part-2">
          <div class="domicilio">
            <label for="domicilio">Domicilio:</label>
            <input type="textarea" name="domicilio" id="domicilio" placeholder="Jr. Lima">
          </div>
          <div class="salario">
            <label for="salario">Que salario deseas ganar?</label>
            <select name="salario" id="salario">
              <option value="a">Menos de $1000</option>
              <option value="b">Entre $1000 y $3000</option>
              <option value="c">Entre $3000 y $5000</option>
              <option value="d">Más de $5000</option>
            </select>
          </div>
          <div class="desempeno">
            <label for="desempeno">Como consideras tu desempeño?</label>
            <div id="desempeno">
              <div class="pesimo">
                <input type="radio" id="pesimo" name="desempeno" value="pesimo">
                <label for="pesimo">Pesimo</label>
              </div>
              <div class="regular">
                <input type="radio" id="regular" name="desempeno" value="regular">
                <label for="regular">Regular</label>
              </div>
              <div class="excelente">
                <input type="radio" name="desempeno" id="excelente" value="excelente">
                <label for="excelente">Excelente</label>
              </div>
            </div>
          </div>
          <div class="botones">
            <input type="submit" value="Presione cuando este listo(a)">
            <a href="./index.php"><input type="button" value="Borra todo"></a>
          </div>
        </div>
    </form>
    </div>
  </body>
</html>