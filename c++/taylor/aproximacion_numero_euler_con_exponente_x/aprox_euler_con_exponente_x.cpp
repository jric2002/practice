#include <iostream>
#include <cmath>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
double factorial(int);
int main() {
  int x, n;
  double euler, real_value, approx_value;
  double absolute_error, relative_error, relative_percentage_error;
  euler = 2.7182818284590452353602874713527;
  cout << "Approximation of Euler's number" << endl;
  cout << "with exponent \"x\" using the Taylor series" << endl;
  cout.width(41);
  cout.fill('-');
  cout << "" << endl;
  cout << "Enter a value for the exponent 'x': ";
  cin >> x;
  cout << "Enter a value for 'n': ";
  cin >> n;
  real_value = pow(euler, x);
  approx_value = 0;
  for (int i = 0; i < n; i++) {
    approx_value += (pow(x, i) / factorial(i));
  }
  absolute_error = abs(real_value - approx_value);
  relative_error = absolute_error / real_value;
  relative_percentage_error = relative_error * 100;
  cout.setf(ios::fixed);
  cout.precision(7);
  cout << "[+] Real value: " << real_value << endl;
  cout << "[+] Approximation value: " << approx_value << endl;
  cout << "[+] Absolute error: " << absolute_error << endl;
  cout << "[+] Relative error: " << relative_error << endl;
  cout.precision(3);
  cout << "[+] Relative percentage error: " << relative_percentage_error << " %" << endl;
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