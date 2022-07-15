#include <iostream>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
struct Node {
  int value;
  struct Node *next;
};
int main() {
  struct Node *n1 = new struct Node;
  struct Node *n2 = new (struct Node);
  n1->value = 20;
  n2->value = 40;
  n1->next = n2;
  cout << n1->value << endl;
  cout << n1->next->value << endl;
  return 0;
}
/* Definition */