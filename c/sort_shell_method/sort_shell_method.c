#include <stdio.h>
#define largo 50
void leeCadena(int n, int A[]) {
  for (int i = 0; i < n; i++) {
    printf("A[%i]: ", i);
    scanf("%i", &A[i]);
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
  printf("Numeros ordenados: ");
  for (int i = 0; i < n; i++) {
    printf("%i ", A[i]);
  }
  printf("\n");
}
int main() {
  int A[largo], n;
  printf("Algoritmo de ordenamiento shell\n");
  do {
    printf("Cantidad de numeros a ingresar: ");
    scanf("%i", &n);
    if (n <= 0 || n > largo) {
      printf("Debe ingresar un valor > a 0 y < a %i\n", largo);
    }
  } while(n <= 0 || n > largo);
  leeCadena(n, A);
  ordenShell(A, n);
  muestraCadena(n, A);
  return 0;
}