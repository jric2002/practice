#include <iostream>
#include <string>
#include <cmath>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
class Persona {
  private:
    string gender;
  public:
    Persona(string _gender) {
      gender = _gender;
    }
    string getGender() {
      return gender;
    }
    bool walk() {
      return true;
    }
};
class Viejo: public Persona {
  private:
    string name;
    int age;
    bool sick;
  public:
    Viejo(string n, int a, string g, bool s): Persona(g) {
      name = n;
      age = a;
      sick = s;
    }
    void getInfo() {
      cout << "name: " << name << endl;
      cout << "age: " << age << endl;
      cout << "sick: " << sick << endl;
      cout << "gender: " << getGender() << endl;
    }
};
class Joven: public Persona {
  private:
    string name;
    int age;
  public:
    Joven(string _gender, string _name, int _age): Persona(_gender) {
      name = _name;
      age = _age;
    }
    void setAge(int a) {
      age = a;
    }
    int getAge() {
      return age;
    }
    void saludo(string msg) {
      cout << "Hola, mundo" << endl;
    }
};
class Woman: public Joven {
  private:
    string status;
  public:
    Woman(string _gender, string _name, int _age, string _status): Joven(_gender, _name, _age) {
      status = _status;
    }
    string getStatus() {
      return status;
    }
};
int main() {
  Joven jose("Masculino", "Jose", 19);
  cout << jose.walk() << endl;
  Woman allison("Femenino", "Allison", 20, "Soltera");
  cout << allison.walk() << endl;
  cout << allison.getGender() << endl;
  cout << "********" << endl;
  Viejo david = Viejo("David", 60, "masculino", true);
  david.getInfo();
  return 0;
}
/* Definition */