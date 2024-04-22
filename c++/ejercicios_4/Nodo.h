class Nodo{
  private:
    int dato;
    Nodo *sig;
  public:
    Nodo(int v){
      dato = v;
      sig = NULL;
    }
    Nodo *retSig(){
      return sig;
    }
    int retDato(){
      return dato;
    }
    void unirCon(Nodo *n){
      sig = n;
    }
};