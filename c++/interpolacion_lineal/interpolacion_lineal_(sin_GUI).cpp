#include <iostream>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  double x, y, x1, y1, x2, y2;
  x = 420;
  x1 = 400;
  y1 = 1.013;
  x2 = 450;
  y2 = 1.020;
  y = y1 + (((y2 - y1) * (x - x1)) / (x2 - x1));
  cout << y << endl;
  return 0;
}
/* Definition */