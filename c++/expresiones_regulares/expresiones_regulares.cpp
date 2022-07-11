#include <iostream>
#include <cstring>
#include <regex>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  string text = "Hola soy Jose mi numero de telefono es 019-192-020 xD";
  smatch m;
  regex re("\\w+\\d+");
  cout << "Text: " << text << endl;
  while (regex_search(text, m, re)) {
    for (auto e : m) {
      cout << "Found string: " << e << endl;
    }
    text = m.suffix();
  }
}
/* Definition */