#include <iostream>
// Metodo agrupamiento
using namespace std;
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
  cout << "Metodo agrupamiento" << endl;
  cout << "suma: " << suma << endl;
  cout.width(20);
  cout.fill('=');
  cout << "" << endl;
  cout << "SIN metodo agrupamiento" << endl;
  suma = 1;
  for (int i = 1; i <= 10000; i++) {
    suma = suma + 0.00001;
  }
  cout << "suma: " << suma << endl;
  return 0;
}