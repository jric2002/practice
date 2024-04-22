#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main(int argc, char *argv[]) {
  char nombre_archivo[] = "entrada.txt";
  fstream f(nombre_archivo, fstream::in);
  string s;
  int n, hojas;
  if (f.is_open()) {
    getline(f, s, '\n');
    n = stoi(s);
    while (n--) {
      getline(f, s, '\n');
      hojas = stoi(s);
      if (hojas < 3) {
        cout << "IMPOSIBLE" << endl;
      }
      else {
        cout << hojas/4 << endl;
      }
    }
    f.close();
  }
  else {
    cout << "No se puede abrir el archivo: " << nombre_archivo << endl;
  }
  return 0;
}