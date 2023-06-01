#include <iostream>
using namespace std;
/*
int extraerDiamantes(string linea) {
  char apertura_diamante = '<';
  char cierre_diamante = '>';
  int c_apertura_diamante = 0; // <
  int c_cierre_diamante = 0; // >
  int cantidad_de_diamantes = 0;
  for (int i = 0; i < linea.size(); i++) {
    if (linea[i] == apertura_diamante) {
      c_apertura_diamante += 1;
    }
    else if (linea[i] == cierre_diamante) {
      c_cierre_diamante += 1;
      if (apertura_diamante > 0 && cierre_diamante > 0) {
        c_apertura_diamante -= 1;
        c_cierre_diamante -= 1;
        cantidad_de_diamantes += 1;
      }
    }
    else if (linea[i] == '.') {
      continue;
    }
    else {
      cout << "Esto " << linea << " no es arena...xD" << endl;
      return 0;
    }
  }
  return cantidad_de_diamantes;
}
*/
/*****************/
int extraerDiamantes(string linea) {
  char apertura_diamante = '<';
  char cierre_diamante = '>';
  char particula_arena = '.';
  int posicion_apertura_diamante = -1;
  int posicion_cierre_diamante = -1;
  int cantidad_de_diamantes = 0;
  // Buscar diamantes para extraerlos
  for (int i = 0; i < linea.size(); i++) {
    if (linea[i] == apertura_diamante) {
      posicion_apertura_diamante = i;
    }
    else if (linea[i] == cierre_diamante) {
      posicion_cierre_diamante = i;
      if (posicion_apertura_diamante != -1) {
        linea.erase(posicion_apertura_diamante, (posicion_cierre_diamante - posicion_apertura_diamante) + 1);
        posicion_apertura_diamante = -1;
        posicion_cierre_diamante = -1;
        cantidad_de_diamantes += 1;
        i = -1;
      }
    }
    else if (linea[i] == particula_arena) {
      continue;
    }
    else {
      cout << "Esto " << linea[i] << " no es arena...xD" << endl;
      return 0;
    }
  }
  return cantidad_de_diamantes;
}
int main() {
  /*
  int casos_de_prueba;
  // Entrada de datos
  cout << "Ingresa un numero de casos de prueba: ";
  cin >> casos_de_prueba;
  string lineas[casos_de_prueba];
  cin.ignore(); // ignorar salto de linea que esta almacenado en el buffer de entrada
  for (int i = 0; i < casos_de_prueba; i++) {
    getline(cin, lineas[i]);
  }
  // Salida de datos
  cout << endl;
  for (int i = 0; i < casos_de_prueba; i++) {
    cout << extraerDiamantes(lineas[i]) << endl;
  }
  */
  /*************************/
  int casos_de_prueba;
  // Entrada de datos
  cout << "Ingresa un numero de casos de prueba: ";
  cin >> casos_de_prueba;
  string lineas[casos_de_prueba];
  cin.ignore(); // ignorar salto de linea que esta almacenado en el buffer de entrada
  for (int i = 0; i < casos_de_prueba; i++) {
    getline(cin, lineas[i]);
  }
  // Salida de datos
  cout << endl;
  for (int i = 0; i < casos_de_prueba; i++) {
    cout << extraerDiamantes(lineas[i]) << endl;
  }
  return 0;
}