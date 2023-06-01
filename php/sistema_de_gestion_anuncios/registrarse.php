<!DOCTYPE html>
  <html lang="es">
  <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="./page.css">
    <link rel="stylesheet" href="./registrarse.css">
    <link rel="stylesheet" href="./footer.css">
    <title>Sistema de Gestión de Anuncios - SGA</title>
  </head>
  <body>
    <header>
      <a href="./index.php">
        <img src="./img/sga-logo.png" alt="SGA">
      </a>
      <div>
        <a href="./login.php" class="publicar">Iniciar sesión</a>
        <a href="./registrarse.php" class="destacado">Registrarse</a>
      </div>
    </header>
    <section>
      <form action="./inicio.php">
        <div class="izq">
          <h1>Crear una cuenta en SGA</h1>
          <div class="parte">
            <input type="text" name="" id="" placeholder="Nombres">
            <input type="text" name="" id="" placeholder="Apellidos">
          </div>
          <div class="parte">
            <select name="pais" id="pais">
              <option value="ar">Argentina</option>
              <option value="mx">Mexico</option>
              <option value="pe">Perú</option>
            </select>
            <input type="number" name="" id="" placeholder="Número">
          </div>
          <div class="parte">
            <input type="email" name="" id="" placeholder="Correo electronico">
          </div>
          <div class="parte">
            <input type="password" name="" id="" placeholder="Contraseña">
            <input type="password" name="" id="" placeholder="Confirmar contraseña">
          </div>
          <p>Utiliza ocho caracteres como mínimo con una combinación de letras, números y símbolos</p>
          <input type="submit" value="Crear cuenta">
          <div class="checks">
            <input type="checkbox" name="" id=""><span>Mostrar contraseña</span>
          </div>
          <div class="checks">
            <input type="radio" name="" id=""><span>Acepto terminos y condiciones</span>
          </div>
          <a href="./login.php" class="login">Prefiero iniciar sesión</a>
          <div class="social-media">
            <a href="#">
              <svg width="32" height="32" viewBox="0 0 256 256"><path fill="#1877F2" d="M256 128C256 57.308 198.692 0 128 0C57.308 0 0 57.307 0 128c0 63.888 46.808 116.843 108 126.445V165H75.5v-37H108V99.8c0-32.08 19.11-49.8 48.347-49.8C170.352 50 185 52.5 185 52.5V84h-16.14C152.958 84 148 93.867 148 103.99V128h35.5l-5.675 37H148v89.445c61.192-9.602 108-62.556 108-126.445"/><path fill="#FFF" d="m177.825 165l5.675-37H148v-24.01C148 93.866 152.959 84 168.86 84H185V52.5S170.352 50 156.347 50C127.11 50 108 67.72 108 99.8V128H75.5v37H108v89.445A128.959 128.959 0 0 0 128 256a128.9 128.9 0 0 0 20-1.555V165h29.825"/></svg>
            </a>
            <a href="#">
              <svg width="31.27" height="32" viewBox="0 0 256 262"><path fill="#4285F4" d="M255.878 133.451c0-10.734-.871-18.567-2.756-26.69H130.55v48.448h71.947c-1.45 12.04-9.283 30.172-26.69 42.356l-.244 1.622l38.755 30.023l2.685.268c24.659-22.774 38.875-56.282 38.875-96.027"/><path fill="#34A853" d="M130.55 261.1c35.248 0 64.839-11.605 86.453-31.622l-41.196-31.913c-11.024 7.688-25.82 13.055-45.257 13.055c-34.523 0-63.824-22.773-74.269-54.25l-1.531.13l-40.298 31.187l-.527 1.465C35.393 231.798 79.49 261.1 130.55 261.1"/><path fill="#FBBC05" d="M56.281 156.37c-2.756-8.123-4.351-16.827-4.351-25.82c0-8.994 1.595-17.697 4.206-25.82l-.073-1.73L15.26 71.312l-1.335.635C5.077 89.644 0 109.517 0 130.55s5.077 40.905 13.925 58.602l42.356-32.782"/><path fill="#EB4335" d="M130.55 50.479c24.514 0 41.05 10.589 50.479 19.438l36.844-35.974C195.245 12.91 165.798 0 130.55 0C79.49 0 35.393 29.301 13.925 71.947l42.211 32.783c10.59-31.477 39.891-54.251 74.414-54.251"/></svg>
            </a>
          </div>
        </div>
        <div class="der">
          <img src="./img/img-registrarse.jpeg" alt="">
        </div>
      </form>
    </section>
<?php
include_once("./footer.php");
?>