#include <iostream>
#include <time.h>
using namespace std;
int main() {
  srand(time(NULL));
  int a, inicio(10), fin(20);
  for(int i=0; i<20; i++){
    a = inicio + rand()%(fin - inicio + 1);
    cout << a << " ";
  }
  return 0;
}