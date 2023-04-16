#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  int **pt;
  pt = (int **)malloc(sizeof(int *));
  *pt = (int *)malloc(sizeof(int));
  **pt = 124;
  printf("Addr pt: %p\n", &pt);
  printf("Val pt: %p\n", pt);
  printf("*pt: %p\n", *pt);
  printf("**pt: %i\n", **pt);
  free(*pt);
  free(pt);
  printf("Done...\n");
  return 0;
}