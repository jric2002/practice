#include <iostream>
#include <cstring>
#include <array>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  array<int, 5> first;
  array<int, 5> second;
  first = {10, 20, 30, 40, 50};
  second = {1, 2, 3, 4, 5};
  //first.fill(2);
  for (auto it = first.begin(); it != first.end(); it++) {
    *it = *it * 2;
  }
  cout << "First array: ";
  for (auto n : first) {
    cout << n << " ";
  }
  cout << endl;
  cout << "Array properties first" << endl;
  cout << "* Size: " << first.size() << endl;
  cout << "* Front: " << first.front() << endl;
  cout << "* Back: " << first.back() << endl;
  cout << "* Empty: ";
  (first.empty()) ? cout << "Yes" << endl : cout << "No" << endl;
  cout.width(20);
  cout.fill('-');
  cout << "" << endl;
  cout << "Before" << endl;
  cout << "* First array: ";
  for (auto n : first) {
    cout << n << " ";
  }
  cout << endl;
  cout << "* Second array: ";
  for (auto n : second) {
    cout << n << " ";
  }
  cout << endl;
  first.swap(second);
  cout << "After" << endl;
  cout << "* First array: ";
  for (auto n : first) {
    cout << n << " ";
  }
  cout << endl;
  cout << "* Second array: ";
  for (auto n : second) {
    cout << n << " ";
  }
  cout << endl;
  return 0;
}
/* Definition */