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
  double x, h;
  string title = "Diferenciacion Numerica";
  cout << title << endl;
  cout.width(title.size());
  cout.fill('-');
  cout << "" << endl;
  cout << "Ingrese el valor para 'x': ";
  cin >> x; // Punto en el cual se desea calcular la 1ra derivada de la funcion
  cout << "Ingrese el tamano de paso 'h': ";
  cin >> h; // Tamaño de paso o intervalo entre los puntos
  cout << "DfN Atras -> La aproximacion de la 1ra derivada de f(x) en x = " << x << " es: " << aproxDfNAtras(x, h) << endl;
  cout << "DfN Centrada -> La aproximacion de la 1ra derivada de f(x) en x = " << x << " es: " << aproxDfNCentrada(x, h) << endl;
  cout << "DfN Adelante -> La aproximacion de la 1ra derivada de f(x) en x = " << x << " es: " << aproxDfNAdelante(x, h) << endl;
  return 0;
}
/* Definition */
double f(double x) {
  double fx;
  // fx = pow(x, 2);
  fx = (2 * pow(x, 3)) - pow(x, 2);
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