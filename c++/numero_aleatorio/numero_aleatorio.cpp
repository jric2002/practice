#include <iostream>
#include <time.h>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int gen(int, int);
int main(int argc, char *argv[]) {
  srand(time(NULL));
  int n = 10;
  while (n--) {
    cout << "Number: " <<  gen(4, 8) << endl;
  }
  return 0;
}
/* Definition */
int gen(int min, int max) {
  return (rand() % (max - min + 1) + min);
}