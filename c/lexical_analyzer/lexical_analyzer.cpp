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
  while (cad[i] == ' ' || cad[i] == '\t') {
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
      cout << "No se reconoce el caracter " <<
      "'" << cad[i - 1] << "'" <<
      " en la posicion " << (i - 1) << endl;
      return false;
    }
  }
  return true;
}
int main(int argc, char *argv[]) {
  char file_name[] = "code.txt";
  FILE *f = fopen(file_name, "r");
  if (f != NULL) {
    fclose(f);
  }
  else {
    cout << "Cannot open the file " << file_name << endl;
  }
  return 0;
}