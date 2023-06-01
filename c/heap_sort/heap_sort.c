#include <stdio.h>
#define largo 100
void leeCadena(int n, int A[]) {
  for (int i = 0; i < n; i++) {
    printf("A[%i]: ", i);
    scanf("%i", &A[i]);
  }
}
void heapsort(int A[], int n) {
  int item, temp, i, j, k;
  for (k = n - 1; k >= 0; k--) {
    for (i = 0; i <= k; i++) {
      item = A[i];
      j = (i + 1)/2 - 1;
      while (j >= 0 && A[j] < item) {
        A[i] = A[j];
        i = j;
        j = (j + 1)/2 - 1;
      }
      A[i] = item;
    }
    temp = A[0];
    A[0] = A[k];
    A[k] = temp;
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
  printf("Algoritmo de ordenamiento Heap sort\n");
  do {
    printf("Cantidad de numeros a ingresar: ");
    scanf("%i", &n);
    if (n <= 0 || n > largo) {
      printf("Debe ingresar un valor > a 0 y < a %i\n", largo);
    }
  } while(n <= 0 || n > largo);
  leeCadena(n, A);
  heapsort(A, n);
  muestraCadena(n, A);
  return 0;
}