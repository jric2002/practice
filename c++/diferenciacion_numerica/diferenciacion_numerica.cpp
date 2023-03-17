#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
/* Declaration */
double f(double);
double aproxDfNAtras(double, double); // Aproximación de la derivada por diferenciación numérica hacia atras
double aproxDfNCentrada(double, double); // Aproximación de la derivada por diferenciación numérica centrada
double aproxDfNAdelante(double, double); // Aproximación de la derivada por diferenciación numérica hacia adelante
int main() {
  double x, h, dfn_atras, dfn_centrada, dfn_adelante;
  string title = "Diferenciacion Numerica";
  cout << title << endl;
  cout.width(title.size());
  cout.fill('-');
  cout << "" << endl;
  cout << "Ingrese el valor para 'x': ";
  cin >> x; // Punto de evaluacion de la derivada
  cout << "Ingrese el tamano de paso 'h': ";
  cin >> h; // Tamaño de paso o intervalo entre los puntos
  dfn_atras = aproxDfNAtras(x, h);
  dfn_centrada = aproxDfNCentrada(x, h);
  dfn_adelante = aproxDfNAdelante(x, h);
  cout << "DfN Atras -> La aproximacion de la 1ra derivada de f(x) en x = " << x << " es: " << dfn_atras << endl;
  cout << "DfN Centrada -> La aproximacion de la 1ra derivada de f(x) en x = " << x << " es: " << dfn_centrada << endl;
  cout << "DfN Adelante -> La aproximacion de la 1ra derivada de f(x) en x = " << x << " es: " << dfn_adelante << endl << endl;
  return 0;
}
/* Definition */
double f(double x) {
  double fx; // Define la función que se desea derivar
  fx = pow(x, 2);
  // fx = (-0.1 * pow(x, 4)) + (-0.15 * pow(x, 3)) + (-0.5 * pow(x, 2)) + (-0.25 * x) + 1.2;
  // fx = (0.1 * pow(x, 3)) + (0.25 * pow(x, 2)) - (0.5 * x) - 1.5;
  return fx;
}
double aproxDfNAtras(double x, double h) {
  double aprox = (f(x) - f(x - h)) / h;
  return aprox;
}
double aproxDfNCentrada(double x, double h) {
  double aprox = (f(x + h) - f(x - h)) / (2 * h);
  return aprox;
}
double aproxDfNAdelante(double x, double h) {
  double aprox = (f(x + h) - f(x)) / h;
  return aprox;
}