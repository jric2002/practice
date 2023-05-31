/*************************
 * GUIA 2 - EJERCICIOS *
*************************/
/* EJERCICIO 1 */
const button_1 = document.getElementById("button-1");
var msg_1 = document.getElementById("msg-1");
button_1.addEventListener("click", function() {
  var nota_1 = parseFloat(document.getElementById("nota-1").value);
  var nota_2 = parseFloat(document.getElementById("nota-2").value);
  var nota_3 = parseFloat(document.getElementById("nota-3").value);
  var nota_4 = parseFloat(document.getElementById("nota-4").value);
  if (nota_1 >= 0 && nota_2 >= 0 && nota_3 >= 0 && nota_4 >= 0) {
    var notas = [nota_1, nota_2, nota_3, nota_4];
    notas.sort();
    var promedio = (notas[1] + notas[2] + notas[3])/3;
    msg_1.innerHTML = "Nota eliminada: " + notas[0] + "<br>" + "Promedio de las 3 notas: " + promedio;
  }
  else {
    msg_1.innerHTML = "Ha ocurrido un error, ingresa un numero positivo."
  }
});

/* EJERCICIO 2 */
const button_2 = document.getElementById("button-2");
var msg_2 = document.getElementById("msg-2");
button_2.addEventListener("click", function() {
  var monto = parseFloat(document.getElementById("monto").value);
  var tipo_cliente = String(document.getElementById("tipo-cliente").value).toLowerCase();
  var forma_pago = String(document.getElementById("forma-pago").value).toLowerCase();
  var monto_total;
  var recargo;
  var descuento;
  if (monto >= 0) {
    if (tipo_cliente == "g") {
      if (forma_pago == "c") {
        descuento = (monto * 15)/100;
        monto_total = monto - descuento;
        msg_2.innerHTML = "Descuento 15%: " + descuento + "<br>" + "Total a pagar: " + monto_total;
      }
      else if (forma_pago == "p") {
        recargo = (monto * 10)/100;
        monto_total = monto + recargo;
        msg_2.innerHTML = "Recargo 10%: " + recargo + "<br>" + "Total a pagar: " + monto_total;
      }
      else {
        msg_2.innerHTML = "No existe esa forma de pago. Eligue C(al contado) o P(a plazos)";
      }
    }
    else if (tipo_cliente == "a") {
      if (forma_pago == "c") {
        descuento = (monto * 20)/100;
        monto_total = monto - descuento;
        msg_2.innerHTML = "Descuento 20%: " + descuento + "<br>" + "Total a pagar: " + monto_total;
      }
      else if (forma_pago == "p") {
        recargo = (monto * 5)/100;
        monto_total = monto + recargo;
        msg_2.innerHTML = "Recargo 5%: " + recargo + "<br>" + "Total a pagar: " + monto_total;
      }
      else {
        msg_2.innerHTML = "No existe esa forma de pago. Eligue C(al contado) o P(a plazos)"
      }
    }
    else {
      msg_2.innerHTML = "Ha ocurrido un error, ingresa un A(cliente afiliado) o G(cliente general).";
    }
  }
  else {
    msg_2.innerHTML = "Ha ocurrido un error, ingrese un numero positivo";
  }
});

/* EJERCICIO 3 */
const button_3 = document.getElementById("button-3");
var msg_3 = document.getElementById("msg-3");
button_3.addEventListener("click", function() {
  var numero_f = parseInt(document.getElementById("numero-factorial").value);
  var factorial = 1;
  if (numero_f > 0) {
    for (var i = numero_f; i > 0; i--) {
      factorial = factorial * i;
    }
    msg_3.innerText = "Factorial de " + String(numero_f) + " es: " + String(factorial);
  }
  else if (numero_f == 0) {
    msg_3.innerText = "Factorial de " + String(numero_f) + " es: 1";
  }
  else {
    msg_3.innerText = "Ha ocurrido un error, ingresa un numero mayor que cero";
  }

});

/* EJERCICIO 4 */
const button_4 = document.getElementById("button-4");
var msg_4 = document.getElementById("msg-4");
button_4.addEventListener("click", function() {
  var numero_c = parseInt(document.getElementById("num").value);
  var suma = 0;
  if (numero_c >= 0) {
    cifras = String(numero_c).split("");
    for (var cifra of cifras) {
      suma += parseInt(cifra);
    }
    msg_4.innerHTML = "La suma de las cifras es: " + suma;
  }
  else {
    msg_4.innerHTML = "Ha ocurrido un error, ingresa un numero positivo.";
  }
});