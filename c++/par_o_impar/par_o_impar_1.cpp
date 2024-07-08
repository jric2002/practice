#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
  int n = 7;
  if (n & 1) {
    cout << "El número " << n << " es impar" << endl;
  }
  else {
    cout << "El número " << n << " es par" << endl;
  }
  return 0;
}