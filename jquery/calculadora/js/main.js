$(document).ready(function() {
  var $display = $("input#display");
  var $buttons = $("div.buttons").find("a");
  var $numeros = [];
  var $numero = "";
  var $operacion = null;
  var $r = 0;
  $buttons.click(function() {
    var $btn = $(this);
    if ($btn.text() == "+") {
      $operacion = "+";
      $numeros.push(parseInt($numero));
      $numero = "";
      $display.val($display.val() + $btn.text());
    }
    else if ($btn.text() == "-") {
      $operacion = "-";
      $numeros.push(parseInt($numero));
      $numero = "";
      $display.val($display.val() + $btn.text());
    }
    else if ($btn.text() == "*") {
      $operacion = "*";
      $numeros.push(parseInt($numero));
      $numero = "";
      $display.val($display.val() + $btn.text());
    }
    else if ($btn.text() == "/") {
      $operacion = "/";
      $numeros.push(parseInt($numero));
      $numero = "";
      $display.val($display.val() + $btn.text());
    }
    else if ($btn.text() == "=") {
      $numeros.push(parseInt($numero));
      if ($operacion == "+") {
        $r = $numeros[0] + $numeros[1];
      }
      if ($operacion == "-") {
        $r = $numeros[0] - $numeros[1];
      }
      if ($operacion == "*") {
        $r = $numeros[0] * $numeros[1];
      }
      if ($operacion == "/") {
        $r = $numeros[0] / $numeros[1];
      }
      $display.val($display.val() + $btn.text() + $r.toString());
      $numero = "";
      $operacion = null;
      $numeros = [];
    }
    else if ($btn.text() == "C") {
      $numeros = [];
      $numero = "";
      $operacion = null;
      $display.val("");
    }
    else {
      $numero += $btn.text();
      $display.val($display.val() + $btn.text());
    }
  });
});