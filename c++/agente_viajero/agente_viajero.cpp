#include <iostream>
#include <algorithm>
#include <vector>
/* Author: José Rodolfo */
using namespace std;
struct Ruta {
  vector<int> p;
  int costo;
};
int main() {
  int n, i, j;
  int ciudades[] = {0, 1, 2, 3}; // ciudades
  n = sizeof(ciudades) / sizeof(int); // numero de ciudades
  int costo;
  vector<vector<int>> tabla_costos(n);
  tabla_costos.at(0) = {0, 3, 4, 2};
  tabla_costos.at(1) = {3, 0, 1, 5};
  tabla_costos.at(2) = {4, 1, 0, 2};
  tabla_costos.at(3) = {2, 5, 2, 0};
  vector<int> pos_mr; // posición de las mejores rutas
  int min_costo = 0;
  int cantidad_permutaciones = (n - 1) * 2;
  struct Ruta rs[cantidad_permutaciones]; // rutas
  cout << "Permutaciones" << endl;
  cout.width(25);
  cout << cout.fill('-') << endl;
  // Realiza permutaciones
  j = 0;
  do {
    costo = 0;
    i = 0;
    while (i < n) {
      rs[j].p.push_back(ciudades[i]);
      if (i < (n - 1)) {
        costo += tabla_costos[ciudades[i]][ciudades[i + 1]];
      }
      else {
        costo += tabla_costos[ciudades[i]][0];
      }
      cout << ciudades[i] << " ";
      i++;
    }
    if (j == 0) {
      min_costo = costo;
    }
    if (min_costo > costo) {
      min_costo = costo;
    }
    rs[j].p.push_back(ciudades[0]);
    rs[j].costo = costo;
    cout << ciudades[0] << " -> costo: " << costo << endl;
    j++;
  } while (next_permutation(ciudades + 1, ciudades + n));
  // Buscar las rutas con minimo costo
  for (int i = 0; i < cantidad_permutaciones; i++) {
    if (min_costo == rs[i].costo) {
      pos_mr.push_back(i);
    }
  }
  // Imprimir las mejores rutas
  cout << endl << "Mejores rutas" << endl;
  cout.width(25);
  cout << cout.fill('-') << endl;
  for (int i = 0; i < pos_mr.size(); i++) {
    for (auto c : rs[pos_mr[i]].p) {
      cout << c << " ";
    }
    cout << " -> costo: " << rs[pos_mr[i]].costo << endl;
  }
  cout << "Minimo costo: " << min_costo << endl;
  return 0;
}