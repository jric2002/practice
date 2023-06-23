# Traductor HTML
Para crear nuestra gramática necesitaremos definir algunas reglas.
## Palabras reservadas (P.R) de nuestro lenguaje
| LEXEMA | TOKEN | Tipo | Valor |
| :---: | :---: | :---: | :---: |
| documento | DOCUMENTO | P.R | - |
| fdocumento | FDOCUMENTO | P.R | - |
| encabezado | ENCABEZADO | P.R | - |
| fencabezado | FENCABEZADO | P.R | - |
| cuerpo | CUERPO | P.R | - |
| fcuerpo | FCUERPO | P.R | - |
| titulo | TITULO | P.R | - |
| ftitulo | FTITULO | P.R | - |
| css | CSS | P.R | - |
| js | JS | P.R | - |
| e1 | E1 | P.R | - |
| fe1 | FE1 | P.R | - |
| e2 | E2 | P.R | - |
| fe2 | FE2 | P.R | - |
| p | P | P.R | - |
| fp | FP | P.R | - |
| a | A | P.R | - |
| fa | FA | P.R | - |
| img | IMG | P.R | - |
| " | COMILLA_DOBLE | P.R | - |
| "mundo" | VALOR | Cadena | - |

P.R = Palabra Reservada

## Ejemplos de código de nuestro lenguaje
Hay ejemplo correctos e incorrectos debido a que a la hora de analizar el codigo de nuestro lenguaje nos avise de los errores.
Los ejemplos 1 y 2 son la manera correcta de usar la sintaxis de nuestro lenguaje.

### 1 ejemplo
```
documento
  encabezado
    titulo "Hola mundo" ftitulo
  fencabezado
  cuerpo
    #Comentario de linea
    /*Esto es un
    comentario multilinea*/
    e1 "Hola mundo" fe1
    e2 "Autor" fe2
    p "Esto es un parrafo" fp
    a href="http://localhost" "Ir a la pagina principal" fa
    img src="http://localhost/cat.jpg" alt="Es un gato" fimg
    usuario "Jose" fusuario
  fcuerpo
fdocumento
```

### 2 ejemplo
```
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
    div id="contenedor"
      a "hola mundo" fa
    fdiv
    usuario "Jose" fusuario
  fcuerpo
fdocumento
```

### 3 ejemplo
```
documento
  encabezado
    titulo "Hola mundo" ftitulo
  fencabezado
  cuerpo
    #Comentario de linea
    /*Esto es un
    comentario multilinea*/
    div id="header" class="header"
      e1 "Hola mundo" fe1
      usuario "Jose" fusuario
      p "Esto es un parrafo" fp
    fdiv
    a href="http://localhost" "Ir a la pagina principal" fa
    img src="http://localhost/cat.jpg" alt="Es un gato" fimg
  fcuerpo
fdocumento
```