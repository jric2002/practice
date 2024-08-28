#include <iostream>

// Definición de la estructura del nodo
struct Node {
  int data;
  Node* next;
  Node(int value) : data(value), next(nullptr) {}
};

// Definición de la clase ListaEnlazada
class ListaEnlazada {
private:
  Node* head;
public:
  ListaEnlazada() : head(nullptr) {}
  // Método para insertar un elemento al principio de la lista
  void insertarAlPrincipio(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
  }
  // Método para insertar un elemento en una posición específica
  void insertarEnPosicion(int value, int posicion) {
    if (posicion <= 0) {
      insertarAlPrincipio(value);
      return;
    }
    Node* newNode = new Node(value);
    Node* current = head;
    int index = 0;
    while (current != nullptr && index < posicion - 1) {
      current = current->next;
      index++;
    }
    if (current == nullptr) {
      std::cout << "La posición está fuera del rango de la lista." << std::endl;
      delete newNode;
      return;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
  // Método para mostrar la lista
  void mostrar() {
    Node* current = head;
    while (current != nullptr) {
      std::cout << current->data << " -> ";
      current = current->next;
    }
    std::cout << "nullptr" << std::endl;
  }
  // Método para buscar un elemento en la lista
  bool buscar(int value) {
    Node* current = head;
    while (current != nullptr) {
      if (current->data == value) {
        return true;
      }
      current = current->next;
    }
    return false;
  }
  // Método para eliminar un elemento de la lista
  void eliminar(int value) {
    if (head == nullptr) {
      return; // La lista está vacía, no hay nada que eliminar
    }
    if (head->data == value) {
      Node* temp = head;
      head = head->next;
      delete temp;
      return;
    }
    Node* current = head;
    while (current->next != nullptr) {
      if (current->next->data == value) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        return;
      }
      current = current->next;
    }
  }
  // Método para eliminar los elementos duplicados
  void eliminarDuplicados() {
    Node* current = head;
    while (current != nullptr) {
      Node* runner = current;
      while (runner->next != nullptr) {
        if (runner->next->data == current->data) {
          Node* duplicate = runner->next;
          runner->next = runner->next->next;
          delete duplicate;
        } else {
          runner = runner->next;
        }
      }
      current = current->next;
    }
  }
  // Método para concatenar otra lista a la lista actual
  void concatenar(ListaEnlazada& otraLista) {
    if (head == nullptr) {
      head = otraLista.head;
      otraLista.head = nullptr;
      return;
    }
    Node* current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = otraLista.head;
    otraLista.head = nullptr;
  }
  // Método para invertir el orden de los elementos
  void invertir() {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while (curr != nullptr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
  }
  // Método para detectar ciclos en la lista
  bool detectarCiclo(Node*& inicioDelCiclo) {
    Node* lento = head;
    Node* rapido = head;
    while (rapido != nullptr && rapido->next != nullptr) {
      lento = lento->next;
      rapido = rapido->next->next;
      if (lento == rapido) {
        // Hay un ciclo, encontrar el inicio del ciclo
        inicioDelCiclo = head;
        Node* ciclo = lento;
        while (inicioDelCiclo != ciclo) {
          inicioDelCiclo = inicioDelCiclo->next;
          ciclo = ciclo->next;
        }
        return true;
      }
    }
    return false;
  }
  // Método para ordenar la lista en orden ascendente (algoritmo de inserción)
  void ordenarAscendente() {
    if (head == nullptr || head->next == nullptr) {
      return; // La lista está vacía o tiene un solo elemento
    }
    Node* sorted = nullptr;
    Node* current = head;
    while (current != nullptr) {
      Node* next = current->next;
      if (sorted == nullptr || sorted->data >= current->data) {
        current->next = sorted;
        sorted = current;
      } else {
        Node* temp = sorted;
        while (temp->next != nullptr && temp->next->data < current->data) {
          temp = temp->next;
        }
        current->next = temp->next;
        temp->next = current;
      }
      current = next;
    }
    head = sorted;
  }
  // Método para ordenar la lista en orden descendente (algoritmo de inserción)
  void ordenarDescendente() {
    if (head == nullptr || head->next == nullptr) {
      return; // La lista está vacía o tiene un solo elemento
    }
    Node* sorted = nullptr;
    Node* current = head;
    while (current != nullptr) {
      Node* next = current->next;
      if (sorted == nullptr || sorted->data <= current->data) {
        current->next = sorted;
        sorted = current;
      } else {
        Node* temp = sorted;
        while (temp->next != nullptr && temp->next->data > current->data) {
          temp = temp->next;
        }
        current->next = temp->next;
        temp->next = current;
      }
      current = next;
    }
    head = sorted;
  }
  // Destructor para liberar la memoria de los nodos
  ~ListaEnlazada() {
    while (head != nullptr) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }
};

int main() {
  ListaEnlazada lista;
  lista.insertarAlPrincipio(5);
  lista.insertarAlPrincipio(10);
  lista.insertarAlPrincipio(15);
  lista.mostrar();
  if (lista.buscar(10)) {
    std::cout << "El elemento 10 está en la lista." << std::endl;
  } else {
    std::cout << "El elemento 10 no está en la lista." << std::endl;
  }
  lista.eliminar(10);
  lista.mostrar();
  std::cout << std::endl;

  // Ejercicio 1
  std::cout << "Ejercicio 1" << std::endl;
  std::cout.fill('-');
  std::cout.width(20);
  std::cout << "" << std::endl;
  // Insertar elementos en posiciones específicas
  lista.insertarEnPosicion(20, 2); // Inserta 20 en la posición 1
  lista.insertarEnPosicion(25, 5); // Inserta 25 al final de la lista (posición fuera de rango)
  lista.mostrar();
  std::cout << std::endl;

  // Ejercicio 2
  std::cout << "Ejercicio 2" << std::endl;
  std::cout.fill('-');
  std::cout.width(20);
  std::cout << "" << std::endl;
  lista.insertarAlPrincipio(10);
  lista.insertarAlPrincipio(5); // Duplicado
  lista.mostrar();
  lista.eliminarDuplicados();
  lista.mostrar();
  std::cout << std::endl;

  // Ejercicio 3
  std::cout << "Ejercicio 3" << std::endl;
  std::cout.fill('-');
  std::cout.width(20);
  std::cout << "" << std::endl;
  ListaEnlazada lista1;
  lista1.insertarAlPrincipio(10);
  lista1.insertarAlPrincipio(5);
  lista1.insertarAlPrincipio(1);
  ListaEnlazada lista2;
  lista2.insertarAlPrincipio(30);
  lista2.insertarAlPrincipio(15);
  lista2.insertarAlPrincipio(12);
  std::cout << "Lista 1:" << std::endl;
  lista1.mostrar();
  std::cout << "Lista 2:" << std::endl;
  lista2.mostrar();
  lista1.concatenar(lista2);
  std::cout << "Lista concatenada:" << std::endl;
  lista1.mostrar();
  std::cout << std::endl;

  // Ejercicio 4
  std::cout << "Ejercicio 4" << std::endl;
  std::cout.fill('-');
  std::cout.width(20);
  std::cout << "" << std::endl;
  std::cout << "Lista original:" << std::endl;
  lista1.mostrar();
  std::cout << "Lista después de invertir:" << std::endl;
  lista1.invertir();
  lista1.mostrar();
  std::cout << std::endl;

  // Ejercicio 5
  std::cout << "Ejercicio 5" << std::endl;
  std::cout.fill('-');
  std::cout.width(20);
  std::cout << "" << std::endl;
  Node* inicioDelCiclo = nullptr;
  if (lista1.detectarCiclo(inicioDelCiclo)) {
    std::cout << "Se detectó un ciclo en la lista, comienza en el nodo con valor: " << inicioDelCiclo->data << std::endl;
  } else {
    std::cout << "No se detectaron ciclos en la lista." << std::endl;
  }
  std::cout << std::endl;

  // Ejercicio 6
  std::cout << "Ejercicio 6" << std::endl;
  std::cout.fill('-');
  std::cout.width(20);
  std::cout << "" << std::endl;
  std::cout << "Lista antes de ordenar:" << std::endl;
  lista1.mostrar();
  lista1.ordenarAscendente();
  std::cout << "Lista ordenada en orden ascendente:" << std::endl;
  lista1.mostrar();
  lista1.ordenarDescendente();
  std::cout << "Lista ordenada en orden descendente:" << std::endl;
  lista1.mostrar();
  return 0;
}