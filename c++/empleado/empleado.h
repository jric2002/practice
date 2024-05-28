#ifndef EMPLOY_H
#define EMPLOY_H
#include "date.h"
#include "time.h"
class Employee {
  public:
    Employee(const char *, const char *);
    ~Employee();
    const char *getFirstName() const;
    const char *getLastName() const;
    Date calcularEdad();
    Time calcularHoras();
    static int getCount();
  private:
    char *firstName;
    char *lastName;
    int dni;
    Date fecha_nac;
    Date fecha_contra;
    Time hora_inicio;
    Time hora_salida;
    static int count;
};
#endif