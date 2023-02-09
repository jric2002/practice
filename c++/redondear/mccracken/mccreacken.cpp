#include <iostream>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  double suma = 0;
  for (int i = 1; i <= 10000; i++) {
    suma = suma + 0.00001;
  }
  cout << "suma: " << suma << endl;
  return 0;
}
/* Definition */