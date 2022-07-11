#include <iostream>
#include <set>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  set<int> c;
  c.insert(1);
  c.insert(2);
  c.insert(3);
  c.insert(4);
  c.insert(2);
  for (set<int>::iterator it = c.begin(); it != c.end(); it++) {
    cout << " " << *it;
  }
  return 0;
}
/* Definition */