#include <iostream>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  int n = 5, m = 3;
  int **tabla;
  tabla = new int*[n];
  int a = 0;
  for (int i = 0; i < n; i++) {
    tabla[i] = new int[m];
    for (int j = 0; j < m; j++) {
      tabla[i][j] = a;
      a += 2;
      cout << "numero: " << tabla[i][j] << endl;
    }
  }
  for (int i = 0; i < n; i++) {
    delete[] tabla[i];
  }
  delete tabla;
  return 0;
}
/* Definition */