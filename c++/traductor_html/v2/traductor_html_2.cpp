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
    int linea;
    int estado;
    string atributo, etiqueta_u, cadena;
    //15 SON LOS ESTADOS DEL AUTOMATA
    //9 SON LOS ELEMENTOS QUE PERTENECEN AL LENGUAJE
    int tTransicion[15][9];
    TablaSimbolos ts;
  public:
    Analisis(char input[100]){
      //Aquí hacer la apertura de archivo de texto plano
      strcpy(cad,input);
      i=0;
      ts.Insertar("#", MICHI, "pclave", vacio, vacio);
      ts.Insertar("*", ASTERISCO, "pclave", vacio, vacio);
      ts.Insertar("/", SLASH, "pclave", vacio, vacio);
      ts.Insertar("=", IGUAL, "pclave", vacio, vacio);
      ts.Insertar("\"", COMILLA_DOBLE, "pclave", vacio, vacio);
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
      for(int ii=0;ii<15;ii++){
        for(int jj=0;jj<9;jj++){
          tTransicion[ii][jj]=ERROR;
        }
      }
      tTransicion[0][ETIQUETA_L]=1;
      tTransicion[0][ETIQUETA_U]=1;
      tTransicion[1][ATRIBUTO]=2;
      tTransicion[1][COMILLA_DOBLE]=7;
      tTransicion[1][ETIQUETA_L]=0;
      tTransicion[1][ETIQUETA_U]=0;
      tTransicion[2][IGUAL]=3;
      tTransicion[3][COMILLA_DOBLE]=4;
      tTransicion[4][CADENA]=5;
      tTransicion[5][COMILLA_DOBLE]=6;
      tTransicion[6][ATRIBUTO]=2;
      tTransicion[6][ETIQUETA_L]=0;
      tTransicion[6][ETIQUETA_U]=0;
      tTransicion[6][COMILLA_DOBLE]=7;
      tTransicion[7][CADENA]=8;
      tTransicion[8][COMILLA_DOBLE]=9;
      tTransicion[9][ETIQUETA_L]=0;
      tTransicion[9][ETIQUETA_U]=0;
      tTransicion[0][MICHI]=10;
      tTransicion[10][CADENA]=0;
      tTransicion[0][SLASH]=11;
      tTransicion[11][ASTERISCO]=12;
      tTransicion[12][CADENA]=13;
      tTransicion[13][ASTERISCO]=14;
      tTransicion[14][SLASH]=0;
    }
    bool iselement(char c){
      char elements[100];
      /*AQUI DEBEN DE DEFINIR LOS CARACTERES QUE NO SEAN LETRAS O NUMEROS Y QUE CORRESPONDAN AL LENGUAJE*/
      /*NO DEBEN DE REPETIR CARACTERES*/
      strcpy(elements,"=\"*/#");/*<- AQUI*/
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
        if (cad[i]=='\n') {
          linea++;
        }
      }
      if(cad[i]=='\0'){
        return FIN;
      }
      /*AQUI PUEDE QUE SE TRATE DE UNA VARIABLE O UNA PALABRA CLAVE*/
      else if(isalpha(cad[i])){
        char tmp[100];
        int tmp_cont=0;
        if (cad[i-1] == '"') {
          while(cad[i] != '"'){
            tmp[tmp_cont]=cad[i];
            tmp_cont++;
            i++;
          }
          cadena = tmp;
          return CADENA;
        }
        else if (cad[i-1] == '#') {
          while(cad[i] != '\n'){
            tmp[tmp_cont]=cad[i];
            tmp_cont++;
            i++;
          }
          cadena = tmp;
          return CADENA;
        }
        else if (cad[i-2] == '/' && cad[i-1] == '*') {
          while(cad[i] != '*' && cad[i+1] != '/'){
            tmp[tmp_cont]=cad[i];
            tmp_cont++;
            i++;
          }
          cadena = tmp;
          return CADENA;
        }
        else {
          while(isalnum(cad[i])){
            tmp[tmp_cont]=cad[i];
            tmp_cont++;
            i++;
          }
          tmp[tmp_cont]='\0';
          if (cad[i] == '=') {
            atributo = tmp;
            return ATRIBUTO;
          }
          Atributos attr;
          string lex=tmp;
          //buscando en la tabla de simbolos
          if(ts.BuscarPClave(lex,attr)){
            return attr.token;
          }
          etiqueta_u = tmp;
          return ETIQUETA_U;
        }
      }
      else if(iselement(cad[i])){
        Atributos attr;
        string lex;
        lex += cad[i];
        i++;
        if(ts.BuscarPClave(lex,attr)){
          return attr.token;
        }
        return ERROR;
      }
      else{
        i++;
        return ERROR;
      }
    }
    bool Lexico(){
      i=0;
      linea = 1;
      int token=0;
      while(true){
        token=getToken();
        cout<<"Lexico: "<<token<<endl;
        if(token==FIN){
          return true;
        }
        else if(token==ETIQUETA_U){
          Atributos attr;
          if(!ts.Buscar(etiqueta_u,attr)){
            ts.Insertar(etiqueta_u,ETIQUETA_U,"pusuario",null,null);
          }
        }
        else if (token==ATRIBUTO) {
          Atributos attr;
          if(!ts.Buscar(atributo, attr)){
            ts.Insertar(atributo,ATRIBUTO,"atributo",null,null);
          }
        }
        else if(token==ERROR){
          //Aqui deben de mostrar el error lo más especifico posible
          Error(100);
          return false;
        }
      }
      ts.Mostrar();
    }
    bool Sintactico(){
      i=0;
      linea = 1;
      int token=0;
      estado=0;
      while(true){
        token=getToken();
        if(token==FIN){
          if(estado==0)/*VERIFICAR EL ESTADO FINAL*/
            return true;
          Error(200);
          return false;
        }
        cout<<"(e"<<estado<<",t"<<token<<")"<<endl;
        estado=tTransicion[estado][token];
        if(estado==ERROR){
          Error(201);
          return false;
        }
      }
      return false;
    }
    bool Semantico(){
      i=0;
      linea = 1;
      int token=0;
      estado=0;
      while(true){
        token=getToken();
        if(token==FIN){
          return true;
        }
        // Comprobar las etiquetas de cierre
      }
      return false;
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
        cout<<"Error 100 A. Lexico";
      }
      else if(nroError==200){
        cout<<"Error 200 A. Sintactico";
      }
      else if(nroError==300){
        cout<<"Error 300 A. Semantico" << endl
        <<"Linea "<<linea<<", '"<<cad[i]<<"'"<<endl;
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
    f.close();
  }
  else {
    cout << "No se puede abrir el archivo: " << file_name << endl;
  }
  return 0;
}