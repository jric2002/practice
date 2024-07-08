#include <iostream>
using namespace std;
string es_par_o_impar(int);
int main(int argc, char *argv[]) {
  int n = 7;
  cout << es_par_o_impar(n) << endl;
  return 0;
}
string es_par_o_impar(int n) {
  if (n == 0) {
    return "El número es par";
  }
  else if (n < 0) {
    return "El número es impar";
  }
  else {
    return es_par_o_impar(n - 2);
  }
}