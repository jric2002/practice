#include <iostream>
using namespace std;
double fib2(double n){
  double i,j;
  i=1;j=0;
  for(double k=1;k<n; k++)
  {
    j=i+j;
    i=j-i;
  }
  return j;
}
double fib3(int n){
  double i, j, k,h;
  double t;
  i=1;j=0;k=0;h=1;
  while(n>0){
    if(n%2!=0){
      t=j*h;
      j=i*h + j*k + t;
      i=i*k + t;
    }
    t=h*h;
    h=2*k*h + t;
    k=k*k + t;
    n=n/2;
  }
  return j;
}
int main() {
  int numero;
  double fib;
  cin>>numero;
  fib = fib2(numero);
  cout << fib << endl;
  return 0;
}