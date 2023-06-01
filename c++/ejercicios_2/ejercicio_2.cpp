#include <iostream>
#include <iomanip>
using namespace std;
bool esCorrecto(string expresion) {
  int posicion_parent_abierto = -1;
  int posicion_parent_cerrado = -1;
  //int c_parent_abierto = 0;
  //int c_parent_cerrado = 0;
  //int total_parent = 0;
  int c_pares_parent = 0;
  int total_parent_sobran = 0;
  int c_parent_abierto_sobran = 0;
  int c_parent_cerrado_sobran = 0;
  char parent_abierto = '(';
  char parent_cerrado = ')';
  bool respuesta;
  // Buscar pares de parentesis para extraerlos
  for (int i = 0; i < expresion.size(); i++) {
    if (expresion[i] == parent_abierto) {
      posicion_parent_abierto = i;
    }
    else if (expresion[i] == parent_cerrado) {
      posicion_parent_cerrado = i;
      if (posicion_parent_abierto != -1) {
        expresion.erase(posicion_parent_abierto, (posicion_parent_cerrado - posicion_parent_abierto) + 1);
        posicion_parent_abierto = -1;
        posicion_parent_cerrado = -1;
        c_pares_parent += 1;
        i = -1;
      }
    }
    else {
      continue;
    }
  }
  // Contar parentesis que sobran
  for (int i = 0; i < expresion.size(); i++) {
    if (expresion[i] == parent_abierto) {
      c_parent_abierto_sobran += 1;
    }
    else if (expresion[i] == parent_cerrado) {
      c_parent_cerrado_sobran += 1;
    }
    else {
      continue;
    }
  }
  total_parent_sobran = c_parent_abierto_sobran + c_parent_cerrado_sobran;
  //c_parent_abierto = (c_pares_parent / 2) + c_parent_abierto_sobran;
  //c_parent_cerrado = (c_pares_parent / 2) + c_parent_cerrado_sobran;
  //total_parent = c_parent_abierto + c_parent_cerrado;
  respuesta = (total_parent_sobran == 0) ? true : false;
  return respuesta;
}
int main() {
  int c_expresiones;
  string respuesta;
  // Entrada de datos
  cout << "Cantidad de expresiones: ";
  cin >> c_expresiones;
  cin.ignore();
  string expresiones[c_expresiones];
  for (int i = 0; i < c_expresiones; i++) {
    getline(cin, expresiones[i]);
  }
  // Salida de datos
  cout << endl;
  for (int i = 0; i < c_expresiones; i++) {
    respuesta = (esCorrecto(expresiones[i])) ? "es correcto" : "es incorrecto";
    cout << expresiones[i] << setw(5) << "-> " << setw(3) << respuesta << endl;
  }
  return 0;
}