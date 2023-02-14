#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <cctype>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
template <typename H, typename C>
class Table {
  public:
    vector<H> header;
    vector<vector<C>> content;
    Table();
    void addColumn(string);
    void addRow(vector<C>);
    void print(char);
};
int main() {
  vector<string> props = {"First name", "Last name", "age"};
  vector<vector<string>> cont = {
    {"Jose Rodolfo", "vacio"},
    {"Daniel", "", "18"},
    {"Alison", "Gutierrez", "20"}
  };
  Table<string, string> t1 = Table<string, string>();
  t1.header = props;
  t1.content = cont;
  t1.addColumn("saludo");
  t1.addRow({"1ra col", "2da col"});
  t1.print('l');
  return 0;
}
/* Definition */
template <typename H, typename C>
Table<H, C>::Table() {}
template <typename H, typename C>
void Table<H, C>::addColumn(string column_name) {
  header.push_back(column_name);
}
template <typename H, typename C>
void Table<H, C>::addRow(vector<C> row) {
  content.push_back(row);
}
template <typename H, typename C>
void Table<H, C>::print(char align) {
  int max_ncols;
  char horizontal_edge, vertical_edge, corner;
  horizontal_edge = '-';
  vertical_edge = '|';
  corner = '+';
  // Searching max number of columns
  max_ncols = header.size();
  for (int r = 0; r < content.size(); r++) {
    if (max_ncols < (content.at(r)).size()) {
      max_ncols = (content.at(r)).size();
    }
  }
  // Searching maximum width of each column
  vector<int> max_width(max_ncols, 0);
  for (int c = 0; c < header.size(); c++) {
    max_width.at(c) = (header.at(c)).size();
  }
  for (int c = 0; c < max_ncols; c++) {
    for (int r = 0; r < content.size(); r++) {
      if (((content.at(r)).size() - 1) >= c) {
        if (max_width.at(c) < ((content.at(r)).at(c)).size()) {
          max_width.at(c) = ((content.at(r)).at(c)).size();
        }
      }
    }
  }
  // Print data table
  if (align == 'r') {
    cout << right;
  }
  else {
    cout << left;
  }
  cout << corner;
  for (int c = 0; c < max_ncols; c++) {
    for (int i = 0; i < max_width.at(c); i++) {
      cout << horizontal_edge;
    }
    cout << corner;
  }
  cout << endl;
  cout << vertical_edge;
  for (int c = 0; c < max_ncols; c++) {
    cout << setw(max_width.at(c));
    if ((header.size() - 1) >= c) {
      cout << header.at(c);
    }
    else {
      cout << " ";
    }
    cout << vertical_edge;
  }
  cout << endl;
  cout << corner;
  for (int c = 0; c < max_ncols; c++) {
    for (int i = 0; i < max_width.at(c); i++) {
      cout << horizontal_edge;
    }
    cout << corner;
  }
  cout << endl;
  for (int r = 0; r < content.size(); r++) {
    cout << vertical_edge;
    for (int c = 0; c < max_ncols; c++) {
      cout << setw(max_width.at(c));
      if (((content.at(r)).size() - 1) >= c) {
        cout << (content.at(r)).at(c);
      }
      else {
        cout << " ";
      }
      cout << vertical_edge;
    }
    cout << endl;
  }
  cout << corner;
  for (int c = 0; c < max_ncols; c++) {
    for (int i = 0; i < max_width.at(c); i++) {
      cout << horizontal_edge;
    }
    cout << corner;
  }
  cout << endl;
}