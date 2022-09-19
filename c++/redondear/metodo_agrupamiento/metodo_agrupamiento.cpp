#include <iostream>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  float suma, temp;
  int n = 10000;
  suma = 1;
  for (int i = 0; i < 100; i++) {
    temp = 0;
    for (int j = 0; j < 100; j++) {
      temp += 0.00001;
    }
    suma += temp;
  }
  cout << suma << endl;
  return 0;
}
/* Definition */