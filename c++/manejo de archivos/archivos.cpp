#include <iostream>
#include <fstream>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main(int argc, char *argv[]) {
  char file_name[] = "example.txt";
  char c;
  int tc;
  ifstream f;
  f.open(file_name);
  if (f.is_open()) {
    tc = 0;
    while (f.get(c)) {
      cout << c;
      //cout << static_cast<int>(c);
      tc++;
    }
    cout << "\ntotal chars: " << tc << endl;
    f.close();
  }
  else {
    cout << "No se puede abrir el archivo " << file_name << endl;
  }
  return 0;
}
/* Definition */