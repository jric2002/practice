#include <iostream>
#include <algorithm>
/* Author: José Rodolfo (jric2002) */
// Theory: https://www.include-poetry.com/Code/C++/Matematicas/Teoria-de-numeros/Divisibilidad/
using namespace std;
/* Declaration */
template <typename T>
T mcd(T, T);
template <typename T>
T mcm(T, T);
int main(int argc, char *argv[]) {
  int n1, n2;
  n1 = n2 = 1;
  if ((argc - 1) == 2) {
    n1 = atoi(argv[1]);
    n2 = atoi(argv[2]);
  }
  else {
    cout << "n1: ";
    cin >> n1;
    cout << "n2: ";
    cin >> n2;
  }
  cout << "MCM(" << n1 << ", " << n2 << ") -> " << mcm<int>(n1, n2) << endl;
  return 0;
}
/* Definition */
template <typename T>
T mcd(T n1, T n2) {
  T temp;
  temp = n1;
  n1 = max(n1, n2);
  n2 = min(temp, n2);
  n1 = n1 % n2;
  return (n1 != 0) ? mcd<T>(n1, n2) : n2;
}
template <typename T>
T mcm(T n1, T n2) {
  return n1 * (n2 / mcd<T>(n1, n2));
}