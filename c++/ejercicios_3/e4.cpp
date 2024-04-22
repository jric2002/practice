#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int contarRepeticiones(string, string);
int main(int argc, char *argv[]) {
  char nombre_archivo[] = "entrada.txt";
  fstream f(nombre_archivo, fstream::in);
  string cadena, sub_cadena;
  if (f.is_open()) {
    getline(f, cadena, '\n');
    getline(f, sub_cadena, '\n');
    cout << contarRepeticiones(cadena, sub_cadena) << endl;
    f.close();
  }
  else {
    cout << "No se puede abrir el archivo: " << nombre_archivo << endl;
  }
  return 0;
}
int contarRepeticiones(string c, string sc) {
  int contador = 0, pos = 0;
  while (true) {
    pos = c.find(sc);
    if (pos == string::npos) {
      break;
    }
    c = c.substr(pos + sc.size());
    contador++;
  }
  return contador;
}