#include <iostream>
#include <cstring>
#include <tuple>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  int a;
  string b;
  char c;
  tuple<int, string, char, float, bool> datos;
  datos = make_tuple(10, "hola", 'A', 3.14, true);
  tie(a, b, ignore, ignore, ignore) = datos;
  c = get<2>(datos);
  tuple_element<3, decltype(datos)>::type d = get<3>(datos);
  cout << "Tuple size: " << tuple_size<decltype(datos)>::value << endl;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;
  cout << "d: " << d << endl;
  return 0;
}
/* Definition */