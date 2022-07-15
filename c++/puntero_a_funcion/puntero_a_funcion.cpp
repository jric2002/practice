#include <iostream>
#include <cstring>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
// Function prototype
int suma(int, int);
string saludo() {
  return "Hola, Jose";
}
int main() {
  typedef int INT;
  INT (*pf)(int, int);
  pf = suma;
  cout << "Suma: " << pf(5, 3) << endl;
  string (*pf_saludo)();
  pf_saludo = saludo;
  cout << "Saludo: " << pf_saludo() << endl;
  return 0;
}
/* Definition */
int suma(int a, int b) {
  return a + b;
}