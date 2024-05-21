#include <iostream>
#include <cstring>
#include <cassert>
#include "empleado.h"
using namespace std;
int Employee::count = 0;
int Employee::getCount() {
  return count;
}
Employee::Employee(const char *first, const char *last, Date fn, Date fc, Time hi, Time hs) {
  firstName = new char[strlen(first) + 1];
  assert(firstName != 0);
  strcpy(firstName, first);
  lastName = new char[strlen(last) + 1];
  assert(lastName != 0);
  strcpy(lastName, last);
  fecha_nac = fn;
  fecha_contra = fc;
  hora_inicio = hi;
  hora_salida = hs;
  ++count;
  cout << "Employee constructor for " << firstName << " " << lastName << " called." << endl;
}
Employee::~Employee() {
  cout << "~Employee() called for " << firstName << " " << lastName << endl;
  delete[] firstName;
  delete[] lastName;
  --count;
}
Date Employee::calcularEdad() {
  return Date();
}
Time Employee::calcularHoras() {
  int h, m, s, tt;
  tt = (hora_salida.getHour()*3600 + hora_salida.getMinute()*60 + hora_salida.getSecond());
  tt = tt - (hora_inicio.getHour()*3600 + hora_inicio.getMinute()*60 + hora_inicio.getSecond());
  h = tt/3600;
  tt %= 3600;
  m = tt/60;
  tt %= 60;
  s = tt;
  return Time(h, m, s);
}
const char *Employee::getFirstName() const {
  return firstName;
}
const char *Employee::getLastName() const {
  return lastName;
}