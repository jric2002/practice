#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void mochila(int p[], int b[], int x[], int n) {
  int aux[n] = {0};
  for (int i = 0; i < n; i++) {
    aux[i] = b[i] / p[i];
  }
}
int main() {
  int n = 3;
  int p[n] = {15, 12, 8};
  int b[n] = {40, 36, 22};
  int x[n] = {0};
  return 0;
}