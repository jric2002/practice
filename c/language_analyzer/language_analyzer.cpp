#include <stdio.h>
#include <string.h>
#define A 99
#define B 200
#define C 105
#define FIN 797
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
    return FIN;
  }
  else {
    i++;
    return ERROR;
  }
}
bool lexico() {
  int token = 0;
  i = 0;
  while (token != FIN) {
    token = getToken();
    if (token == ERROR) {
      printf("No se reconoce el caracter '%c' en la posicion %i\n", cad[i - 1], (i - 1));
      return false;
    }
  }
  return true;
}
int sintactico() {
  int token = 0;
  int estado = 0;
  i = 0;
  while(true) {
    token = getToken();
    printf("estado: %i\ttoken: %c\n", estado, cad[i-1]);
    if (token == FIN) {
      break;
    }
    if (estado == 0) {
      if (token == A || token == C) {
        estado = 1;
      }
      else {
        printf("Te recomiendo usar estos caracteres 'a', 'c'\n");
        return false;
      }
    }
    else if (estado == 1) {
      if (token == A) {
        estado = 1;
      }
      else if (token == C) {
        estado = 2;
      }
      else if (token == B) {
        estado = 3;
      }
      else {
        printf("Te recomiendo usar estos caracteres 'a', 'b', 'c'\n");
        return false;
      }
    }
    else if (estado == 2) {
      if (token == A) {
        estado = 3;
      }
      else if (token == B) {
        estado = 2;
      }
      else {
        printf("Te recomiendo usar estos caracteres 'a', 'b'\n");
        return false;
      }
    }
    else {
      printf("Error: Este caracter esta mal ubicado '%c'\n", cad[i-1]);
      return false;
    }
  }
  if (estado == 3) {
    return true;
  }
  else {
    printf("'%c' en el estado %i\n", cad[i], estado);
    return false;
  }
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
  printf("Content:\n%s\n", cad);
  if (lexico()) {
    printf("Sintactico: %i\n", sintactico());
  }
  return 0;
}