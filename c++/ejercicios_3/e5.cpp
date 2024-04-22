#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
  char nombre_archivo[] = "entrada.txt";
  fstream f(nombre_archivo, fstream::in);
  if (f.is_open()) {
    int n;
    vector<int> a;
    while (f >> n) {
      a.push_back(n);
    }
    reverse(a.begin(), a.end());
    for (int n : a) {
      cout << n << " ";
    }
    cout << endl;
    f.close();
  }
  else {
    cout << "No se puede abrir el archivo: " << nombre_archivo << endl;
  }
  return 0;
}