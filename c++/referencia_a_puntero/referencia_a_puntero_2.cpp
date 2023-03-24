#include <iostream>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main(int argc, char *argv[]) {
  int **rr;
  int *p;
  int n = 123;
  p = &n;
  int *&rp = p;
  rr = &p;
  cout << "address of n: " << &n << endl;
  cout << "value of n: " << n << endl << endl;
  cout << "address of rp: " << &rp << endl;
  cout << "value of rp: " << rp << endl;
  cout << "*rp: " << *rp << endl << endl;
  cout << "address of p: " << &p << endl;
  cout << "value of p: " << p << endl;
  cout << "*p: " << *p << endl << endl;
  cout << "address of rr: " << &rr << endl;
  cout << "value of rr: " << rr << endl;
  cout << "*rr: " << *rr << endl;
  return 0;
}
/* Definition */