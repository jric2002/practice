$(document).ready(function() {
  /* Ejercicio 1 */
  $("#boton").click(function() {
    if ($("input[value=john]").prop("checked")) {
      $("#dos").css({"background-color": "#759e2d", "color": "#fff"});
    }
    else {
      $("#dos").css({"background-color": "transparent", "color": "#fff"});
    }
  });

  /* Ejercicio 2 */
  $("#boton-2").click(function() {
    if ($("#trivia-answer").val() == "resig") {
      $("#resultado").text("La respuesta es: John Resig").css("color", "green");
    }
    else {
      $("#resultado").text("Respuesta incorrecta").css("color", "red");
    }
  });

  /* Ejercicio 3 */
  $("#boton-3").click(function() {
    var $tarea = $("#tarea").val();
    if ($tarea != "") {
      $("#lista").append("<li>" + $tarea + "</li>");
    }
  });
});