#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;
/* Declaration */
template <typename H, typename C>
void printTable(vector<H>, vector<pair<C, C>>, char);
int main() {
  int n;
  double gx, li, x, y;
  vector<string> header(2, "");
  header.at(0) = "x";
  header.at(1) = "f(x)";
  vector<pair<double, double>> datos;
  cout << "INTERPOLACION DE LAGRANGE" << endl;
  cout.width(25);
  cout.fill('=');
  cout << "" << endl;
  cout << "[+] Ingresa la cantidad de datos: ";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << i << " dato: ";
    cin >> x >> y;
    datos.push_back(make_pair(x, y));
  }
  cout << "[+] Ingresa el valor de 'x' para calcular g(x): ";
  cin >> x;
  printTable(header, datos, 'l');
  gx = 0;
  for (int j = 0; j < n; j++) {
    li = 1;
    for (int i = 0; i < n; i++) {
      if (i != j) {
        li = li * (x - datos.at(i).first)/(datos.at(j).first - datos.at(i).first);
      }
    }
    gx = gx + (li * datos.at(j).second);
  }
  cout.setf(ios::fixed);
  cout.precision(3);
  cout << "[+] El resultado de g(" << x;
  cout.precision(10);
  cout << ") es: " << gx << endl;
  cout.unsetf(ios::fixed);
  return 0;
}
/* Definition */
template <typename H, typename C>
void printTable(vector<H> header, vector<pair<C, C>> datos, char align) {
  // Buscar ancho maximo para cada columna
  vector<int> max_width(header.size());
  for (int c = 0; c < header.size(); c++) {
    max_width.at(c) = (header.at(c)).size();
  }
  string number;
  for (int c = 0; c < header.size(); c++) {
    for (int r = 0; r < datos.size(); r++) {
      number = to_string((datos.at(r)).first);
      if (max_width.at(c) < number.size()) {
        max_width.at(c) = number.size();
      }
    }
  }
  // Imprimir tabla de datos
  char horizontal_edge, vertical_edge, corner;
  horizontal_edge = '-';
  vertical_edge = '|';
  corner = '+';
  if (align == 'r') {
    cout << right;
  }
  else {
    cout << left;
  }
  cout.fill(' ');
  for (int c = 0; c < header.size(); c++) {
    cout << corner;
    for (int i = 0; i < max_width.at(c); i++) {
      cout << horizontal_edge;
    }
  }
  cout << corner << endl;
  for (int c = 0; c < header.size(); c++) {
    cout << vertical_edge;
    cout.width(max_width.at(c));
    cout << header.at(c);
  }
  cout << vertical_edge << endl;
  for (int c = 0; c < header.size(); c++) {
    cout << corner;
    for (int i = 0; i < max_width.at(c); i++) {
      cout << horizontal_edge;
    }
  }
  cout << corner << endl;
  for (int r = 0; r < datos.size(); r++) {
    cout << vertical_edge;
    cout.width(max_width.at(0));
    cout << datos.at(r).first;
    cout << vertical_edge;
    cout.width(max_width.at(1));
    cout << datos.at(r).second;
    cout << vertical_edge << endl;
  }
  for (int c = 0; c < header.size(); c++) {
    cout << corner;
    for (int i = 0; i < max_width.at(c); i++) {
      cout << horizontal_edge;
    }
  }
  cout << corner << endl;
}