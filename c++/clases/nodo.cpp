#include <iostream>
using namespace std;
class Nodo {
  private:
    int valor;
    Nodo *sig;
  public:
    Nodo(int v) {
      this->valor = v;
      this->sig = NULL;
    }
    int retValor() {
      return valor;
    }
    Nodo *retSig() {
      return sig;
    }
    void unir(Nodo *n2) {
      sig = n2;
    }
};
int main() {
  Nodo *n1 = new Nodo(5);
  Nodo *n2 = new Nodo(8);
  Nodo *n3 = new Nodo(3);
  n1->unir(n2);
  n2->unir(n3);
  cout << n1->retValor() << endl;
  cout << n1->retSig()->retValor() << endl;
  cout << n3->retSig() << endl;
  n3->unir(n1);
  cout << n3->retSig()->retValor() << endl;
  n3->unir(NULL);
  cout << n3->retSig()->retValor() << endl;
  return 0;
}