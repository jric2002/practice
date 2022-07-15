#include <iostream>
#include <cstring>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  // Using lambda expressions
  auto sum = [](int n1, int n2) {
    return (n1 + n2);
  };
  cout << "Sum: " << sum(3, 5) << endl;
  auto mult = [](float n1, float n2) -> int {
    return (n1 * n2);
  };
  cout << "Mult: " << mult(2.5, 3) << endl << endl;
  // Using the & operator with return type
  string s1 = "Hello";
  int year = 2022;
  auto greeting = [&s1, year](string name, int age) -> string {
    s1 = s1 + " " + name + ", you are " + to_string(age) + " years old.";
    s1 = s1 + " We are in the year " + to_string(year);
    return s1;
  };
  cout << "Greeting: " << greeting("Jose", 20) << endl;
  cout << "s1: " << s1 << endl;
  cout << "year: " << year << endl << endl;
  // Operador & : Capture scope by reference
  auto farewell = [&](string name) -> string {
    year = 2023;
    s1 = name + ", see you in the year " + to_string(year);
    return s1;
  };
  cout << "Farewell: " << farewell("Jose") << endl;
  cout << "s1: " << s1 << endl;
  cout << "year: " << year << endl << endl;
  // Operator = : Capture scope by value
  string my_name = "Jose";
  int my_age = 20;
  auto whoiam = [=]() -> string {
    string p = "My name is " + my_name + ", I am " + to_string(my_age) + " years old.";
    return p;
  };
  cout << "Who I am?: " << whoiam() << endl;
  return 0;
}
/* Definition */