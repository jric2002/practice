#include <iostream>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
// int main(int argc, char *argv[]) {
int main(int argc, char **argv) {
  for (int i = 0; i < argc; i++) {
    // cout << i << " -> " << *(argv + i) << endl;
    cout << i << " -> " << argv[i] << endl;
  }
  return 0;
}
/* Definition */