#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main(int argc, char *argv[]) {
  char file_name[] = "example.txt";
  char c;
  string s;
  ofstream f;
  f.open(file_name);
  if (f.is_open()) {
    while (true) {
      c = cin.get();
      if (c != '.') {
        f.put(c);
      }
      else {
        break;
      }
    }
    s = "ab bc\n\tabc a\nab c a";
    f.write(s.c_str(), s.size());
    f.close();
  }
  else {
    cout << "No se puede abrir el archivo " << file_name << endl;
  }
  return 0;
}