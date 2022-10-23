#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  srand(time(NULL));
  int l = 4;
  cout << rand() % (l + 1) << endl;
  cout << rand() % (l + 1) << endl;
  cout << rand() % (l + 1) << endl;
  cout << rand() % (l + 1) << endl;
  return 0;
}
/* Definition */