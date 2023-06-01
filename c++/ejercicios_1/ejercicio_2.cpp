#include <iostream>
using namespace std;
int main() {
  int numero = 5;
  int *puntero;
  cout << "Memory address: " << &numero << endl;
  cout << "Value: " << numero << endl;
  cout << endl;
  cout << "Memory address of pointer: " << &puntero << endl;
  cout << "Value of pointer: " << puntero << endl;
  cout << "Value of the memory address: " << *puntero << endl;
  cout << endl;
  puntero = &numero;
  cout << "Memory address of pointer: " << &puntero << endl;
  cout << "Value of pointer: " << puntero << endl;
  cout << "Value of the memory address: " << *puntero << endl;
  cout << endl;
  numero = 10;
  cout << "Memory address of pointer: " << &puntero << endl;
  cout << "Value of pointer: " << puntero << endl;
  cout << "Value of the memory address: " << *puntero << endl;
  cout << endl;
  *puntero = 20;
  cout << "Memory address: " << &numero << endl;
  cout << "Value: " << numero << endl;
  return 0;
}