#include <iostream>
#include <cstring>
#include <vector>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
vector<string> split(string, string);
int main() {
  string s, sep;
  getline(cin, s, '\n');
  sep = " ";
  cout << "s: " << s << endl;
  vector<string> r = split(s, sep);
  for (string e : r) {
    cout << e << " ";
  }
  cout << endl;
  cout << "size: " << r.size() << endl;
  return 0;
}
/* Definition */
vector<string> split(string s, string sep) {
  vector<string> r;
  string t;
  long long int pos;
  while(true) {
    pos = s.find(sep);
    if (pos != string::npos) {
      t = s.substr(0, pos);
      if (!t.empty()) {
        r.push_back(t);
      }
      s = s.substr(pos + sep.size(), string::npos);
    }
    else {
      break;
    }
  }
  if (!s.empty()) {
    r.push_back(s);
  }
  return r;
}