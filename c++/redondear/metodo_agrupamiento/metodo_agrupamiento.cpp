#include <iostream>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  float suma, total;
  suma = 1;
  for (int i = 1; i <= 100; i++) {
    total = 0;
    for (int j = 1; j <= 100; j++) {
      total += 0.00001;
    }
    suma += total;
  }
  cout << "suma: " << suma << endl;
  return 0;
}
/* Definition */