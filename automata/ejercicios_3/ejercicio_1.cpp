#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
class Automata {
  private:
    string cadena;
    int long_cadena;
    int pos;
    stack<char> pila;
    bool aceptado;
  public:
    Automata(string cadena) {
      this->cadena = cadena;
      long_cadena = cadena.size();
      pos = 0;
      pila.push('Z');
      aceptado = false;
    }
    void iniciar() {
      q0();
    }
    void q0() {
      if (pos < long_cadena) {
        if (cadena[pos] == 'a') {
          pila.push('A');
          pos++;
          q0();
        }
        else if (cadena[pos] == 'b') {
          pila.push('B');
          pos++;
          q0();
        }
        else if (cadena[pos] == 'x') {
          pos++;
          q1();
        }
        else {
          aceptado = false;
        }
      }
    }
    void q1() {
      if (pos < long_cadena) {
        if (cadena[pos] == 'a' && pila.top() == 'A') {
          pila.pop();
          pos++;
          q1();
        }
        else if (cadena[pos] == 'b' && pila.top() == 'B') {
          pila.pop();
          pos++;
          q1();
        }
        else {
          aceptado = false;
        }
      }
      else if (pila.top() == 'Z') {
        pila.pop();
        q2();
      }
      else {
        aceptado = false;
      }
    }
    void q2() {
      aceptado = true;
    }
    bool obtenerEstado() {
      return aceptado;
    }
};
int main() {
  string input;
  int n = 8;
  while (n--) {
    cout << "input: ";
    cin >> input;
    Automata *a = new Automata(input);
    a->iniciar();
    if (a->obtenerEstado()) {
      cout << "El automata SI acepta/reconoce la cadena: " << input << endl;
    }
    else {
      cout << "El automata NO acepta/reconoce la cadena: " << input << endl;
    }
    delete a;
  }
  return 0;
}