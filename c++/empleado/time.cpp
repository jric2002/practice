#include <iostream>
#include "time.h"
using namespace std;
Time::Time(int hr, int min, int sec) {
  setTime(hr, min, sec);
}
void Time::setTime(int h, int m, int s) {
  setHour(h);
  setMinute(m);
  setSecond(s);
}
void Time::setHour(int h) {
  hour = (h >= 0 && h < 24) ? h : 0;
}
void Time::setMinute(int m) {
  minute = (m >= 0 && m < 60) ? m : 0;
}
void Time::setSecond(int s) {
  second = (s >= 0 && s < 24) ? s : 0;
}
int Time::getHour() const {
  return hour;
}
int Time::getMinute() const {
  return minute;
}
int Time::getSecond() const {
  return second;
}
void Time::printMilitary() const {
  cout << (hour < 10 ? "0" : "") << hour << ":" << (minute < 10 ? "0" : "") << minute;
}
void Time::printStandard() const {
  cout << ((hour == 12) ? 12 : hour % 12) << ":" << (minute < 10 ? "0" : "") << minute << ":" << (second < 10 ? "0" : "") << second << (hour < 12 ? " AM" : " PM");
}