#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <limits>
#include <map>
#include <cmath>
#define PI 3.14159265
/* Author: José Rodolfo */
using namespace std;
template <typename T>
class Calculadora {
  public:
    Calculadora();
    static T sumar(vector<T>);
    static T restar(vector<T>);
    static T multiplicar(vector<T>);
    static T dividir(T, T);
    static T raizCuadrada(T);
    static T potencia(T, T);
};
template <typename T = double>
class CalculadoraCientifica: public Calculadora<T> {
  public:
    CalculadoraCientifica(): Calculadora<T>() {}
    static T seno(T);
    static T coseno(T);
    static T tangente(T);
    static T arcoseno(T);
    static T arcocoseno(T);
    static T arcotangente(T);
    static T logaritmoBase10(T);
    static T logaritmoNatural(T);
    static T exponencial(T);
    static T factorial(T);
};
int main(int argc, char *argv[]) {
  string title = "CALCULADORA CIENTIFICA", s, opt;
  stringstream ss;
  map<int, string> operaciones = {
    {1, "Sumar"},
    {2, "Restar"},
    {3, "Multiplicar"},
    {4, "Dividir"},
    {5, "Raiz Cuadrada"},
    {6, "Potencia"},
    {7, "Seno"},
    {8, "Coseno"},
    {9, "Tangente"},
    {10, "Arcoseno"},
    {11, "Arcocoseno"},
    {12, "Arcotangente"},
    {13, "Logaritmo Base 10"},
    {14, "Logaritmo Natural"},
    {15, "Exponencial"},
    {16, "Factorial"}
  };
  vector<double> numeros;
  double n;
  // CalculadoraCientifica<double> cc;
  while (true) {
    cout << title << endl;
    cout.fill('-');
    cout.width(title.size());
    cout << "" << endl;
    for (map<int, string>::iterator it = operaciones.begin(); it != operaciones.end(); it++) {
      cout << it->first << ". " << it->second << endl;
    }
    cout << 0 << ". Salir" << endl;
    cout.fill('-');
    cout.width(title.size());
    cout << "\nOption: "; cin >> opt;
    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (stoi(opt) == 0) break;
    switch (stoi(opt)) {
      case 1:
        cout << "Ingresa los numeros separados por espacios: ";
        getline(cin, s, '\n');
        ss << s;
        while (ss >> n) {
          numeros.push_back(n);
        }
        cout << "Suma: " << Calculadora<double>::sumar(numeros) << endl;
        ss.clear();
        numeros.clear();
        break;
      case 2:
        cout << "Ingresa los numeros separados por espacios: ";
        getline(cin, s, '\n');
        ss << s;
        while (ss >> n) {
          numeros.push_back(n);
        }
        cout << "Resta: " << Calculadora<double>::sumar(numeros) << endl;
        ss.clear();
        numeros.clear();
        break;
      case 3:
        cout << "Ingresa los numeros separados por espacios: ";
        getline(cin, s, '\n');
        ss << s;
        while (ss >> n) {
          numeros.push_back(n);
        }
        cout << "Multiplicacion: " << Calculadora<double>::multiplicar(numeros) << endl;
        ss.clear();
        numeros.clear();
        break;
      case 4:
        double dividendo, divisor;
        cout << "Ingresa el dividendo: "; cin >> dividendo;
        cout << "Ingresa el divisor: "; cin >> divisor;
        cout << "Division: " << Calculadora<double>::dividir(dividendo, divisor) << endl;
        break;
      case 5:
        cout << "Ingresa el numero: "; cin >> n;
        cout << "Raiz Cuadrada: " << Calculadora<double>::raizCuadrada(n) << endl;
        break;
      case 6:
        double b, e;
        cout << "Ingresa la base: "; cin >> b;
        cout << "Ingresa el exponente: "; cin >> e;
        cout << "Potencia: " << Calculadora<double>::potencia(b, e) << endl;
        break;
      case 7:
        cout << "Ingresa un numero: "; cin >> n;
        cout << "Seno: " << CalculadoraCientifica<double>::seno(n) << endl;
        break;
      case 8:
        cout << "Ingresa un numero: "; cin >> n;
        cout << "Coseno: " << CalculadoraCientifica<double>::coseno(n) << endl;
        break;
      case 9:
        cout << "Ingresa un numero: "; cin >> n;
        cout << "Tangente: " << CalculadoraCientifica<double>::tangente(n) << endl;
        break;
      case 10:
        cout << "Ingresa un numero: "; cin >> n;
        cout << "Arcoseno: " << CalculadoraCientifica<double>::arcoseno(n) << " grados" << endl;
        break;
      case 11:
        cout << "Ingresa un numero: "; cin >> n;
        cout << "Arcocoseno: " << CalculadoraCientifica<double>::arcocoseno(n) << " grados" << endl;
        break;
      case 12:
        cout << "Ingresa un numero: "; cin >> n;
        cout << "Arcotangente: " << CalculadoraCientifica<double>::arcotangente(n) << " grados" << endl;
        break;
      case 13:
        cout << "Ingresa un numero: "; cin >> n;
        cout << "Logaritmo en base 10: " << CalculadoraCientifica<double>::logaritmoBase10(n) << endl;
        break;
      case 14:
        cout << "Ingresa un numero: "; cin >> n;
        cout << "Logaritmo natural: " << CalculadoraCientifica<double>::logaritmoNatural(n) << endl;
        break;
      case 15:
        cout << "Ingresa un numero: "; cin >> n;
        cout << "Exponencial (e^n): " << CalculadoraCientifica<double>::exponencial(n) << endl;
        break;
      case 16:
        cout << "Ingresa un numero: "; cin >> n;
        cout << "Factorial: " << CalculadoraCientifica<double>::factorial(n) << endl;
        break;
      default:
        cout << "Opcion incorrecta." << endl;
    }
    cout << endl;
  }
  return 0;
}
template <typename T>
Calculadora<T>::Calculadora() {}
template <typename T>
T Calculadora<T>::sumar(vector<T> n) {
  T st = 0;
  for (T v : n) {
    st += v;
  }
  return st;
}
template <typename T>
T Calculadora<T>::restar(vector<T> n) {
  T rt = 0;
  for (T v : n) {
    rt -= v;
  }
  return rt;
}
template <typename T>
T Calculadora<T>::multiplicar(vector<T> n) {
  T m = 1;
  for (T v : n) {
    m *= v;
  }
  return m;
}
template <typename T>
T Calculadora<T>::dividir(T dividendo, T divisor) {
  return dividendo/divisor;
}
template <typename T>
T Calculadora<T>::raizCuadrada(T n) {
  return sqrt(n);
}
template <typename T>
T Calculadora<T>::potencia(T base, T exponente) {
  return pow(base, exponente);
}
template <typename T>
T CalculadoraCientifica<T>::seno(T n) {
  return sin((PI * n)/180);
}
template <typename T>
T CalculadoraCientifica<T>::coseno(T n) {
  return cos((PI * n)/180);
}
template <typename T>
T CalculadoraCientifica<T>::tangente(T n) {
  return tan((PI * n)/180);
}
template <typename T>
T CalculadoraCientifica<T>::arcoseno(T n) {
  return asin(n) * 180.0/PI;
}
template <typename T>
T CalculadoraCientifica<T>::arcocoseno(T n) {
  return acos(n) * 180.0/PI;
}
template <typename T>
T CalculadoraCientifica<T>::arcotangente(T n) {
  return atan(n) * 180.0/PI;
}
template <typename T>
T CalculadoraCientifica<T>::logaritmoBase10(T n) {
  return log10(n);
}
template <typename T>
T CalculadoraCientifica<T>::logaritmoNatural(T n) {
  return log(n);
}
template <typename T>
T CalculadoraCientifica<T>::exponencial(T n) {
  return exp(n);
}
template <typename T>
T CalculadoraCientifica<T>::factorial(T n) {
  double f = 1;
  while (n > 0) {
    f *= n;
    n--;
  }
  return f;
}