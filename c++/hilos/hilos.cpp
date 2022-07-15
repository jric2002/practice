#include <iostream>
#include <thread>
#include <chrono>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
void f1();
void f2();
int main() {
  thread t1(f1);
  thread t2(f2);
  cout << "t1 thread id: " << t1.get_id() << endl;
  cout << "t2 thread id: " << t2.get_id() << endl;
  t1.join();
  chrono::milliseconds ts(1000);
  this_thread::sleep_for(ts);
  t2.join();
  cout << "Number of threads: " << thread::hardware_concurrency << endl;
  thread::id main_thread_id = this_thread::get_id();
  cout << "Main thread id: " << main_thread_id << endl;
  return 0;
}
/* Definition */
void f1() {
  cout << "1st function" << endl;
}
void f2() {
  cout << "2nd function" << endl;
}