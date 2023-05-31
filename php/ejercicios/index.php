<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ejercicios de la guía 2 y 3</title>
    <link rel="stylesheet" href="main.css">
  </head>
  <body>
  <h1>PHP - Ejercicios</h1>
    <hr>
    <div class="author">Autor: José Rodolfo</div>
    <hr>
    <h2>Guía 2</h2>
    <div class="container">
      <form action="guia_2/isPar.php" method="POST">
        <div class="numero">1</div>
        <p>Que muestre por pantalla si un número es par o impar, utilizar una función.</p>
        Número: <input type="text" id="numero" name="numero" placeholder="Ejm: 10">
        <input type="submit" value="Verificar" id="btn-1">
      </form>
      <form action="guia_2/escribirTablaMultiplicar.php" method="POST">
        <div class="numero">2</div>
        <p>Crear una función escribirTablaMultiplicar, que reciba como parámetro un número entero, y escriba la tabla de multiplicar de ese número (por ejemplo, para el 3 deberá llegar desde 3x1=3 hasta 3x10=30:</p>
        Numero: <input type="text" id="numero-2" name="numero-2" placeholder="Ejm: 3"><br>
        <input type="submit" value="Escribir tabla de multiplicar" id="btn-2">
      </form>
      <form action="guia_2/esPrimo.php" method="POST">
        <div class="numero">3</div>
        <p>Crear una función esPrimo, que reciba un número y devuelva el valor 1 si es un número primo o 0 en caso contrario.</p>
        Número: <input type="text" id="numero-3" name="numero-3" placeholder="Ejm: 4">
        <input type="submit" value="Verificar" id="btn-3">
      </form>
      <form action="guia_2/dibujarTriangulo.php" method="POST">
        <div class="numero">4</div>
        <p>Implementar una función dibujaTriangulo que reciba un número y devuelva como resultado en la pantalla un triángulo formado por asteriscos, por ejemplo N = 5:</p>
        Número: <input type="text" id="numero-4" name="numero-4" placeholder="Ejm: 1234">
        <input type="submit" value="Dibujar triangulo" id="btn-4">
      </form>
    </div>
    <hr>
    <h2>Guía 3</h2>
    <div class="container">
      <form action="guia_3/validar.php" method="POST">
        <div class="numero">1</div>
        <p>Desarrolle un login con ayuda de html y css (Frontend) y php (backend), al ingresar con un usuario se debe mostrar un mensaje mostrando si esta registrado en una tabla o no.</p>
        Usuario: <input type="text" id="usuario" name="usuario" placeholder="User" required><br>
        Contraseña: <input type="text" id="password" name="password" placeholder="Password" required><br>
        <input type="submit" value="Entrar" id="submit-1">
      </form>
    </div>
  </body>
</html>