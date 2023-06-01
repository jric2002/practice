#include <iostream>
using namespace std;
class Apuntador {
  private:
    int *numeros;
  public:
    Apuntador(int *_numeros) {
      numeros = _numeros;
    }
    void invertirDatos() {
      // a = {1, 2, 3}
      // b = {1, 2, 3, 4}
      int size_array = (sizeof(numeros)/sizeof(int));
      int invertidos[size_array + 1];
      for (int i = 0; i <= size_array;i++) {
        invertidos[size_array - i] = numeros[i];
      }
      cout << "\nDatos invertidos: ";
      for (int i = 0; i < sizeof(invertidos)/sizeof(int); i++) {
        cout << invertidos[i] << " ";
      }
      cout << endl;
    }
};
int main() {
  int numeros[] = {1, 3, 6};
  Apuntador p = Apuntador(&numeros[0]);
  p.invertirDatos();
  return 0;
}