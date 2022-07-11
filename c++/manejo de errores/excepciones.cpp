#include <iostream>
#include <cstring>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  // Catch específico
  try {
    throw 2;
  }
  catch(int e) {
    cout << e << endl;
  }
  // Catch general
  try {
    throw "x";
  }
  catch(...) {
    cout << "error" << endl;
  }
  return 0;
}
/* Definition */