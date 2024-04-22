class Pila{
  private:
    Nodo *cima;
  public:
    Pila(){
      cima = nullptr;
    }
    void insertar(int valor){
      Nodo *n = new Nodo(valor);
      n->unirCon(cima);
      cima = n;
    }
    int retCima(){
      return cima->retDato();
    }
    Nodo* Cima(){
      return cima;
    }
    void eliminar(){
      if(cima != nullptr){
        Nodo *t = cima;
        cima = t->retSig();
        delete t;
      }
    }
    bool eliminar2(){
      if(cima != nullptr){
        Nodo *t = cima;
        cima = t->retSig();
        delete t;
        return true;
      }
      return false;
    }
    void limpiar(){
      while(true){
        bool t = eliminar2();
        if(t==false)
          break;
      }
    }
    void limpiar2(){
      while(eliminar2()){}
    }
    int tamanio(){
      Nodo *t = cima;
      int cont(0);
      while(t != nullptr){
        t = t->retSig();
        cont++;
      }
      return cont;
    }
    bool esVacio(){
      return cima == nullptr ? true:false;
      //if(cima == nullptr)
      //    return true;
      //return false;
    }
};