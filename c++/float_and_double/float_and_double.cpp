#include <iostream>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  float a = 2.12345678901;
  double b = 2.123456789123456789;
  cout.setf(ios::fixed);
  cout.precision(11);
  cout << "a: " << a << endl;
  cout.precision(18);
  cout << "b: " << b << endl;
  cout.unsetf(ios::fixed);
  return 0;
}
/* Definition */