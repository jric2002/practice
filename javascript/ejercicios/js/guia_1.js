/***********************
 * GUIA 1 - EJERCICIOS *
 **********************/
/* EJERCICIO 1 */
//Diseñe un algoritmo para convertir una longitud dada en metros a pulgadas. Considere que: 1pulgada = 25.4 mm.
var pulgadas;
// 1 pulgada = 25.4 mm = 2.54 cm = 254/10000 m
const btn1 = document.getElementById("btn-1");
var result1 = document.getElementById("result-1");
btn1.addEventListener("click", function() {
  const metros = parseFloat(document.getElementById("metros").value);
  if (metros > 0) {
    pulgadas = (metros*10000)/254;
    result1.innerHTML = pulgadas + " pulgadas";
  }
  else {
    result1.innerHTML = "No es un número positivo.";
  }
});

/* EJERCICIO 2 */
//Diseñar un algoritmo para leer las longitudes de los tres lados de un triángulo (L1, L2, L3) y calcular el área del mismo de acuerdo con la siguiente fórmula:
var area;
var sp;
const btn2 = document.getElementById("btn-2");
var result2 = document.getElementById("result-2");
btn2.addEventListener("click", function() {
  var l1 = parseFloat(document.getElementById("l-1").value);
  var l2 = parseFloat(document.getElementById("l-2").value);
  var l3 = parseFloat(document.getElementById("l-3").value);
  if (l1 >= 0 && l2 >= 0 && l3 >= 0) {
    sp = (l1 + l2 + l3)/2;
    area = Math.sqrt(sp*(sp - l1)*(sp - l2)*(sp - l3));
    result2.innerHTML = "El area del triangulo es: " + area;
  }
  else {
    result2.innerHTML = "No es un número positivo.";
  }
});

/* EJERCICIO 3 */
//Realizar el algoritmo que calcule la longitud y el área total de tres circunferencias sabiendo que la 1ª de ellas tiene radio R que será introducido por teclado, la 2ª tiene radio 2R y la 3ª tiene radio 3R.
var area_total;
var area_1, area_2, area_3;
var longitud_total;
var long_1, long_2, long_3;
const btn3 = document.getElementById("btn-3");
var result3 = document.getElementById("result-3");
btn3.addEventListener("click", function() {
  const radio = parseFloat(document.getElementById("radio").value);
  if (radio > 0) {
    area_1 = Math.PI * Math.pow(radio, 2);
    area_2 = Math.PI * Math.pow(2 * radio, 2);
    area_3 = Math.PI * Math.pow(3 * radio, 2);
    area_total = area_1 + area_2 + area_3;
    long_1 = 2 * Math.PI * radio;
    long_2 = 2 * Math.PI * (2 * radio);
    long_3 = 2 * Math.PI * (3 * radio);
    longitud_total = long_1 + long_2 + long_3;
    result3.innerHTML = "De las 3 circunferencias.<br>Area total: " + area_total + "<br>Longitud total: " + longitud_total;
  }
  else {
    result3.innerHTML = "No es un número positivo."
  }
});

/* EJERCICIO 4 */
//Diseñe un algoritmo que determine la suma de las cifras de un número entero positivo de 4 cifras.
const btn4 = document.getElementById("btn-4");
var result4 = document.getElementById("result-4");
btn4.addEventListener("click", function() {
  var suma = 0;
  var number = parseInt(document.getElementById("numero").value);
  if (number >= 1000 && number <= 9999) {
    number = String(number).split("");
    for (var num of number) {
      suma += parseInt(num);
    }
    result4.innerHTML = "La suma de las cifras es: " + suma;
  }
  else {
    result4.innerHTML = "No es un número positivo de 4 cifras.";
  }
});