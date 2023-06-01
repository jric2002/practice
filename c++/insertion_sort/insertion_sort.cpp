#include <iostream>
#define largo 50
using namespace std;
void leeCadena(int n, int A[]) {
  for (int i = 0; i < n; i++) {
    cout << "A[" << i << "]: ";
    cin >> A[i];
  }
}
void insercionDirecta(int A[], int n) {
  int i, j, v;
  for (i = 1; i < n; i++) {
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
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
  insercionDirecta(A, n);
  muestraCadena(n, A);
  return 0;
}