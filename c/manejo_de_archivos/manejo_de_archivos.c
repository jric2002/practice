#include <stdio.h>
/* Author: José Rodolfo (jric2002) */
/* Declaration */
int main(int argc, char *argv[]) {
  char file_name[] = "example.txt";
  FILE *f = fopen(file_name, "r");
  int c, tc;
  if (f != NULL) {
    tc = 0;
    while ((c = fgetc(f)) != EOF) {
      printf("%c", c);
      tc++;
    }
    printf("\n");
    if (feof(f)) {
      printf("tc: %i", tc);
    }
    fclose(f);
  }
  else {
    printf("Cannot open the file %s\n", file_name);
  }
  return 0;
}
/* Definition */