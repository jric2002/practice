#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Author: José Rodolfo (jric2002) */
/* Declaration */
int main() {
  char *p;
  p = (char *)malloc(4 * sizeof(char));
  *(p) = 'h';
  *(p + 1) = 'o';
  *(p + 2) = 'l';
  *(p + 3) = 'a';
  for (int i = 0; i < 4; i++) {
    printf("%c", *(p + i));
  }
  printf("\n");
  free(p);
  p = NULL;
  return 0;
}
/* Definition */