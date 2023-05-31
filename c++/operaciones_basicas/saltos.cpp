#include <iostream>
#include <time.h>
using namespace std;
int main() {
  int s_altos = 0, s_bajos = 0;
  int num = 20;
  int alturas[num];
  int inicio = 1, fin = 20;
  srand(time(NULL));
  for(int i = 0; i < num; i++) {
    alturas[i] = inicio + rand()%(fin - inicio + 1);
  }
  for(int i = 0; i < (num - 1); i++){
    if (alturas[i] < alturas[i+1]) {
      s_altos++;
    }
    else {
      s_bajos++;
    }
  }
  cout << "saltos altos: " << s_altos << endl;
  cout << "saltos bajos: " << s_bajos << endl;
  return 0;
}