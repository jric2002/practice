%{
#include <stdio.h>
extern int yylex();
extern void yyerror(char *);
%}
%token NUMERO
%token MAS MENOS MULTIPLICACION DIVISION
%token PARENTESIS_IZQUIERDO PARENTESIS_DERECHO
%%
expresion: termino
         | expresion MAS termino
         | expresion MENOS termino
termino: factor
       | termino MULTIPLICACION factor
       | termino DIVISION factor
factor: NUMERO
      | PARENTESIS_IZQUIERDO expresion PARENTESIS_DERECHO
%%
int main() {
  yyparse();
  return 0;
}
void yyerror(char *s) {
  printf("Error de sintaxis: %s\n", s);
}