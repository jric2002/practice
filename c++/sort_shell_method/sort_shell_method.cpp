#include <iostream>
#define largo 50
using namespace std;
void leeCadena(int n, int A[]) {
  for (int i = 0; i < n; i++) {
    cout << "A[" << i << "]: ";
    cin >> A[i];
  }
}
void ordenShell(int A[], int n) {
  int i, j, inc, temp;
  inc = n / 2;
  while (inc > 0) {
    for (i = inc; i < n; i++) {
      j = i;
      temp = A[i];
      while (j >= inc && A[j - inc] > temp) {
        A[j] = A[j - inc];
        j = j - inc;
      }
      A[j] = temp;
    }
    inc /= 2;
  }
}
void muestraCadena(int n, int A[]) {
  cout << "Numeros ordenados: ";
  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}
int main() {
  int A[largo], n;
  do {
    cout << "Cantidad de numeros a ingresar: ";
    cin >> n;
    if (n <= 0 || n > largo) {
      cout << "Debe ingresar un valor > a 0 y < a " << largo << endl;
    }
  } while(n <= 0 || n > largo);
  leeCadena(n, A);
  ordenShell(A, n);
  muestraCadena(n, A);
  return 0;
}