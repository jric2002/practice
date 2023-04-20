#include <iostream>
#include <fstream>
#include <cstring>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main(int argc, char *argv[]) {
  char file_name[] = "example.txt";
  string s;
  int t;
  fstream f;
  f.open(file_name, fstream::in); // fstream::in | std::fstream::out | std::fstream::app
  if (f.is_open()) {
    t = 0;
    while(getline(f, s, '\n')) {
      cout << s;
      t++;
    }
    cout << endl;
    cout << "t: " << t << endl;
    f.close();
  }
  else {
    cout << "No se puede abrir el archivo " << file_name << endl;
  }
  return 0;
}
/* Definition */