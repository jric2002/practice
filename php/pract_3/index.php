<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Empresa</title>
    <link rel="stylesheet" href="./main.css"/>
    <script defer type="text/javascript" src="./main.js"></script>
  </head>
  <body>
    <div class="main">
      <h1 class="title">Empresa - Base de Datos</h1>
      <div class="options">
        <div>
          <label for="query">Consulta:</label>
          <input type="text" name="query" id="query"/>
          <button id="query-button">Consultar</button>
        </div>
        <div>
          <button id="delete-button">Eliminar ultimo registro de la tabla "empresa"</button>
        </div>
      </div>
      <div class="query-string" id="query-string"></div>
      <div class="response" id="response"></div>
    </div>
  </body>
</html>