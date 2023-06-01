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
      if (pos < long_cad) {
        if (cad[pos] == '1') {
          pos++;
          reconoce = false;
          q1();
        }
        else if (cad[pos] == '2' || cad[pos] == '3') {
          pos++;
          reconoce = false;
          q3();
        }
      }
    }
    void q1() {
      if (pos < long_cad) {
        if (cad[pos] == '1') {
          pos++;
          reconoce = false;
          q4();
        }
        else if (cad[pos] == '2') {
          pos++;
          reconoce = true;
          q5();
        }
        else if (cad[pos] == '3') {
          pos++;
          reconoce = true;
          q2();
        }
      }
    }
    void q2() {
      if (pos < long_cad) {
        if (cad[pos] == '1' || cad[pos] == '2' || cad[pos] == '3') {
          pos++;
          reconoce = true;
          q2();
        }
      }
    }
    void q3() {
      if (pos < long_cad) {
        if (cad[pos] == '1') {
          pos++;
          reconoce = false;
          q4();
        }
        else if (cad[pos] == '2' | cad[pos] == '3') {
          pos++;
          reconoce = false;
          q3();
        }
      }
    }
    void q4() {
      if (pos < long_cad) {
        if (cad[pos] == '1') {
          pos++;
          reconoce = false;
          q4();
        }
        else if (cad[pos] == '2') {
          pos++;
          reconoce = true;
          q5();
        }
        else if (cad[pos] == '3') {
          pos++;
          reconoce = false;
          q3();
        }
      }
    }
    void q5() {
      if (pos < long_cad) {
        if (cad[pos] == '1') {
          pos++;
          reconoce = false;
          q4();
        }
        else if (cad[pos] == '2' || cad[pos] == '3') {
          pos++;
          reconoce = false;
          q3();
        }
      }
    }
    bool aceptado() {
      return reconoce;
    }
};
int main() {
  string cadena("1123131");
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