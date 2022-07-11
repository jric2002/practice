#include <iostream>
#include <iomanip>
#include <cstring>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int sum(int a, int b) {
  return a + b;
}
int main() {
  int (*fp)(int, int);
  fp = sum;
  cout << "suma: " << fp(5, 6) << endl;
  enum Week {sunday, monday, tuesday, wednesday, thursday, friday, saturday};
  Week today = tuesday;
  cout << "Day: " << monday << endl;
  int **p;
  *p = new int;
  **p = 25;
  cout << **p << endl;
  delete *p;
  return 0;
}
/* Definition */