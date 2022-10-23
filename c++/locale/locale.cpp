#include <iostream>
#include <cstring>
#include <clocale>
//#include <windows.h>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  string name;
  name = "José Rodolfo";
  cout << name << endl;
  setlocale(LC_ALL, "");
  cout << name << endl;
  //SetConsoleCP(1252);
  //SetConsoleOutputCP(1252);
  return 0;
}
/* Definition */