<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Generador de Reporte</title>
    <style>
      * {
        font-family: sans-serif;
      }
      :root {
        --black-color: #000000;
        --gray-color: #0f0f12;
        --second-color-gray: #8b949e;
        --green-color: #98ca3f;
        --yellow-color: #fcee0a;
        --sky-blue-color: #2490fc;
        --white-color: #ffffff;
      }
      h1 {
        text-align: center;
      }
      form select.consulta, form div.datos-entrada {
        font-size: 1rem;
        margin: 0 0 1rem;
      }
      form input {
        font-size: 1rem;
      }
      form input[type="text"] {
        width: 6rem;
      }
      form input[type="number"] {
        width: 3rem;
      }
      form input[type="submit"] {
        color: var(--white-color);
        background-color: var(--sky-blue-color);
        transition: background-color 0.25s linear;
      }
      form input[type="submit"]:hover {
        color: var(--white-color);
        background-color: var(--green-color);
      }
    </style>
  </head>
  <body>
    <form action="./reporte_pdf_v3.php" method="post" class="form" id="form">
      <h1>GENERADOR DE REPORTE</h1>
      <label for="consulta">Consulta:</label>
      <select name="consulta" class="consulta" id="consulta">
        <option value="salario" selected>Salario</option>
        <option value="fn">Fecha de nacimiento</option>
      </select>
      <div class="datos-entrada" id="datos-entrada"></div>
    </form>
    <section class="resultado" id="resultado">
      <!-- <div class="parametros"></div> -->
    </section>
    <script type="text/javascript">
      const PROTOCOL = window.location.protocol;
      const HOST = window.location.host;
      const PATHNAME = window.location.pathname;
      const URL = PROTOCOL + "//" + HOST;
      const FORM = document.getElementById("form");
      const DATOS_ENTRADA = document.getElementById("datos-entrada");
      const CONSULTA = document.getElementById("consulta");
      const RESULTADO = document.getElementById("resultado");
      var consultas = {
        salario: {
          contenido_form: `
            <label for="min">Mínimo:</label>
            <input type="text" name="min" id="min" value="3000">
            <label for="max">Máximo:</label>
            <input type="text" name="max" id="max" value="5000">
            <label for="cifras">Cifras:</label>
            <input type="number" name="cifras" class="cifras" id="cifras" min="0" value="0">
            <input type="submit" value="Buscar" id="buscar">`,
          data: function() {
            const MIN = document.getElementById("min");
            const MAX = document.getElementById("max");
            const CIFRAS = document.getElementById("cifras");
            return ("min=" + encodeURIComponent(MIN.value) + "&max=" + encodeURIComponent(MAX.value) + "&cifras=" + encodeURIComponent(CIFRAS.value));
          }
        },
        fn: {
          contenido_form: `
            <label for="fmin">Mínimo:</label>
            <input type="date" name="fmin" id="fmin" value="1950-01-01">
            <label for="fmax">Máximo:</label>
            <input type="date" name="fmax" id="fmax" value="1960-01-01">
            <input type="submit" value="Buscar" id="buscar">`,
          data: function() {
            const FMIN = document.getElementById("fmin");
            const FMAX = document.getElementById("fmax");
            return ("fmin=" + encodeURIComponent(FMIN.value) + "&fmax=" + encodeURIComponent(FMAX.value));
          }
        }
      };
      DATOS_ENTRADA.innerHTML = consultas[CONSULTA.value]["contenido_form"];
      CONSULTA.addEventListener("change", function() {
        DATOS_ENTRADA.innerHTML = consultas[CONSULTA.value]["contenido_form"];
      });
      FORM.addEventListener("submit", function(event) {
        event.preventDefault();
        const REQUEST = new XMLHttpRequest();
        REQUEST.open("POST", URL + (FORM.getAttribute("action")).slice(1));
        REQUEST.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
        REQUEST.addEventListener("load", function(e) {
          if (REQUEST.status === 200) {
            RESULTADO.innerHTML = `<embed src="./reporte_pdf.pdf" class="pdf-viewer" id="pdf-viewer" type="application/pdf" width="100%" height="720px"/>`;
          }
          else {
            console.log("Error en la solicitud");
          }
        });
        let d = "consulta=" + encodeURIComponent(CONSULTA.value) + "&" + consultas[CONSULTA.value]["data"]();
        // console.log(d);
        REQUEST.send(d);
      });
    </script>
  </body>
</html>