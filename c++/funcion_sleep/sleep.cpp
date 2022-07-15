#include <iostream>
#include <chrono>
#include <thread>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  cout << "1st line" << endl;
  chrono::milliseconds ms(1500);
  this_thread::sleep_for(ms);
  cout << "2nd line" << endl;
  return 0;
}
/* Definition */