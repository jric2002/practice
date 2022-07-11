#include <iostream>
#include <string>
#include <fstream>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  const string file_name = "example.txt";
  string line;
  ifstream file(file_name.c_str());
  if (file.is_open()) {
    while (!file.eof()) {
      getline(file, line);
      cout << line << endl;
    }
    file.close();
  }
  else {
    cout << "No se puede abrir el archivo" << endl;
  }
  return 0;
}
/* Definition */