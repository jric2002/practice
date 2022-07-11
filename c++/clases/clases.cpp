#include <iostream>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
class Persona {
  private:
    string name;
    int age;
  public:
    Persona(string name, int age);
    string getName();
    int getAge();
    void showInfo();
};
int main() {
  Persona juan("juan", 20);
  Persona jose = Persona("jose", 30);
  jose.showInfo();
  juan.showInfo();
  return 0;
}
/* Definition */
Persona::Persona(string _name, int _age) : name(_name), age(_age) {}
string Persona::getName() {
  return name;
}
int Persona::getAge() {
  return age;
}
void Persona::showInfo() {
  cout << "name: " << name << endl;
  cout << "age: " << age << endl;
}