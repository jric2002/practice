#include <iostream>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  int n = 10; // cantidad de numeros
  int b = 0, a = 1, f;
  for (int i = 0; i < n; i++) {
    f = b + a;
    cout << f << " ";
    b = a;
    a = f;
  }
  return 0;
}
/* Definition */