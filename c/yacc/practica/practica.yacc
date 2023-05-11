%{
#include <stdio.h>
int yylex();
void yyerror(char *);
%}
%token A B C
%token FIN
%token ERROR
%%
expresion : q0 q1 | q0 q1 q2
q0 : A | C
q1 : A q1 | C | B
q2 : A | B q2
%%
int main() {
  yyparse();
  return 0;
}
void yyerror(char *s) {
  printf("Error de sintaxis: %s\n", s);
}
