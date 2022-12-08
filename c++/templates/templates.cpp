#include <iostream>
#include <cstring>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
// template <class T>
template <typename T>
class Node {
  private:
    Node<T> *next;
    T value;
  public:
    Node(T);
    Node<T> *nextNode();
    T getValue();
    bool pointTo(Node<T> *);
};
int main() {
  Node<int> *n1 = new Node<int>(10);
  Node<int> *n2 = new Node<int>(20);
  Node<int> *n3 = new Node<int>(40);
  n1->pointTo(n2);
  n2->pointTo(n3);
  for (Node<int> *it = n1; it != NULL; it = it->nextNode()) {
    cout << it->getValue() << " ";
  }
  cout << endl;
  delete n1, n2, n3;
  return 0;
}
/* Definition */
template <typename T>
Node<T>::Node(T v) {
  next = NULL;
  value = v;
}
template <typename T>
Node<T> *Node<T>::nextNode() {
  return next;
}
template <typename T>
T Node<T>::getValue() {
  return value;
}
template <typename T>
bool Node<T>::pointTo(Node<T> *n) {
  try {
    next = n;
    return true;
  }
  catch (...) {
    return false;
  }
}