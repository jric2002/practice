#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
  char file_name[] = "example.txt";
  ofstream f;
  f.open(file_name);
  if (f.is_open()) {
    f << "ab  a\n\tabc\nab c";
    f.close();
  }
  else {
    cout << "No se puede abrir el archivo " << file_name << endl;
  }
  return 0;
}