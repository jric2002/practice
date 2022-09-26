#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  double x, y, x1, y1, x2, y2;
  vector<pair<double, double>> datos;
  datos.push_back(make_pair(250, 1.003));
  datos.push_back(make_pair(300, 1.005));
  datos.push_back(make_pair(350, 1.008));
  datos.push_back(make_pair(400, 1.013));
  datos.push_back(make_pair(450, 1.020));
  datos.push_back(make_pair(500, 1.029));
  datos.push_back(make_pair(550, 1.040));
  datos.push_back(make_pair(600, 1.051));
  datos.push_back(make_pair(650, 1.063));
  datos.push_back(make_pair(700, 1.075));
  datos.push_back(make_pair(750, 1.087));
  datos.push_back(make_pair(800, 1.099));
  datos.push_back(make_pair(900, 1.121));
  datos.push_back(make_pair(1000, 1.142));
  sort(datos.begin(), datos.end(), [](pair<double, double> a, pair<double, double> b) -> bool {
    return (a.first < b.first);
  });
  cout.setf(ios::fixed);
  cout << "Datos" << endl;
  cout.width(6);
  cout.fill('-');
  cout << "" << endl;
  for (pair<double, double> d : datos) {
    cout.precision(0);
    cout << d.first;
    cout.precision(3);
    cout << " -> " << d.second << endl;
  }
  cout << endl;
  cout << "Ingresa un valor para 'x': ";
  cin >> x;
  for (int i = 0; i < datos.size(); i++) {
    if (datos.at(i).first > x) {
      x2 = datos.at(i).first;
      y2 = datos.at(i).second;
      x1 = datos.at(i - 1).first;
      y1 = datos.at(i - 1).second;
      break;
    }
  }
  y = (((x - x1) / (x2 - x1)) * (y2 - y1)) + y1;
  cout.precision(0);
  cout << "x1: " << x1;
  cout.precision(3);
  cout << "\t\ty1: " << y1 << endl;
  cout.precision(0);
  cout << "x2: " << x2;
  cout.precision(3);
  cout << "\t\ty2: " << y2 << endl;
  cout.precision(4);
  cout << "Valor de 'y' es: " << y << endl;
  cout.unsetf(ios::fixed);
  return 0;
}
/* Definition */