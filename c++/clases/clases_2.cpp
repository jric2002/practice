#include <iostream>
using namespace std;
class Telefono {
  public:
    string *tel;
    int c_tel;
    Telefono(string _tel[], int _c_tel) {
      this->tel = new string;
      this->tel = &_tel[0];
      this->c_tel = _c_tel;
    }
    ~Telefono() {
      delete tel;
    }
};
class Persona {
  private:
    string nombre;
    int *edad;
    Telefono *tel;
  public:
    Persona(string nombre, int edad, Telefono *t) {
      this->nombre = nombre;
      this->edad = new int;
      this->edad = &edad;
      this->tel = t;
    }
    string retNombre() {
      return nombre;
    }
    int retEdad() {
      return *edad;
    }
    void mostrarTel() {
      for (int i = 0; i < tel->c_tel; i++) {
        cout << *(tel->tel + i) << endl;
      }
    }
    ~Persona() {
      delete edad;
    }
};
int main() {
  int c_tel = 3;
  string tel[c_tel] = {"900101202", "987654321", "900322500"};
  Telefono *t = new Telefono(tel, c_tel);
  Persona *p = new Persona("PEDRO", 19, t);
  cout << p->retNombre() << endl;
  cout << p->retEdad() << endl;
  p->mostrarTel();
  return 0;
}