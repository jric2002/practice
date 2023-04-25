%{
  #include <stdlib.h>
%}
PALABRAS_RESERVADAS       "int"|"char"|"if"|"else if"|"else"|"void"|"class"|"static"
IDENTIFICADOR             [_a-zA-Z]+
OPERADORES                "+"|"-"|"*"|"/"
DIGITO                    [0-9]
CADENA                    .*
%%
{PALABRAS_RESERVADAS}     {printf("Es una palabra reservada\n");}
{IDENTIFICADOR}           {printf("Es un identificador\n");}
{OPERADORES}              {printf("Es un operador\n");}
{DIGITO}                  {printf("Es un digito\n");}
{CADENA}                  {printf("Es una cadena\n");}
%%
int main() {
  yylex();
  return 0;
}