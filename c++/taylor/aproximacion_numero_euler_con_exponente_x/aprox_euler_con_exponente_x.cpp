#include <iostream>
#include <cmath>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
double factorial(int);
int main() {
  int x, n;
  double euler_approx;
  cout << "Approximation of Euler's number" << endl;
  cout << "with exponent \"x\" using the Taylor series" << endl;
  cout.width(41);
  cout.fill('-');
  cout << "" << endl;
  cout << "Enter a value for the exponent: ";
  cin >> x;
  cout << "Enter a valur for n: ";
  cin >> n;
  euler_approx = 0;
  for (int i = 0; i < n; i++) {
    euler_approx += (pow(x, i) / factorial(i));
  }
  cout.setf(ios::fixed);
  cout.precision(10);
  cout << "Euler's number approximation: " << euler_approx << endl;
  cout.unsetf(ios::fixed);
  return 0;
}
/* Definition */
double factorial(int n) {
  if (n > 1) {
    return (n * factorial(n - 1));
  }
  else {
    return 1;
  }
}