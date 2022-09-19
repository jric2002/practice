#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <map>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
class Columna {
  public:
    map<int,string> c;
    void Insertar(int pos, string s) {
      c[pos] = s;
    }
    void Mostrar() {
      for (map<int, string>::iterator it = c.begin(); it != c.end(); it++) {
        cout << "(" << (*it).first << ")[" << (*it).second << "] ";
      }
      cout << endl;
    }
};
class Hoja {
  public:
    map<string, Columna> h;
    void Insertar(string c, int f, string s) {
      map<string, Columna>::iterator it = h.find(c);
      if (it != h.end()) {
        ((*it).second).Insertar(f, s);
      }
      else {
        Columna Col;
        Col.Insertar(f, s);
        h[c] = Col;
      }
    }
    void Mostrar() {
      for (map<string, Columna>::iterator it = h.begin(); it != h.end(); it++) {
        cout << "{" << (*it).first << "} -> ";
        ((*it).second).Mostrar();
      }
    }
};
int main() {
  /* Hoja h;
  h.Insertar("C", 5, "C cinco");
  h.Insertar("A", 15, "A quince");
  h.Insertar("E", 10, "E diez");
  h.Insertar("A", 15, "modificado");
  h.Mostrar(); */
  Columna c;
  c.Insertar(4, "5");
  c.Insertar(8, "Hola");
  c.Insertar(1, "10");
  c.Insertar(6, "5.5");
  c.Insertar(5000, "otro");
  c.Mostrar();
  map<int, string> t;
  t.insert(pair<int, string>(4, "b"));
  t.insert(pair<int, string>(1, "a"));
  t.insert(pair<int, string>(3, "d"));
  t.insert(pair<int, string>(2, "c"));
  for (map<int, string>::iterator it = t.begin(); it != t.end(); it++) {
    cout << (*it).first << " -> " << (*it).second << endl;
  }
  return 0;
}
/* Definition */