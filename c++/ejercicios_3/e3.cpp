#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
  char nombre_archivo[] = "entrada.txt";
  fstream f(nombre_archivo, fstream::in);
  int n;
  if (f.is_open()) {
    vector<int> a;
    while (f >> n) {
      a.push_back(n);
    }
    vector<vector<int>> series;
    vector<int> posiciones;
    vector<int>::iterator s = a.begin(), c = a.begin() + 1;
    while (c != a.end()) {
      if (*c < *(c - 1)) {
        series.push_back(vector<int>(s, c));
        s = c;
      }
      c++;
    }
    series.push_back(vector<int>(s, c));
    for (vector<int> s : series) {
      posiciones.push_back(find(a.begin(), a.end(), s.at(0)) - a.begin());
      cout << "serie: ";
      for (int n : s) {
        cout << n << " ";
      }
      cout << endl;
    }
    cout << "posiciones: ";
    for (int p : posiciones) {
      cout << p << " ";
    }
    cout << endl;
    f.close();
  }
  else {
    cout << "No se puede abrir el archivo: " << nombre_archivo << endl;
  }
  return 0;
}