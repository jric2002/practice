#include <iostream>
#include <math.h>
using namespace std;
int main() {
  /*string correo, clave;
  cout << "ingresa tu correo: ";
  cin >> correo;
  cout << "ingresa tu clave: ";
  cin >> clave;
  cout << sqrt(25) << endl;
  //condicional
  if (correo == "aaaa@gmail.com" && clave == "abc") {
    cout << "entraste correctamente";
  }
  else {
    cout << "vuelve a ingresar";
  }
  int test1 = 15;
  int test2 = 2;
  if (test1 < 10 && test2 > 8) {
    cout << "entraste correctamente";
  }
  else {
    cout << "vuelve a ingresar";
  }*/
  double peso, altura, imc;
  cout << "ingresa el peso: ";
  cin >> peso;
  cout << "ingresa la altura: ";
  cin >> altura;
  imc = (peso)/(altura*altura);
  cout << imc << endl;
  if (imc < 16){
    cout << "necesita ingresar al hospital";
  }
  else if (imc >= 16 && imc < 17){
    cout << "infrapeso";
  }
  else if (imc >=17 && imc < 18){
    cout << "bajo peso";
  }
  else if (imc >=18 && imc < 25){
    cout << "peso normal (saludable)";
  }
  else if (imc >=25 && imc < 30){
    cout << "infrapeso";
  }
  else if (imc >=30 && imc < 35){
    cout << "infrapeso";
  }
  else if (imc >=35 && imc < 40){
    cout << "infrapeso";
  }
  else {
    cout << "infrapeso";
  }
  return 0;
}