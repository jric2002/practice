/******* EJEMPLOS DEL LENGUAJE GRAFICADOR *******
documento
  encabezado
    titulo "Hola mundo" ftitulo
  fencabezado
  cuerpo
    e1 "Hola mundo" fe1
    e2 "Autor" fe2
    p "Esto es un párrafo" fp
    a "http://localhost" "Ir a la página principal" fa
    div
      img "http://localhost/cat.jpg" "Es un gato"
    fdiv
  fcuerpo
fdocumento

documento
  encabezado
    titulo "8 ejemplo" ftitulo
    css "./main.js"
  fencabezado
  cuerpo
    e1 "8 ejemplo" fe1
    div
      div
      div
        e2 "subtitulo" fe2
        p "párrafo 1" fp
        img "http://localhost/sub-1.jpg" "sub-1"
      fdiv
      div
        e2 "subtitulo" fe2
        p "párrafo 2" fp
        img "http://localhost/sub-2.jpg"
        div fdiv
      fdiv
    fdiv
    div
      a "http://localhost" "Ir a inicio" fa
      p "Fin de la página web" fp
    fdiv
    js "./main.js"
  fcuerpo
fdocumento

******** PALABRAS CLAVE Y SIGNOS QUE CORRESPONDEN AL LENGUAJE *******
documento
fdocumento
encabezado
fencabezado
cuerpo
fcuerpo
titulo
ftitulo
css
js
e1
fe1
e2
fe2
e3
fe3
e4
fe4
img
p
fp
a
fa
div
fdiv

******** LISTA DE SENTENCIAS ****************************************
DECLARAR Y DIFINIR PALABRAS RESERVADAS

******** DIBUJAR EL AUTOMATA ****************************************

******** ERRORES SEMANTICOS *****************************************
LAS PALABRAS RESERVADAS NO ESTAN REGISTRADAS EN LA TABLA DE SIMBOLOS
LAS PALABRAS RESERVADAS DEBEN ESTAR EN MINUSCULA

********************************************************************/

#include <iostream>
#include <string.h>
#include <list>
#include <fstream>
#include <cstring>

#define DOCUMENT       0
#define FDOCUMENT      1
#define ENCABEZADO     2
#define FENCABEZADO    3
#define CUERPO         4
#define FCUERPO        5
#define TITULO         6
#define FTITULO        7
#define CSS            8
#define JS             9
#define E1            10
#define FE1           11
#define E2            12
#define FE2           13
#define E3            14
#define FE3           15
#define E4            16
#define FE4           17
#define P             18
#define FP            19
#define A             20
#define FA            21
#define IMG           22
#define DIV           23
#define FDIV          24

#define FIN     666
#define ERROR   999

#define null "6c3e226b4d4795d518ab341b0824ec29"
#define vacio "-"
#define asignado "asignado"

using namespace std;

class Atributos{
  public:
    string lexema;
    int token;
    string tipo;
    string valor;
    string estado;
    Atributos(){
      lexema="";
      token=-999;
      tipo="";
      valor=null;
      estado="";
    }
    Atributos(string lex,int tok,string tip,string val,string est){
      lexema=lex;
      token=tok;
      tipo=tip;
      valor=val;
      estado=est;
    }
    Mostrar(){
      cout<<"Tipo("<<tipo<<") \t";
      cout<<"Lexema("<<lexema<<") \t";
      cout<<"Token("<<token<<") \t";
      cout<<"Valor("<<valor<<") \t";
      cout<<"Estado("<<estado<<")"<<endl;
    }
};

class TablaSimbolos{
  private:
    list<Atributos> tabla;
  public:
    void Insertar(string lex,int tok,string tip,string val,string est){
      Atributos attr(lex,tok,tip,val,est);
      tabla.push_back(attr);
    }
    bool ActualizarValor(string lex,string val){
      for (auto &item:tabla){
        if(item.lexema == lex){
          item.valor = val;
          return true;
        }
      }
      return false;
    }
    bool ActualizarEstado(string lex,string est){
      for (auto &item:tabla){
        if(item.lexema == lex){
          item.estado = est;
          return true;
        }
      }
      return false;
    }
    void Mostrar(){
      for (auto item:tabla){
        item.Mostrar();
      }
    }
    bool Buscar(string lex,Atributos&attr){
      for (auto item:tabla){
        if(item.lexema == lex){
          attr=item;
          return true;
        }
      }
      return false;
    }
    bool BuscarPClave(string lex,Atributos&attr){
      for (auto item:tabla){
        if(item.lexema == lex && item.tipo == "pclave"){
          attr=item;
          return true;
        }
      }
      return false;
    }
    list<Atributos> getTabla(){
      return tabla;
    }
};

class Analisis{
  private:
    int i;
    char cad[1000];
    int estado;
    string numero;
    string variable;
    //22 SON LOS ESTADOS DEL AUTOMATA
    //14 SON LOS ELEMENTOS QUE PERTENECEN AL LENGUAJE
    int tTransicion[22][14];
    TablaSimbolos ts;
  public:
    Analisis(char input[100]){
      //Aquí hacer la apertura de archivo de texto plano
      strcpy(cad,input);
      i=0;
      ts.Insertar("documento", DOCUMENTO, "pclave", vacio, vacio);
      ts.Insertar("fdocumento", FDOCUMENTO, "pclave", vacio, vacio);
      ts.Insertar("encabezado", ENCABEZADO, "pclave", vacio, vacio);
      ts.Insertar("fencabezado", FENCABEZADO, "pclave", vacio, vacio);
      ts.Insertar("cuerpo", CUERPO, "pclave", vacio, vacio);
      ts.Insertar("fcuerpo", FCUERPO, "pclave", vacio, vacio);
      ts.Insertar("titulo", TITULO, "pclave", vacio, vacio);
      ts.Insertar("ftitulo", FTITULO, "pclave", vacio, vacio);
      ts.Insertar("css", CSS, "pclave", vacio, vacio);
      ts.Insertar("js", JS, "pclave", vacio, vacio);
      ts.Insertar("e1", E1, "pclave", vacio, vacio);
      ts.Insertar("fe1", FE1, "pclave", vacio, vacio);
      ts.Insertar("e2", E2, "pclave", vacio, vacio);
      ts.Insertar("fe2", FE2, "pclave", vacio, vacio);
      ts.Insertar("e3", E3, "pclave", vacio, vacio);
      ts.Insertar("fe3", FE3, "pclave", vacio, vacio);
      ts.Insertar("e4", E4, "pclave", vacio, vacio);
      ts.Insertar("fe4", FE4, "pclave", vacio, vacio);
      ts.Insertar("p", P, "pclave", vacio, vacio);
      ts.Insertar("fp", FP, "pclave", vacio, vacio);
      ts.Insertar("a", A, "pclave", vacio, vacio);
      ts.Insertar("fa", FA, "pclave", vacio, vacio);
      ts.Insertar("img", IMG, "pclave", vacio, vacio);
      ts.Insertar("div", DIV, "pclave", vacio, vacio);
      ts.Insertar("fdiv", FDIV, "pclave", vacio, vacio);
      for(int ii=0;ii<22;ii++){
        for(int jj=0;jj<14;jj++){
          tTransicion[ii][jj]=ERROR;
        }
      }
      tTransicion[0][0]=1;
    }
    bool iselement(char c){
      char elements[100];
      /*AQUI DEBEN DE DEFINIR LOS CARACTERES QUE NO SEAN LETRAS O NUMEROS Y QUE CORRESPONDAN AL LENGUAJE*/
      /*NO DEBEN DE REPETIR CARACTERES*/
      strcpy(elements,"(){}=,;");/*<- AQUI*/
      int elements_cont=0;
      while(elements[elements_cont]!='\0'){
        if(elements[elements_cont]==c)
          return true;
        elements_cont++;
      }
      return false;
    }
    int getToken(){
      while(cad[i]==' '){
        i++;
      }
      if(cad[i]=='\0'){
        return FIN;
      }
      /*AQUI PUEDE QUE SE TRATE DE UNA VARIABLE O UNA PALABRA CLAVE*/
      else if(isalpha(cad[i])){
        char tmp[100];
        int tmp_cont=0;
        while(isalpha(cad[i]) || isdigit(cad[i])){
          tmp[tmp_cont]=cad[i];
          tmp_cont++;
          i++;
        }
        tmp[tmp_cont]='\0';
        Atributos attr;
        string lex=tmp;
        //buscando en la tabla de simbolos
        for(auto item:ts.getTabla()){
          if(ts.BuscarPClave(lex,attr)){
            return attr.token;
          }
        }
        variable=tmp;
        return VAR;
      }
      else if(isdigit(cad[i])){
        char tmp[100];
        int tmp_cont=0;
        while(isdigit(cad[i])){
          tmp[tmp_cont]=cad[i];
          tmp_cont++;
          i++;
        }
        tmp[tmp_cont]='\0';
        numero=tmp;
        return NUM;
      }
      else if(iselement(cad[i])){
        if(iselement(cad[i+1])){
          char tmp[3];
          tmp[0]=cad[i];
          tmp[1]=cad[i+1];
          tmp[2]='\0';
          Atributos attr;
          string lex=tmp;
          //cout<<"de 2:"<<lex<<endl;
          for(auto item:ts.getTabla()){
            if(ts.BuscarPClave(lex,attr)){
              i++;
              i++;
              return attr.token;
            }
          }
          //cout<<"salio"<<endl;
        }
        char tmp[2];
        tmp[0]=cad[i];
        tmp[1]='\0';
        Atributos attr;
        string lex=tmp;
        //cout<<"de 1:"<<lex<<endl;
        for(auto item:ts.getTabla()){
          if(ts.BuscarPClave(lex,attr)){
            i++;
            return attr.token;
          }
        }
        //cout<<"salio"<<endl;
        i++;
        return ERROR;
      }
      else{
        i++;
        return ERROR;
      }
    }
    bool Lexico(){
      i=0;
      int token=0;
      while(true){
        token=getToken();
        //cout<<"Lexico: "<<token<<endl;
        if(token==FIN){
          return true;
        }
        else if(token==VAR){
          Atributos attr;
          if(!ts.Buscar(variable,attr)){
            ts.Insertar(variable,VAR,"var",null,null);
          }
        }
        else if(token==ERROR){
          //Aqui deben de mostrar el error lo más especifico posible
          Error(100);
          return false;
        }
      }
    }
    bool Sintactico(){
      i=0;
      int token=0;
      estado=0;
      while(true){
        token=getToken();
        if(token==FIN){
          if(estado==21)/*VERIFICAR EL ESTADO FINAL*/
            return true;
          Error(2000);
          return false;
        }
        //cout<<"(e"<<estado<<",t"<<token<<")"<<endl;
        estado=tTransicion[estado][token];
        if(estado==ERROR){
          Error(400);
          return false;
        }
      }
      return false;
    }
    bool Semantico(){
      return true;
    }
    bool Ejecucion(){
      return true;
    }
    void Analizar(){
      if(Lexico()){
        if(Sintactico()){
          if(Semantico()){
            Ejecucion();
            //ts.Mostrar();
          }
        }
      }
    }
    void Error(int nroError){
      cout<<"Error "<<nroError<<": ";
      if(nroError==100){
        cout<<"Detallar el error 100";
      }
      else if(nroError==2000){
        cout<<"Detallar el error 2000";
      }
      else if(nroError==400){
        cout<<"Detallar el error 400";
      }
      else if(nroError==1500){
        cout<<"Detallar el error 1500";
      }
      else if(nroError==1600){
        cout<<"Detallar el error 1600";
      }
    }
};
int main()
{
  char file_name[] = "ejemplo.txt";
  ifstream f;
  f.open(file_name);
  if (f.is_open()) {
    string codigo;
    char c;
    while (f.get(c)) {
      codigo += c;
    }
    cout << codigo << endl;
    Analisis *obj = new Analisis(codigo);
    obj->Analizar();
    f.close();
  }
  else {
    cout << "No se puede abrir el archivo: " << file_name << endl;
  }
  return 0;
}