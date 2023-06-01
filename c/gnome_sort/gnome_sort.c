#include <stdio.h>
#define largo 100
void leeCadena(int n, int A[]) {
  for (int i = 0; i < n; i++) {
    printf("A[%i]: ", i);
    scanf("%i", &A[i]);
  }
}
void gnomesort(int A[], int n) {
  int i, temp;
  i = 1;
  while (i <= (n - 1)) {
    if (A[i - 1] <= A[i]) {
      i = i + 1;
    }
    else {
      temp = A[i - 1];
      A[i - 1] = A[i];
      A[i] = temp;
      i = i - 1;
      if (i == 0) {
        i = 1;
      }
    }
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
  printf("Algoritmo de ordenamiento Gnome sort\n");
  do {
    printf("Cantidad de numeros a ingresar: ");
    scanf("%i", &n);
    if (n <= 0 || n > largo) {
      printf("Debe ingresar un valor > a 0 y < a %i\n", largo);
    }
  } while(n <= 0 || n > largo);
  leeCadena(n, A);
  gnomesort(A, n);
  muestraCadena(n, A);
  return 0;
}