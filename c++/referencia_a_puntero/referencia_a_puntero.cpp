#include <iostream>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
void f(int *&);
int main() {
  int *p;
  int n = 12;
  p = &n;
  cout << "Address of n: " << &n << endl;
  cout << "Value of n: " << n << endl;
  cout.width(30);
  cout.fill('-');
  cout << "" << endl;
  cout << "Address of p: " << &p << endl;
  cout << "Value of p: " << p << endl;
  cout << "*p: " << *p << endl;
  cout.width(30);
  cout.fill('-');
  cout << "" << endl;
  f(p);
  return 0;
}
/* Definition */
void f(int *&rp) {
  cout << "Address of rp: " << &rp << endl;
  cout << "Value of rp: " << rp << endl;
  cout << "*rp: " << *rp << endl;
  cout << "*&rp: " << *&rp << endl;
}