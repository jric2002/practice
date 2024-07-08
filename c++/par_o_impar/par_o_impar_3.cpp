#include <iostream>
using namespace std;
int es_par_o_impar(int);
int main(int argc, char *argv[]) {
  int n = 7;
  if (es_par_o_impar(n) == 0) {
    cout << "El número " + to_string(n) + " es par" << endl;
  }
  else {
    cout << "El número " + to_string(n) + " es impar" << endl;
  }
  return 0;
}
int es_par_o_impar(int n) {
  return (n <= 0) ? n : es_par_o_impar(n - 2);
}