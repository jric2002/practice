#include <iostream>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
class Test {
  public:
    Test();
    ~Test();
};
int main() {
  cout << "Test 1: Pointer to object" << endl;
  cout.width(40);
  cout.fill('-');
  cout << "" << endl;
  cout << "Constructor:" << endl;
  Test *t1 = new Test;
  cout << "Destructor:" << endl;
  delete t1; // Free memory of an object
  cout << endl;
  cout << "Test 2: Pointer to array of objects" << endl;
  cout.width(40);
  cout.fill('-');
  cout << "" << endl;
  cout << "Constructor:" << endl;
  Test *t2 = new Test[5];
  cout << "Destructor:" << endl;
  //delete t2; // Free memory of an object
  delete[] t2; // Free memory of and array of objects
  cout << endl;
  cout << "Test 3: Pointer to array of pointers" << endl;
  cout.width(40);
  cout.fill('-');
  cout << "" << endl;
  cout << "Constructor:" << endl;
  Test **t3 = new Test*[3];
  for (int i = 0; i < 3; i++) {
    t3[i] = new Test[2];
  }
  cout << "Destructor:" << endl;
  for (int i = 0; i < 3; i++) {
    delete[] t3[i];
  }
  delete t3;
  return 0;
}
/* Definition */
Test::Test() {
  cout << this << " -> Constructor" << endl;
}
Test::~Test() {
  cout << this << " -> Destructor" << endl;
}