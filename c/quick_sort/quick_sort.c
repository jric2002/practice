#include <stdio.h>
#define largo 100
void leeCadena(int n, int A[]) {
  for (int i = 0; i < n; i++) {
    printf("A[%i]: ", i);
    scanf("%i", &A[i]);
  }
}
void quicksort(int A[], int izq, int der) {
  int i, j, x, aux;
  i = izq;
  j = der;
  x = A[(izq + der) / 2];
  do {
    while ((A[i] < x) && (j <= der)) {
      i++;
    }
    while ((x < A[j]) &&(j > izq)) {
      j--;
    }
    if (i <= j) {
      aux = A[i];
      A[i] = A[j];
      A[j] = aux;
      i++;
      j--;
    }
  } while (i <= j);
  if (izq < j) {
    quicksort(A, izq, j);
  }
  if (i < der) {
    quicksort(A, i, der);
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
  printf("Algoritmo de ordenamiento Quick sort\n");
  do {
    printf("Cantidad de numeros a ingresar: ");
    scanf("%i", &n);
    if (n <= 0 || n > largo) {
      printf("Debe ingresar un valor > a 0 y < a %i\n", largo);
    }
  } while(n <= 0 || n > largo);
  leeCadena(n, A);
  quicksort(A, 0, n - 1);
  muestraCadena(n, A);
  return 0;
}