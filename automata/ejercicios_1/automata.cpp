#include <iostream>
#include <cstring>
using namespace std;
class Automata {
  private:
    string cad;
    int long_cad;
    int pos;
    bool reconoce;
  public:
    Automata(string cad) {
      this->cad = cad;
      long_cad = cad.size();
      pos = 0;
      reconoce = false;
    }
    void iniciar() {
      q0();
    }
    void q0() {
      if (long_cad == 0) {
        reconoce = true;
      }
      else if (pos < long_cad) {
        if (cad.at(pos) == 'a') {
          pos++;
          reconoce = false;
          q1();
        }
        else if (cad.at(pos) == 'b') {
          pos++;
          reconoce = true;
          q2();
        }
      }
    }
    void q1() {
      if (pos < long_cad) {
        if (cad.at(pos) == 'a') {
          pos++;
          reconoce = true;
          q0();
        }
        else if (cad.at(pos) == 'b') {
          pos++;
          reconoce = true;
          q2();
        }
      }
    }
    void q2() {
      if (pos < long_cad) {
        if (cad.at(pos) == 'a') {
          pos++;
          reconoce = false;
          q1();
        }
        else if (cad.at(pos) == 'b') {
          reconoce = false;
        }
      }
    }
    bool aceptado() {
      return reconoce;
    }
};
int main() {
  string cadena("baba");
  Automata *aut = new Automata(cadena);
  aut->iniciar();
  if (aut->aceptado()) {
    cout << "El automata SI reconoce/acepta la cadena: " << cadena << endl;
  }
  else {
    cout << "El automata NO reconoce/acepta la cadena: " << cadena << endl;
  }
  delete aut;
  return 0;
}