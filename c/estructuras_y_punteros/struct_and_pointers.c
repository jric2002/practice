#include <stdio.h>
#include <stdlib.h>
/* Author: José Rodolfo (jric2002) */
/* Declaration */
struct Node {
  int value;
  struct Node *next;
};
int main() {
  struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
  struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
  struct Node *n3 = (struct Node *)malloc(sizeof(struct Node));
  n1->value = 10;
  n2->value = 20;
  n3->value = 30;
  n1->next = n2;
  n2->next = n3;
  n3->next = NULL;
  struct Node *aux;
  aux = n1;
  while (aux != NULL) {
    printf("%i ", aux->value);
    aux = aux->next;
  }
  free(n1);
  free(n2);
  free(n3);
  return 0;
}
/* Definition */