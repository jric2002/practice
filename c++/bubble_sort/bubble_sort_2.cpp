#include <iostream>
#define largo 50
using namespace std;
void leeCadena(int n, int A[]) {
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
}
void seleccionsort(int A[], int n) {
  int min, i, j, aux;
  for (i = 0; i < (n - 1); i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (A[min] > A[j]) {
        min = j;
      }
      aux = A[min];
      A[min] = A[i];
      A[i] = aux;
    }
  }
}
void muestraCadena(int n, int A[]) {
  cout << "Array: ";
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
  seleccionsort(A, n);
  muestraCadena(n, A);
  return 0;
}