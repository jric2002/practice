#include <iostream>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
// Function prototype
int suma(int, int);
int main() {
  typedef int INT;
  INT (*pf)(int, int);
  pf = suma;
  cout << pf(5, 3) << endl;
  return 0;
}
/* Definition */
int suma(int a, int b) {
  return a + b;
}