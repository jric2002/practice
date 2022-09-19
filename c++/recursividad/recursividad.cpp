#include <iostream>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
void saludo(int);
int main() {
  int n = 5;
  saludo(n);
  return 0;
}
/* Definition */
void saludo(int i) {
  if (i > 0) {
    cout << "Before: " << i << endl;
    saludo(i - 1);
    cout << "After: " << i << endl;
  }
}