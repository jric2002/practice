#include <iostream>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main(int argc, char *argv[]) {
  int n = 3, m = 3, a = 1;
  int **tabla;
  tabla = new int*[n];
  for (int i = 0; i < n; i++) {
    *(tabla + i) = new int[m];
    // tabla[i] = new int[m];
    for (int j = 0; j < m; j++) {
      *(*(tabla + i) + j) = a;
      // tabla[i][j] = a;
      a += 2;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout.width(3);
      cout << tabla[i][j] << " ";
    }
    cout << endl;
  }
  for (int i = 0; i < n; i++) {
    delete[] tabla[i];
  }
  delete tabla;
  return 0;
}
/* Definition */