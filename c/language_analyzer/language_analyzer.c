#include <stdio.h>
#include <string.h>
#include <stdbool.h>  
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
  i = 0;
  int token = 0;
  while (token != FIN) {
    token = getToken();
    if (token == ERROR) {
      printf("No se reconoce el caracter '%c' en la posicion %i\n", cad[i - 1], (i - 1));
      return false;
    }
  }
  return true;
}
bool sintactico() {
  i = 0;
  int token = 0;
  int estado = 0;
  while (true) {
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
      else if (token == B) {
        estado = 3;
      }
      else if (token == C) {
        estado = 2;
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
bool semantico() {
  i = 0;
  int token = 0, token_ant = 0, cont = 0;
  int ca = 0, cb = 0, cc = 0;
  while (true) {
    token = getToken();
    if (token == FIN) {
      break;
    }
    if (token == token_ant) {
      cont++;
    }
    else {
      cont = 0;
    }
    token_ant = token;
    if (cont == 3) {
      printf("ERROR: Pusiste mas de '%c' juntas permitidas.\n", cad[i - 1]);
      return false;
    }
    if (token == A) {
      ca++;
    }
    if (token == B) {
      cb++;
    }
    if (token == C) {
      cc++;
    }
    if (ca > 4) {
      printf("ERROR a\n");
      return false;
    }
    if (cb > 4) {
      printf("ERROR b\n");
      return false;
    }
    if (cc > 4) {
      printf("ERROR c\n");
      return false;
    }
  }
  return true;
}
void ejecucion() {
  i = 0;
  int token = 0;
  while (true) {
    token = getToken();
    if (token == FIN) {
      break;
    }
    if (token == A) {
      printf("Vocal\n");
    }
    if (token == B) {
      printf("Consonante\n");
    }
    if (token == C) {
      printf("Numero\n");
    }
  }
}
int main(int argc, char *argv[]) {
  char file_name[] = "code.txt";
  bool res;
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
  printf("[+] Content: \n%s\n", cad);
  res = lexico();
  printf("[+] Analisis Lexico: ");
  if (res) {
    printf("OK\n");
    res = sintactico();
    printf("[+] Analisis Sintactico: ");
    if (res) {
      printf("OK\n");
      res = semantico();
      printf("[+] Analisis Semantico: ");
      if (res) {
        printf("OK\n");
        ejecucion();
      }
      else {
        printf("WRONG\n");
      }
    }
    else {
      printf("WRONG\n");
    }
  }
  else {
    printf("WRONG\n");
  }
  return 0;
}