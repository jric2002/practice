#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Author: José Rodolfo (jric2002) */
/* Declaration */
int main(int argc, char *argv[]) {
  int n = 3;
  char *ns[n], name[100];
  for (int i = 0; i < n; i++) {
    scanf("%s", name);
    *(ns + i) = (char *)malloc(strlen(name) + sizeof(char));
    strcpy(*(ns + i), name);
  }
  for (int i = 0; i < n; i++) {
    printf("%i -> %s\n", strlen(*(ns + i)), ns[i]);
  }
  return 0;
}
/* Definition*/