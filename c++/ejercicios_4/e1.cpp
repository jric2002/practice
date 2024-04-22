#include <iostream>
#include <fstream>
#include <cstring>
#include "Nodo.h"
#include "Pila.h"
using namespace std;
int main(int argc, char *argv[]) {
  char nombre_archivo[] = "entrada.txt";
  fstream f(nombre_archivo, fstream::in);
  if (f.is_open()) {
    int n, diamantes;
    string cadena;
    Pila *p = new Pila();
    f >> n >> ws;
    while (n--) {
      diamantes = 0;
      getline(f, cadena, '\n');
      for (char c : cadena) {
        if (!p->esVacio() && c == '>') {
          diamantes++;
          p->eliminar();
          continue;
        }
        if (c != '.' && c != '>') {
          p->insertar(c);
        }
      }
      cout << diamantes << endl;
      p->limpiar();
    }
    delete p;
    f.close();
  }
  else {
    cout << "No se puede abrir el archivo: " << nombre_archivo << endl;
  }
  return 0;
}