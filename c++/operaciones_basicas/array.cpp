#include <iostream>
using namespace std;
int main() {
  int n, T;
  cin >> n; cin >> T;
  int numeros[n];
  //recibir y guardar datos
  for (int i = 0; i < n; i++) {
    //cout << (i + 1) << " num: ";
    cin >> numeros[i];
  }
  cout<<endl;
  //mostrar resultado
  for (int j = 0; j < T; j++) {
    for (int i = 0; i < n; i++) {
      cout << numeros[i];
    }
  }
  cout<<endl;
  return 0;
}