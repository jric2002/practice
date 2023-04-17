#include <stdio.h>
#include <string.h>
#define A 99
#define B 200
#define C 105
#define FN 797
#define ERROR 17
char cad[100];
int i;
int getToken() {
  while (cad[i] == ' ' || cad[i] == '\t' || cad[i] == '\n') {
    i++;
  }
  if (cad[i] == 'a') {
    i++;
    return A;
  }
  else if (cad[i] == 'b') {
    i++;
    return B;
  }
  else if (cad[i] == 'c') {
    i++;
    return C;
  }
  else if (cad[i] == '\0') {
    i++;
    return FN;
  }
  else {
    i++;
    return ERROR;
  }
}
bool lexico() {
  int token = 0;
  while (token != FN) {
    token = getToken();
    if (token == ERROR) {
      printf("No se reconoce el caracter '%c' en la posicion %i\n", cad[i - 1], (i - 1));
      return false;
    }
  }
  return true;
}
int main(int argc, char *argv[]) {
  char file_name[] = "code.txt";
  char c;
  FILE *f = fopen(file_name, "r");
  if (f != NULL) {
    while ((c = fgetc(f)) != EOF) {
      strncat(cad, &c, 1);
    }
    fclose(f);
  }
  else {
    printf("No se puede abrir el archivo %s\n", file_name);
  }
  printf("%s\n", cad);
  i = 0;
  printf("Estado %i\n", lexico());
  return 0;
}