%{
#include "y.tab.h"
%}
%%
"a"         { return A; }
"b"         { return B; }
"c"         { return C; }
"$"         { return FIN; }
[ \t\n]     { /* ignorar espacios en blanco */ }
.           { printf("Caracter desconocido: %s\n", yytext); return ERROR; }
%%
int yywrap() {
  return 1;
}