/*************************
 * GUIA 3 - EJERCICIOS *
*************************/
/* EJERCICIO 1 */
const but_1 = document.getElementById("but-1");
var message_1 = document.getElementById("message-1");
function verify(n) {
  if ((n % 2) == 0) {
    return "Par";
  }
  else {
    return "Impar";
  }
}
but_1.addEventListener("click", function() {
  var numb = parseFloat(document.getElementById("numb").value);
  message_1.innerHTML = "El numero es: " + verify(numb);
});

/* EJERCICIO 2 */
const but_2 = document.getElementById("but-2");
var message_2 = document.getElementById("message-2");
function escribirTablaMultiplicar(n) {
  var tabla = "";
  var i = 0;
  var n_max = 10;
  while (i <= n_max) {
    tabla = tabla + String(n) + " x " + String(i) + " = " + String(n * i) + "<br>";
    i++;
  }
  return tabla;
}
but_2.addEventListener("click", function() {
  var num_t = parseInt(document.getElementById("num-t").value);
  message_2.innerHTML = "Tabla de multiplicar de <b>" + String(num_t) + "</b>:<br>" + escribirTablaMultiplicar(num_t);
});

/* EJERCICIO 3 */
const but_3 = document.getElementById("but-3");
var message_3 = document.getElementById("message-3");
//numeros primos: 2 3 5 7 11 13 17 19 23 ...
function esPrimo(n) {
  for (var i = 2; i <= (n / 2); i++) {
    if ((n % i) == 0) {
      return 0;
    }
  }
  return 1;
}
but_3.addEventListener("click", function() {
  var num_p = parseInt(document.getElementById("num-p").value);
  if (esPrimo(num_p) == 0) {
    message_3.innerHTML = "El numero <b>" + String(num_p) + "</b> NO es Primo";
  }
  if (esPrimo(num_p) == 1) {
    message_3.innerHTML = "El numero <b>" + String(num_p) + "</b> SI es Primo";
  }
});

/* EJERCICIO 4 */
const but_4 = document.getElementById("but-4");
var message_4 = document.getElementById("message-4");
function dibujaTriangulo(n) {
  var triangulo = "";
  var i = 1;
  while (i <= n) {
    triangulo = triangulo + "* ".repeat(i) + "<br>";
    i++;
  }
  return triangulo;
}
but_4.addEventListener("click", function() {
  var numero_ast = parseInt(document.getElementById("numero-ast").value);
  if (numero_ast > 0) {
    message_4.innerHTML = dibujaTriangulo(numero_ast);
  }
  else {
    message_4.innerHTML = "Ha ocurrido un problema, por favor ingresa un numero positivo.";
  }
});