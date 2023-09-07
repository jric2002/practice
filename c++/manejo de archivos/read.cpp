#include <iostream>
#include <fstream>
#include <cstring>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main(int argc, char *argv[]) {
  char file_name[] = "example.txt";
  string line;
  int tl;
  ifstream f;
  f.open(file_name);
  if (f.is_open()) {
    tl = 0;
    while (getline(f, line, '\n')) {
      cout << line;
      tl++;
    }
    cout << "\ntotal lines: " << tl << endl;
    f.close();
  }
  else {
    cout << "No se puede abrir el archivo " << file_name << endl;
  }
  return 0;
}
/* Definition */