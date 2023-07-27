/******* EJEMPLOS DEL LENGUAJE GRAFICADOR *******
documento
  encabezado
    titulo "Hola mundo" ftitulo
  fencabezado
  cuerpo
    #Comentario de linea
    e1 "Hola mundo" fe1
    e2 "Autor" fe2
    p "Esto es un parrafo" fp
    a href="http://localhost" "Ir a la pagina principal" fa
    img src="http://localhost/cat.jpg" alt="Es un gato" fimg
  fcuerpo
fdocumento

******** PALABRAS CLAVE Y SIGNOS QUE CORRESPONDEN AL LENGUAJE *******
#
*
/
=
"
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
#include <stack>

#define MICHI              0
#define SLASH              1
#define ASTERISCO          2
#define ETIQUETA_L         3
#define ETIQUETA_U         4
#define ATRIBUTO           5
#define IGUAL              6
#define COMILLA_DOBLE      7
#define CADENA_A           8
#define CADENA_E           9
#define CADENA_C           10

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
    string atributo, etiqueta, cadena_a, cadena_e, cadena_c;
    string codigo_html;
    //14 SON LOS ESTADOS DEL AUTOMATA
    //9 SON LOS ELEMENTOS QUE PERTENECEN AL LENGUAJE
    int tTransicion[14][11];
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
      ts.Insertar("meta", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("fmeta", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("cuerpo", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("fcuerpo", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("titulo", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("ftitulo", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("css", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("fcss", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("js", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("fjs", ETIQUETA_L, "pclave", vacio, vacio);
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
      ts.Insertar("fimg", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("div", ETIQUETA_L, "pclave", vacio, vacio);
      ts.Insertar("fdiv", ETIQUETA_L, "pclave", vacio, vacio);
      for(int ii=0;ii<14;ii++){
        for(int jj=0;jj<11;jj++){
          tTransicion[ii][jj]=ERROR;
        }
      }
      tTransicion[0][ETIQUETA_L]=1;
      tTransicion[0][ETIQUETA_U]=1;
      tTransicion[1][ATRIBUTO]=2;
      tTransicion[1][COMILLA_DOBLE]=6;
      tTransicion[1][ETIQUETA_L]=1;
      tTransicion[1][ETIQUETA_U]=1;
      tTransicion[1][SLASH]=10;
      tTransicion[1][MICHI]=9;
      tTransicion[2][IGUAL]=3;
      tTransicion[3][COMILLA_DOBLE]=4;
      tTransicion[4][CADENA_A]=5;
      tTransicion[5][COMILLA_DOBLE]=1;
      tTransicion[6][CADENA_E]=7;
      tTransicion[7][COMILLA_DOBLE]=8;
      tTransicion[8][ETIQUETA_L]=0;
      tTransicion[8][ETIQUETA_U]=0;
      tTransicion[0][MICHI]=9;
      tTransicion[9][CADENA_C]=0;
      tTransicion[0][SLASH]=10;
      tTransicion[10][ASTERISCO]=11;
      tTransicion[11][CADENA_C]=12;
      tTransicion[12][ASTERISCO]=13;
      tTransicion[13][SLASH]=0;
    }
    void agregarEspacios(int n) {
      while(n>0) {
        codigo_html += "\t";
        n--;
      }
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
        if (cad[i]=='\n') {
          linea++;
        }
        i++;
      }
      if(cad[i]=='\0'){
        return FIN;
      }
      /*AQUI PUEDE QUE SE TRATE DE UNA VARIABLE O UNA PALABRA CLAVE*/
      else if(isalpha(cad[i])){
        char tmp[100];
        int tmp_cont=0;
        if (cad[i-1] == '"') {
          char ct = cad[i-2];
          while(cad[i] != '"'){
            tmp[tmp_cont]=cad[i];
            tmp_cont++;
            i++;
          }
          if(ct == '=') {
            cadena_a = tmp;
            return CADENA_A;
          }
          cadena_e = tmp;
          return CADENA_E;
        }
        else if (cad[i-1] == '#') {
          while(cad[i] != '\n'){
            tmp[tmp_cont]=cad[i];
            tmp_cont++;
            i++;
          }
          cadena_c = tmp;
          return CADENA_C;
        }
        else if (cad[i-2] == '/' && cad[i-1] == '*') {
          while(cad[i] != '*' && cad[i+1] != '/'){
            tmp[tmp_cont]=cad[i];
            tmp_cont++;
            i++;
          }
          cadena_c = tmp;
          return CADENA_C;
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
          etiqueta = tmp;
          //buscando en la tabla de simbolos
          if(ts.BuscarPClave(lex,attr)){
            return attr.token;
          }
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
        // cout<<"Lexico: "<<token<<endl;
        // cout << "linea "<<linea << endl;
        if(token==FIN){
          return true;
        }
        else if(token==ETIQUETA_U){
          Atributos attr;
          if(!ts.Buscar(etiqueta,attr)){
            ts.Insertar(etiqueta,ETIQUETA_U,"pusuario",null,null);
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
          if(estado==0 || estado==1)/*VERIFICAR EL ESTADO FINAL*/
            return true;
          Error(200);
          return false;
        }
        // cout<<"(e"<<estado<<",t"<<token<<")"<<endl;
        estado=tTransicion[estado][token];
        if(estado==ERROR){
          Error(201);
          return false;
        }
      }
    }
    bool Semantico(){
      i=0;
      linea = 1;
      int token=0;
      estado=0;
      stack<string> pila;
      while(true){
        token=getToken();
        if(token==FIN){
          return true;
          break;
        }
        // Comprobar las etiquetas de cierre
        if(token==ETIQUETA_L || token==ETIQUETA_U) {
          if (!pila.empty() && (etiqueta.substr(1, string::npos) == pila.top()) && etiqueta.at(0) == 'f') {
            pila.pop();
          }
          else {
            pila.push(etiqueta);
          }
          // cout << "tag: " << etiqueta << endl;
        }
      }
      if (pila.empty()) {
        return true;
      }
      // cout << "Error: La pila no esta vacia" << endl;
      /* while (!pila.empty()) {
        cout << "tag: " << pila.top() << endl;
        pila.pop();
      } */
      return false;
    }
    bool Ejecucion(){
      i=0;
      linea = 1;
      int token=0, token_ant=-1;
      estado=0;
      stack<string> pila;
      codigo_html += "<!DOCTYPE html>\n";
      while(true){
        token=getToken();
        if(token==FIN){
          return true;
          break;
        }
        if(token==CADENA_E) {
          codigo_html += ">\n";
          agregarEspacios(pila.size());
          codigo_html += cadena_e;
          codigo_html += '\n';
        }
        else if(token==CADENA_C) {
          if(token_ant!=token){
            codigo_html += ">\n";
          }
          agregarEspacios(pila.size());
          codigo_html += "<!-- ";
          codigo_html += cadena_c;
          codigo_html += " -->\n";
        }
        else if(token==CADENA_A) {
          codigo_html += cadena_a;
          codigo_html += '"';
        }
        else if(token==ATRIBUTO) {
          codigo_html += " ";
          codigo_html += atributo;
          codigo_html += "=\"";
        }
        else if(token==ETIQUETA_L || token==ETIQUETA_U) {
          if(token_ant==ETIQUETA_L || token_ant==ETIQUETA_U || token_ant==CADENA_A) {
            if (etiqueta!="fcss" && etiqueta!="fimg" && etiqueta!="fmeta") {
              codigo_html += ">\n";
            }
          }
          if (!pila.empty() && (etiqueta.substr(1, string::npos) == pila.top()) && etiqueta.at(0) == 'f') {
            pila.pop();
            if (etiqueta!="fcss" && etiqueta!="fimg"  && etiqueta!="fmeta") {
              agregarEspacios(pila.size());
              codigo_html += "</";
            }
            if (token==ETIQUETA_L) {
              if(etiqueta == "fdocumento") {
                codigo_html += "html";
              }
              else if(etiqueta == "fencabezado") {
                codigo_html += "head";
              }
              else if(etiqueta == "fcuerpo") {
                codigo_html += "body";
              }
              else if(etiqueta == "ftitulo") {
                codigo_html += "title";
              }
              else if(etiqueta == "fjs") {
                codigo_html += "script";
              }
              else if(etiqueta == "fe1") {
                codigo_html += "h1";
              }
              else if(etiqueta == "fe2") {
                codigo_html += "h2";
              }
              else if(etiqueta == "fe3") {
                codigo_html += "h3";
              }
              else if(etiqueta == "fe4") {
                codigo_html += "h4";
              }
              else if(etiqueta == "fp") {
                codigo_html += "p";
              }
              else if(etiqueta == "fa") {
                codigo_html += "a";
              }
              else if(etiqueta == "fdiv") {
                codigo_html += "div";
              }
            }
            else if(token==ETIQUETA_U) {
              codigo_html += etiqueta;
            }
          }
          else {
            agregarEspacios(pila.size());
            pila.push(etiqueta);
            codigo_html += "<";
            if(token==ETIQUETA_L) {
              if(etiqueta == "documento") {
                codigo_html += "html";
              }
              else if(etiqueta == "encabezado") {
                codigo_html += "head";
              }
              else if(etiqueta == "meta") {
                codigo_html += "meta";
              }
              else if(etiqueta == "cuerpo") {
                codigo_html += "body";
              }
              else if(etiqueta == "titulo") {
                codigo_html += "title";
              }
              else if(etiqueta == "css") {
                codigo_html += "link";
              }
              else if(etiqueta == "js") {
                codigo_html += "script";
              }
              else if(etiqueta == "e1") {
                codigo_html += "h1";
              }
              else if(etiqueta == "e2") {
                codigo_html += "h2";
              }
              else if(etiqueta == "e3") {
                codigo_html += "h3";
              }
              else if(etiqueta == "e4") {
                codigo_html += "h4";
              }
              else if(etiqueta == "p") {
                codigo_html += "p";
              }
              else if(etiqueta == "a") {
                codigo_html += "a";
              }
              else if(etiqueta == "img") {
                codigo_html += "img";
              }
              else if(etiqueta == "div") {
                codigo_html += "div";
              }
            }
            else if(token==ETIQUETA_U) {
              codigo_html += etiqueta;
            }
          }
        }
        token_ant = token;
      }
      return false;
    }
    void Analizar(){
      if (Lexico()) {
      cout << "[+] Analisis Lexico: BIEN" << endl;
      if (Sintactico()) {
        cout << "[+] Analisis Sintatico: BIEN" << endl;
        if (Semantico()) {
          cout << "[+] Analisis Semantico: BIEN" << endl;
          if (Ejecucion()) {
            char file_name[] = "index.html";
            char c;
            string s;
            ofstream f;
            f.open(file_name);
            if (f.is_open()) {
              f.write(codigo_html.c_str(), codigo_html.size());
              f.close();
              cout << "[+] Se ha creado un archivo index.html con todo el codigo" << endl;
            }
            else {
              cout << "No se puede abrir el archivo " << file_name << endl;
            }
          }
          else {
            cout << "[-] Ha ocurrido un error en la traduccion" << endl;
          }
          // ts.Mostrar();
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
    }
    void Error(int nroError){
      cout<<"Error "<<nroError<<": ";
      if(nroError==100){
        cout<<"Error: No se reconoce el caracter "<<cad[i-1]<<" en la linea "<<linea;
      }
      else if(nroError==200){
        cout<<"Error 200 A. Sintactico";
      }
      else if(nroError==300){
        cout<<"Error 300 A. Semantico" << endl
        <<"Linea "<<linea<<", '"<<cad[i]<<"'"<<endl;
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
    obj->Analizar();
    f.close();
  }
  else {
    cout << "No se puede abrir el archivo: " << file_name << endl;
  }
  return 0;
}