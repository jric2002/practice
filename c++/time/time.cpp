#include <iostream>
using namespace std;
class Time {
  private:
    int hour;
    int minute;
    int second;
  public:
    Time(int = 0, int = 0, int = 0);
    Time &setTime(int, int, int);
    Time &setHour(int);
    Time &setMinute(int);
    Time &setSecond(int);
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void printMilitary() const;
    void printStandard() const;
};
/* Declaration */
int main(int argc, char *argv[]) {
  Time t(14, 20, 15);
  cout << "HH:MM:SS" << endl;
  cout.width(10);
  cout.fill('-');
  cout << "" << endl;
  t.printMilitary();
  t.printStandard();
  cout << endl;
  t.setHour(15).setMinute(30).setSecond(20);
  t.printMilitary();
  t.printStandard();
  return 0;
}
/* Definition */
Time::Time(int h, int m, int s) {
  setTime(h, m, s);
}
Time &Time::setTime(int h, int m, int s) {
  setHour(h);
  setMinute(m);
  setSecond(s);
  return *this;
}
Time &Time::setHour(int h) {
  hour = (h >= 0 && h < 24) ? h : 0;
  return *this;
}
Time &Time::setMinute(int m) {
  minute = (m >= 0 && m < 60) ? m : 0;
  return *this;
}
Time &Time::setSecond(int s) {
  second = (s >= 0 && s < 60) ? s : 0;
  return *this;
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
  cout << (hour < 10 ? "0" : "") << hour << ":"
      << (minute < 10 ? "0" : "") << minute << ":"
      << (second < 10 ? "0" : "") << second << endl;
}
void Time::printStandard() const {
  int h = (hour == 0 || hour == 12) ? 12 : hour % 12;
  cout << (h < 10 ? "0" : "") << h << ":"
      << (minute < 10 ? "0" : "") << minute << ":"
      << (second < 10 ? "0" : "") << second << " "
      << (hour < 12 ? "AM" : "PM") << endl;
}