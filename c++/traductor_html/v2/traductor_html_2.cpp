/******* EJEMPLOS DEL LENGUAJE GRAFICADOR *******
documento
  encabezado
    titulo "1 ejemplo" ftitulo
    css "./main.js"
    js "./main.js"
  fencabezado
  cuerpo
    e1 "1 ejemplo" fe1
    e2 "subtitulo" fe2
    p "párrafo 1" fp
    img "http://localhost/sub-1.jpg" "sub-1"
    e2 "subtitulo" fe2
    p "párrafo 2" fp
    img "http://localhost/sub-2.jpg" "sub-2"
    a "http://localhost" "Ir a inicio" fa
    p "Fin de la página web" fp
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
img
p
fp
a
fa

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

#define MICHI              0
#define SLASH              1
#define ASTERISCO          2
#define ETIQUETA_L         3
#define ETIQUETA_U         4
#define ATRIBUTO           5
#define IGUAL              6
#define COMILLA_DOBLE      7
#define CADENA             8

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
    void Mostrar(){
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
    string cadena;
    //22 SON LOS ESTADOS DEL AUTOMATA
    //14 SON LOS ELEMENTOS QUE PERTENECEN AL LENGUAJE
    int tTransicion[12][9];
    TablaSimbolos ts;
  public:
    Analisis(char input[100]){
      //Aquí hacer la apertura de archivo de texto plano
      strcpy(cad,input);
      i=0;
      ts.Insertar("documento", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("fdocumento", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("encabezado", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("fencabezado", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("cuerpo", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("fcuerpo", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("titulo", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("ftitulo", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("css", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("js", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("e1", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("fe1", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("e2", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("fe2", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("e3", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("fe3", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("e4", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("fe4", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("p", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("fp", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("a", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("fa", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("img", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("div", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("fdiv", ETIQUETA_L, "pclave", vacio, vacio);
      for(int ii=0;ii<12;ii++){
        for(int jj=0;jj<9;jj++){
          tTransicion[ii][jj]=ERROR;
        }
      }
      tTransicion[0][DOCUMENTO]=1;
      tTransicion[1][ENCABEZADO]=2;
      tTransicion[2][TITULO]=3;
      tTransicion[3][CADENA]=4;
      tTransicion[4][FTITULO]=2;
      tTransicion[2][JS]=6;
      tTransicion[6][CADENA]=2;
      tTransicion[2][CSS]=5;
      tTransicion[5][CADENA]=2;
      tTransicion[2][FENCABEZADO]=7;
      tTransicion[7][CUERPO]=8;
      tTransicion[8][E1]=9;
      tTransicion[9][CADENA]=10;
      tTransicion[10][FE1]=8;
      tTransicion[8][E2]=11;
      tTransicion[11][CADENA]=12;
      tTransicion[12][FE2]=8;
      tTransicion[8][P]=13;
      tTransicion[13][CADENA]=14;
      tTransicion[14][FP]=8;
      tTransicion[8][A]=15;
      tTransicion[15][CADENA]=16;
      tTransicion[16][FA]=8;
      tTransicion[16][CADENA]=17;
      tTransicion[17][FA]=8;
      tTransicion[8][IMG]=18;
      tTransicion[18][CADENA]=19;
      tTransicion[19][CADENA]=8;
      tTransicion[8][FCUERPO]=20;
      tTransicion[20][FDOCUMENTO]=21;
    }
    bool iselement(char c){
      char elements[100];
      /*AQUI DEBEN DE DEFINIR LOS CARACTERES QUE NO SEAN LETRAS O NUMEROS Y QUE CORRESPONDAN AL LENGUAJE*/
      /*NO DEBEN DE REPETIR CARACTERES*/
      strcpy(elements,"\"");/*<- AQUI*/
      int elements_cont=0;
      while(elements[elements_cont]!='\0'){
        if(elements[elements_cont]==c)
          return true;
        elements_cont++;
      }
      return false;
    }
    int getToken(){
      while(cad[i]==' ' || cad[i]=='\t' || cad[i]=='\n'){
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
        if(ts.BuscarPClave(lex,attr)){
          return attr.token;
        }
        return ERROR;
      }
      else if(iselement(cad[i])){
        char tmp[100];
        int tmp_cont=0;
        i++;
        while(cad[i] != '\"'){
          tmp[tmp_cont]=cad[i];
          tmp_cont++;
          i++;
        }
        i++;
        Atributos attr;
        string lex=tmp;
        if(ts.BuscarPClave(lex,attr)){
          return attr.token;
        }
        cadena=tmp;
        return CADENA;
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
        cout<<"Lexico: "<<token<<endl;
        if(token==FIN){
          return true;
        }
        else if(token==CADENA){
          Atributos attr;
          if(!ts.Buscar(cadena,attr)){
            ts.Insertar(cadena,CADENA,"cadena",null,null);
          }
        }
        else if(token==ERROR){
          //Aqui deben de mostrar el error lo más especifico posible
          Error(100);
          return false;
        }
      }
      // ts.Mostrar();
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
        // cout<<"(e"<<estado<<",t"<<token<<")"<<endl;
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
    string contenido;
    char codigo[100];
    char c;
    while (f.get(c)) {
      contenido += c;
    }
    // cout << contenido << endl;
    strcpy(codigo, contenido.c_str());
    Analisis *obj = new Analisis(codigo);
    // obj->Analizar();
    if (obj->Lexico()) {
      cout << "[+] Analisis Lexico: BIEN" << endl;
      if (obj->Sintactico()) {
        cout << "[+] Analisis Sintatico: BIEN" << endl;
        if (obj->Semantico()) {
          cout << "[+] Analisis Semantico: BIEN" << endl;
        }
        else {
          cout << "[-] Analisis Semantico: FALLO" << endl;
        }
      }
      else {
        cout << "[-] Analisis Sintatico: FALLO" << endl;
      }
    }
    else {
      cout << "[-] Analisis Lexico: FALLO" << endl;
    }
    obj->Sintactico();
    f.close();
  }
  else {
    cout << "No se puede abrir el archivo: " << file_name << endl;
  }
  return 0;
}