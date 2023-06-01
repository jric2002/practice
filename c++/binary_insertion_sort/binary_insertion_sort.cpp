#include <iostream>
#define largo 50
using namespace std;
void leeCadena(int n, int A[]) {
  for (int i = 0; i < n; i++) {
    cout << "A[" << i << "]: ";
    cin >> A[i];
  }
}
void insercionBinaria(int A[], int n) {
  int i, j, izq, der, m, aux;
  for (i = 1; i < n; i++) {
    aux = A[i];
    izq = 0;
    der = i - 1;
    while (izq <= der) {
      m = (izq + der) / 2;
      if (aux < A[m]) {
        der = m - 1;
      }
      else {
        izq = m + 1;
      }
    }
    j = i - 1;
    while (j >= izq) {
      A[j + 1] = A[j];
      j = j - 1;
    }
    A[izq] = aux;
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
  insercionBinaria(A, n);
  muestraCadena(n, A);
  return 0;
}