#include <iostream>
#include <cstring>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
string trim(string, char);
int main() {
  string s, r;
  getline(cin, s, '\n');
  cout << "s: " << s << endl;
  r = trim(s, 'b');
  cout << r << endl;
  cout << "size: " << r.size() << endl;
  return 0;
}
/* Definition */
string trim(string s, char side) {
  int i, j;
  if (side == 'l') {
    i = 0;
    while (s.at(i) == ' ') {
      i++;
    }
    return s.substr(i, string::npos);
  }
  else if (side == 'b') {
    i = 0;
    j = s.size() - 1;
    while (s.at(i) == ' ') {
      i++;
    }
    while (s.at(j) == ' ') {
      j--;
    }
    return s.substr(i, ((j + 1) - i));
  }
  else if (s.at(i) == 'r') {
    j = s.size() - 1;
    while (s.at(j) == ' ') {
      j--;
    }
    return s.substr(0, j + 1);
  }
  else {
    return s;
  }
  return s;
}