#include <iostream>
#include <vector>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  int n;
  double x, y;
  vector<pair<double, double>> datos;
  datos.push_back(make_pair());
  cout << "AJUSTE DE CURVAS" << endl;
  cout.width(10);
  cout.fill('-');
  cout << "" << endl;
  cout << "[+] Regresion lineal simple" << endl;
  cout << "Ingrese la cantidad de datos: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << (i + 1) << " dato: ";
    cin >> x >> y;
    datos.push_back(make_pair(x, y));
  }
  return 0;
}
/* Definition */