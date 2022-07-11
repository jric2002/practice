#include <iostream>
#include <iomanip>
#include <cstring>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int *duplicar(int [], int);
int main() {
  int numbers[] = {1, 3, 5, 7};
  int nl = sizeof(numbers)/sizeof(int);
  int *r;
  r = duplicar(numbers, nl);
  for (int i = 0; i < nl; i++) {
    cout << r[i] << " ";
  }
  cout << endl;
  return 0;
}
/* Definition */
int *duplicar(int n[], int nl) {
  for (int i = 0; i < nl; i++) {
    n[i] = n[i] * 2;
  }
  return n;
}