#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

class Abb {
  private:
    Nodo *raiz;
  public:
    Arbol() {
      raiz = NULL;
    }
    Nodo *retRaiz() {
      return raiz;
    }
    void Insertar(Nodo *aux, int valor) {
      if (aux == NULL) {
        Nodo *nuevo_nodo = new Nodo(valor);
        raiz = nuevo_nodo;
      }
      else {
        if (valor < aux->retValor()) {
          this->Insertar(aux->obtHijoIzq(), valor);
          aux->defHijoIzq(raiz);
        }
        else {
          this->Insertar(aux->obtHijoDer(), valor);
          aux->defHijoDer(raiz);
        }
        raiz = aux;
      }
    }
    /* Metodo eliminar */
    void Eliminar(Nodo *aux, int valor) {
      if (aux) {
        if (valor < aux->retValor()) {
          Eliminar(aux->obtHijoIzq(), valor);
          aux->defHijoIzq(raiz);
        }
        else {
          if (valor > aux->retValor()) {
            Eliminar(aux->obtHijoDer(), valor);
            aux->defHijoDer(raiz);
          }
          else {
            Nodo *ap1, *ap2, *ap3;
            ap3 = aux;
            if (!ap3->obtHijoDer()) {
              if (!ap3->obtHijoIzq()) {
                aux = NULL;
              }
              else {
                aux = ap3->obtHijoIzq();
              }
            }
            else {
              if (!ap3->obtHijoIzq()) {
                aux = ap3->obtHijoDer();
              }
              else {
                ap1 = ap3->obtHijoIzq();
                ap2 = ap3;
                // busca el nodo mas a la derecho del subarbol izquierdo
                while (ap1->obtHijoDer()) {
                  ap2 = ap1;
                  ap1 = ap1->obtHijoDer();
                }
                ap3->nuevoValor(ap1->retValor());
                if (ap3 == ap2) {
                  ap3->defHijoIzq(NULL);
                }
                else {
                  if (!ap1->obtHijoIzq()) {
                    ap2->defHijoDer(NULL);
                  }
                  else {
                    ap2->defHijoDer(ap1->obtHijoIzq());
                  }
                }
                ap3 = ap1;
              }
              delete ap3;
            }
          }
        }
        raiz = aux;
      }
    }
    void preOrden(Nodo *aux) {
      if (aux) {
        std::cout << aux->retValor() << " ";
        this->preOrden(aux->obtHijoIzq());
        this->preOrden(aux->obtHijoDer());
      }
    }
    void inOrden(Nodo *aux) {
      if (aux) {
        this->inOrden(aux->obtHijoIzq());
        std::cout << aux->retValor() << " ";
        this->inOrden(aux->obtHijoDer());
      }
    }
    void postOrden(Nodo *aux) {
      if (aux) {
        this->postOrden(aux->obtHijoIzq());
        this->postOrden(aux->obtHijoDer());
        std::cout << aux->retValor() << " ";
      }
    }
    int alturaArbol(Nodo *aux) {
      if (aux == NULL) {
        return 0;
      }
      if (aux->obtHijoIzq() == NULL && aux->obtHijoDer() == NULL) {
        return 1;
      }
      return std::max(alturaArbol(aux->obtHijoIzq()), alturaArbol(aux->obtHijoDer())) + 1;
    }
    int cantidadNodos(Nodo *aux) {
      if (aux != NULL) {
        int medio = 1;
        int cantidad_nodos_izq = cantidadNodos(aux->obtHijoIzq());
        int cantidad_nodos_der = cantidadNodos(aux->obtHijoDer());
        return cantidad_nodos_izq + cantidad_nodos_der + medio;
      }
    }
    bool buscarNodo(Nodo *aux, int valor) {
      if (aux == NULL) {
        return false;
      }
      else if (aux->retValor() == valor) {
        return true;
      }
      else if (aux->retValor() > valor) {
        return buscarNodo(aux->obtHijoIzq(), valor);
      }
      else {
        return buscarNodo(aux->obtHijoDer(), valor);
      }
    }
    void codificar(Nodo *aux) {
      if (aux) {
        if (aux->obtHijoIzq() != NULL && aux->obtHijoDer() != NULL) {
          std::cout << "1";
        }
        else {
          std::cout << "0";
        }
        this->codificar(aux->obtHijoIzq());
        this->codificar(aux->obtHijoDer());
      }
    }
    void Mostrar(Nodo *aux, int c) {
      if (aux != NULL) {
        this->Mostrar(aux->obtHijoDer(), c + 1);
        for (int i = 0; i < c; i++) {
          std::cout << "    ";
        }
        std::cout << aux->retValor() << std::endl;
        this->Mostrar(aux->obtHijoIzq(), c + 1);
      }
    }
    void MostrarArbolEspecular(Nodo *aux, int c) {
      if (aux != NULL) {
        this->MostrarArbolEspecular(aux->obtHijoIzq(), c + 1);
        for (int i = 0; i < c; i++) {
          std::cout << "    ";
        }
        std::cout << aux->retValor() << std::endl;
        this->MostrarArbolEspecular(aux->obtHijoDer(), c + 1);
      }
    }
};

#endif // ABB_H_INCLUDED
