#include <iostream>
#include <cstring>
#include <limits>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main(int argc, char *argv[]) {
  string s;
  char c;
  getline(cin, s, '\n');
  cout << "s: " << s << endl;
  cin >> s;
  cout << "s: " << s << endl;
  // while(getchar() != '\n'); // Manera de ignorar caracteres del flujo de entrada
  // cin.ignore(numeric_limits<int>::max(), '\n');
  fflush(stdin);
  c = getchar();
  cout << "c: " << c << endl;
  return 0;
}
/* Definition */