%{
#include "y.tab.h"
%}
%%
[0-9]+      { yylval = atoi(yytext); return NUMERO; }
"+"         { return MAS; }
"-"         { return MENOS; }
"*"         { return MULTIPLICACION; }
"/"         { return DIVISION; }
"("         { return PARENTESIS_IZQUIERDO; }
")"         { return PARENTESIS_DERECHO; }
[ \t\n]     { /* ignorar espacios en blanco */ }
.           { printf("Caracter desconocido: %s\n", yytext); }
%%
int yywrap() {
  return 1;
}