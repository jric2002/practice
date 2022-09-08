#include <stdio.h>
/* Author: José Rodolfo (jric2002) */
/* Declaration */
void printLine(char, int);
void f(int **);
int main() {
  int *p;
  int n = 12;
  p = &n;
  printf("Address of n: %p\n", &n);
  printf("Value of n: %i\n", n);
  printLine('-', 30);
  printf("Address of p: %p\n", &p);
  printf("Value of p: %p\n", p);
  printf("*p: %i\n", *p);
  printLine('-', 30);
  f(&p);
  return 0;
}
/* Definition */
void printLine(char c, int a) {
  while (a--) {
    printf("%c", c);
  }
  printf("\n");
}
void f(int **rp) {
  printf("Address of rp: %p\n", &rp);
  printf("Value of rp: %p\n", rp);
  printf("*rp: %p\n", *rp);
  printf("**rp: %i\n", **rp);
}