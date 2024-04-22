#include <iostream>
#include <fstream>
#include "Nodo.h"
#include "Pila.h"
using namespace std;
int main(int argc, char *argv[]) {
  char nombre_archivo[] = "entrada.txt";
  fstream f(nombre_archivo, fstream::in);
  if (f.is_open()) {
    f.close();
  }
  else {
    cout << "No se puede abrir el archivo: " << nombre_archivo << endl;
  }
  return 0;
}