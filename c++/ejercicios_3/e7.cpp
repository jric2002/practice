#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
  char nombre_archivo[] = "entrada.txt";
  fstream f(nombre_archivo, fstream::in);
  if (f.is_open()) {
    int n, t, v;
    f >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      f >> v;
      a.at(i) = v;
    }
    while (t--) {
      for (int v : a) {
        cout << v << " ";
      }
    }
    cout << endl;
    f.close();
  }
  else {
    cout << "No se puede abrir el archivo: " << nombre_archivo << endl;
  }
  return 0;
}