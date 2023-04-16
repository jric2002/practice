#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Author: José Rodolfo (jric2002) */
/* Declaration */
int main(int argc, char *argv[]) {
  int n = 3;
  char **pt;
  char name[100];
  pt = (char **)malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++) {
    scanf("%s", name);
    // Devuelve direccion de memoria con una cantidad de memoria reservada en tiempo de ejecucion
    *(pt + i) = (char *)malloc(strlen(name) * sizeof(char));
    // pt[i] = (char *)malloc(strlen(name) * sizeof(char));
    // strcpy() recibe direccion de memoria en la cual se hizo la asignacion dinamica de memoria
    strcpy(*(pt + i), name);
  }
  for (int i = 0; i < n; i++) {
    printf("%i -> %s\n", strlen(*(pt + i)), *(pt + i));
  }
  // Freeing memory
  for (int i = 0; i < n; i++) {
    free(*(pt + i));
    *(pt + i) = NULL;
  }
  free(pt);
  pt = NULL;
  printf("--------------------------\n");
  for (int i = 0; i < n; i++) {
    printf("%i -> %s\n", strlen(*(pt + i)), *(pt + i));
  }
  printf("Done...\n");
  return 0;
}
/* Definition */