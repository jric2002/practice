<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registro de Libros y Usuarios</title>
    <link rel="stylesheet" href="./main.css">
  </head>
  <body>
    <div class="libro">
      <h1>Registar Libro</h1>
      <form action="./registrar_libro.php" method="post">
        <div class="titulo">
          <span>Título</span>
          <input type="text" name="titulo" placeholder="Título" required>
        </div>
        <div class="descripcion">
          <span>Descripción (opcional)</span>
          <input type="text" name="descripcion" placeholder="Descripción">
        </div>
        <div class="enviar">
          <input type="submit" value="Enviar">
        </div>
      </form>
    </div>
    <div class="usuario">
      <h1>Registar Usuario</h1>
      <form action="./registrar_usuario.php" method="post">
        <div class="user">
          <span>Usuario</span>
          <input type="text" name="usuario" placeholder="Usuario" required>
        </div>
        <div class="password">
          <span>Contraseña</span>
          <input type="text" name="password" placeholder="Contraseña" required>
        </div>
        <div class="enviar">
          <input type="submit" value="Enviar">
        </div>
      </form>
    </div>
  </body>
</html>