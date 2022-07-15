#include <stdio.h>
/* Author: José Rodolfo (jric2002) */
/* Declaration */
struct Node {
  int value;
  struct Nodo *next;
};
int main() {
  struct Node n1 = {5, NULL};
  printf("%i", n1.value);
  return 0;
}
/* Definition */