/******* EJEMPLOS DEL LENGUAJE GRAFICADOR *******
graficos(){
  cuadrado(100,100,50);
  circulo(125,125,50);
  rectangulo(100,100,200,50);
  linea(100,100,200,50);
}

graficos(){
  posx1=120;
  posx2=120;
  posx=175;
  posy=100;
  tam1=100;
  tam2=75;
  cuadrado(200,200,tam1);
  linea(100,100,tam1,50);
  rectangulo(posx1,posy,tam2,50);
  radio=24;
  circulo(posx,posy,radio);
}

graficos(){
  lado=50;
  cuadrado(100,100,lado);
  ancho=150;
  rectangulo(x1,y1,100,ancho);
}

******** PALABRAS CLAVE Y SIGNOS QUE CORRESPONDEN AL LENGUAJE *******
graficos
(
)
{
}
=
;
cuadrado
rectangulo
circulo
linea
,
VAR
NUM

******** LISTA DE SENTENCIAS ****************************************
ASIGNACIONES
DIBUJAR CUADRADO
DIBUJAR RECTANGULO
DIBUJAR CIRCULO
DIBUJAR LINEA

******** DIBUJAR EL AUTOMATA ****************************************

******** ERRORES SEMANTICOS *****************************************
LAS VARIABLES NO ESTAN REGISTRADAS EN LA TABLA DE SIMBOLOS
LAS VARIABLES NO TIENEN UN VALOR ASIGNADO

********************************************************************/

#include <iostream>
#include <string.h>
#include <list>

#define VAR         20
#define NUM         21

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
      ts.Insertar("",0,"pclave",vacio,vacio);
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
  Analisis*obj=new Analisis("graficos(){ posx1=120; posx2=120; posx=175; posy=100; tam1=100; tam2=75; cuadrado(200,200,tam1); linea(100,100,tam1,50); rectangulo(posx1,posy,tam2,tam2); radio=24; circulo(posx,posy,radio); }");
  obj->Analizar();
  return true;
}