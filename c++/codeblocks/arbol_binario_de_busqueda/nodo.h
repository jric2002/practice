#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

class Nodo {
  private:
    int valor;
    Nodo *hijoIzq;
    Nodo *hijoDer;
  public:
    Nodo(int valor) {
      this->valor = valor;
      hijoIzq = NULL;
      hijoDer = NULL;
    }
    int retValor() {
      return valor;
    }
    void nuevoValor(int v) {
      valor = v;
    }
    Nodo *obtHijoIzq() {
      return hijoIzq;
    }
    Nodo *obtHijoDer() {
      return hijoDer;
    }
    void defHijoIzq(Nodo *hi) {
      hijoIzq = hi;
    }
    void defHijoDer(Nodo *hd) {
      hijoDer = hd;
    }
};

#endif // NODO_H_INCLUDED
