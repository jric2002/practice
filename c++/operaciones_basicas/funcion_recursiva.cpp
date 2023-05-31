#include <iostream>
using namespace std;
//funcion recursiva
void demo(int x) {
  if (x != 0) {
    cout << x << " " << endl;
    demo(x-1);
  }
  cout << "x" << endl;
}
int main() {
  demo(3);
  return 0;
}