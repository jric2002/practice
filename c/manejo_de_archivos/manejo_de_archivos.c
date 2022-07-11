#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Author: José Rodolfo (jric2002) */
/* Declaration */
int main() {
  FILE *fp;
  fp = fopen("example.txt", "r");
  if (fp != NULL) {
    while (!feof(fp)) {
      printf("%c", fgetc(fp));
    }
    fclose(fp);
  }
  else {
    printf("error to open file");
  }
  return 0;
}
/* Definition */