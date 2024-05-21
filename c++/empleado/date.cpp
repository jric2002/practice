#include <iostream>
#include "date.h"
using namespace std;
Date::Date(int mn, int dy, int yr) {
  if (mn > 0 && mn <= 12) {
    month = mn;
  }
  else {
    month = 1;
    cout << "Month " << mn << "invalid. Set to month";
  }
  year = yr;
  day = checkDay(dy);
  cout << "Date object constructor for date ";
  print();
  cout << endl;
}
void Date::print() const {
  cout << month << '/' << day << '/' << year;
}
Date::~Date() {
  cout << "Date object destructor for date ";
  print();
  cout << endl;
}
int Date::checkDay(int testDay) {
  static const int daysPerMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (testDay > 0 && testDay <= daysPerMonth[month]) {
    return testDay;
  }
  if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
    return testDay;
  }
  cout << "Day " << testDay << " invalid. Set to day 1.\n";
  return 1;
}