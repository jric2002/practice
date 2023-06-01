#include <iostream>
// Doble precision [McCracken]
using namespace std;
int main() {
  double suma = 1;
  for (int i = 1; i <= 10000; i++) {
    suma = suma + 0.00001;
  }
  cout << "Doble precision [McCracken]" << endl;
  cout << "suma: " << suma << endl;
  return 0;
}