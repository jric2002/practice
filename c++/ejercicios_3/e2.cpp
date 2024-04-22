#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <utility>
#include <map>
using namespace std;
float calcularX(map<string, pair<int, int>> *sr, float sr_m, int y) {
  return ((*sr)["p1"].second - (sr_m * (*sr)["p1"].first) - y)/sr_m;
}
float calcularY(map<string, pair<int, int>> *sr, float sr_m, int x) {
  return ((sr_m * (x - (*sr)["p1"].first)) + (*sr)["p1"].second);
}
int main(int argc, char *argv[]) {
  char nombre_archivo[] = "entrada.txt";
  fstream f(nombre_archivo, fstream::in);
  string s;
  stringstream ss;
  int n, x, y;
  float l1, l2, l3, l4, sr_m;
  bool rest_l1, rest_l2, rest_l3, rest_l4;
  map<string, pair<int, int>> seg_recta, rectangulo;
  if (f.is_open()) {
    getline(f, s, '\n');
    n = stoi(s);
    while (n--) {
      getline(f, s, '\n');
      ss << s;
      ss >> x;
      ss >> y;
      seg_recta["p1"] = make_pair(x, y);
      ss >> x;
      ss >> y;
      seg_recta["p2"] = make_pair(x, y);
      ss >> x;
      ss >> y;
      rectangulo["p1"] = make_pair(x, y);
      ss >> x;
      ss >> y;
      rectangulo["p2"] = make_pair(x, y);
      // Pendiente del segmento de recta
      sr_m = (seg_recta["p2"].second - seg_recta["p1"].second)/(float)(seg_recta["p2"].first - seg_recta["p1"].first);
      // L1, L2, L3, L4 con restricciones, conforman el rectangulo
      l1 = calcularX(&seg_recta, sr_m, rectangulo["p1"].second); // L1 : y = p1.y , p1.x <= x <= p2.x
      l2 = calcularY(&seg_recta, sr_m, rectangulo["p2"].first); // L2 : x = p2.x , p2.y <= y <= p1.y
      l3 = calcularX(&seg_recta, sr_m, rectangulo["p2"].second); // L3 : y = p2.y , p1.x <= x <= p2.x
      l4 = calcularY(&seg_recta, sr_m, rectangulo["p1"].first); // L4 : x = p1.x , p2.y <= y <= p1.y
      rest_l1 = l1 >= rectangulo["p1"].first && l1 <= rectangulo["p2"].first;
      rest_l2 = l2 >= rectangulo["p2"].second && l2 <= rectangulo["p1"].second;
      rest_l3 = l3 >= rectangulo["p1"].first && l3 <= rectangulo["p2"].first;
      rest_l4 = l4 >= rectangulo["p2"].second && l4 <= rectangulo["p1"].second;
      if (rest_l1 || rest_l2 || rest_l3 || rest_l4) {
        cout << "Si" << endl;
      }
      else {
        cout << "No" << endl;
      }
      ss.clear();
    }
    f.close();
  }
  else {
    cout << "No se puede abrir el archivo: " << nombre_archivo << endl;
  }
  return 0;
}