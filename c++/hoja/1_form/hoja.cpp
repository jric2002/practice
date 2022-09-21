#include <iostream>
#include <cstring>
#include <map>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
class Row {
  public:
    map<int, string> r;
    void insert(int p, string t) {
      r[p] = t;
      //r.insert(pair<int, string>(p, t));
    }
    void display() {
      for (map<int, string>::iterator it = r.begin(); it != r.end(); it++) {
        cout << "(" << (*it).first << ")[" << (*it).second << "] ";
      }
      cout << endl;
    }
};
class Sheet {
  public:
    map<string, Row> s;
    void insert(string c, int r, string t) {
      map<string, Row>::iterator it = s.find(c);
      if (it != s.end()) {
        ((*it).second).insert(r, t);
      }
      else {
        Row row;
        row.insert(r, t);
        s[c] = row;
        //s.insert(pair<string, Row>(c, Row(r, t)));
      }
    }
    void display() {
      for (map<string, Row>::iterator it = s.begin(); it != s.end(); it++) {
        cout << "[" << (*it).first << "] -> ";
        ((*it).second).display();
      }
    }
};
int main() {
  Sheet s;
  s.insert("C", 1, "Hola");
  s.insert("A", 2, "mundo");
  s.insert("E", 3, "xD");
  s.insert("A", 2, "genial");
  s.display();
  return 0;
}
/* Definition */