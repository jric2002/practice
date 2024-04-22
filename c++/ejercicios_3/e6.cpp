#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(int argc, char *argv[]) {
  char nombre_archivo[] = "entrada.txt";
  fstream f(nombre_archivo, fstream::in | fstream::out | fstream::trunc);
  if (f.is_open()) {
    vector<int> edades;
    map<int, int> frecuencia;
    map<int, int>::iterator it;
    srand(time(NULL));
    int n = 20, e, min_edad = 15, max_edad = 25, moda;
    while(n--) {
      e = (rand() % (max_edad - min_edad + 1)) + min_edad;
      cout << e << " ";
      edades.push_back(e);
      f << e;
      if (n != 0) {
        f << " ";
      }
    }
    cout << endl;
    for (int e : edades) {
      frecuencia[e]++;
    }
    it = max_element(frecuencia.begin(), frecuencia.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
      return a.second < b.second;
    });
    if (it->second == 1) {
      cout << "No hay moda" << endl;
    }
    else {
      moda = it->first;
      cout << "Moda: " << moda << endl;
    }
    f.close();
  }
  else {
    cout << "No se puede abrir el archivo: " << nombre_archivo << endl;
  }
  return 0;
}