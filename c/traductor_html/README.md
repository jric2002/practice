# Traductor HTML
Para crear nuestra gramática necesitaremos definir algunas reglas.
## Palabras reservadas (P.R) de nuestro lenguaje
| P.R | Etiqueta HTML |
| :---: | :---: |
| documento | DOCTYPE |
| fdocumento | DOCTYPE |
| encabezado | head |
| fencabezado | head |
| cuerpo | body |
| fcuerpo | body |
| titulo | title |
| ftitulo | title |
| css | link:css |
| js | script |
| e1 | h1 |
| fe1 | h1 |
| e2 | h2 |
| fe2 | h2 |
| e3 | h3 |
| fe3 | h3 |
| e4 | h4 |
| fe4 | h4 |
| p | p |
| fp | p |
| fa | a |
| img | img |
| div | div |
| fdiv | div |

## Ejemplos de código de nuestro lenguaje
### 1 ejemplo
```
documento
  encabezado
    titulo "Hola mundo" ftitulo
  fencabezado
  cuerpo
    e1 "Hola mundo" fe1
    e2 "Autor" fe2
    p "Esto es un párrafo" fp
    a "http://localhost" "Ir a la página principal" fa
    div
      img "http://localhost/cat.jpg" "Es un gato"
    fdiv
  fcuerpo
fdocumento
```

### 2 ejemplo
```
documento
  encabezado
    titulo "2 ejemplo" ftitulo
    css "./main.js"
  fencabezado
  cuerpo
    e1 "2 ejemplo" fe1
    div
      e2 "subtitulo" fe2
      p "párrafo 1" fp
    fdiv
    div
      e2 "subtitulo" fe2
      p "párrafo 2" fp
    fdiv
    a "http://localhost" "Ir a inicio" fa
    p "Fin del página web" fp
    js "./main.js"
  fcuerpo
fdocumento
```

### 3 ejemplo
```
documento
  encabezado
    titulo "3 ejemplo" ftitulo
    css "./main.js"
  fencabezado
  cuerpo
    e1 "3 ejemplo" fe1
    div
      div
        e2 "subtitulo" fe2
        p "párrafo 1" fp
        img "http://localhost/sub-1.jpg" "sub-1"
      fdiv
    fdiv
      div
        e2 "subtitulo" fe2
        p "párrafo 2" fp
        img "http://localhost/sub-2.jpg" "sub-2"
        fdiv
    div
      a "http://localhost" "Ir a inicio" fa
      p "Fin de la página web" fp
    fdiv
    js "./main.js"
  fcuerpo
fdocumento
```

### 4 ejemplo
```
documento
  encabezado
    titulo "4 ejemplo" ftitulo
    css "./main.js"
  fencabezado
  cuerpo
    e1 "4 ejemplo" fe1
    div
      div
        e2 "subtitulo" fe2
        p "párrafo 1" fp
        img "http://localhost/sub-1.jpg" "sub-1"
      fdiv
      div
        e2 "subtitulo" fe2
        p "párrafo 2" fp
        img "http://localhost/sub-2.jpg" "sub-2"
      fdiv
      a "http://localhost" "Ver más" fa
    fdiv
    div
      a "http://localhost" "Ir a inicio" fa
      p "Fin de la página web" fp
    fdiv
    js "./main.js"
  fcuerpo
fdocumento
```

### 5 ejemplo
```
documento
  encabezado
    titulo "5 ejemplo" ftitulo
    css "./main.js"
  fencabezado
  cuerpo
    e1 "5 ejemplo" fe1
    div
      e2 "subtitulo" fe2
      p "párrafo 1" fp
      img "http://localhost/sub-1.jpg" "sub-1"
    fdiv
    div
      e2 "subtitulo" fe2
      p "párrafo 2" fp
      img "http://localhost/sub-2.jpg" "sub-2"
      div
        e3 "subtitulo" fe3
        p "parráfo 3" fp
        img
      fdiv
    fdiv
    div
      a "http://localhost" "Ir a inicio" fa
      p "Fin de la página web" fp
    fdiv
    js "./main.js"
  fcuerpo
fdocumento
```

### 6 ejemplo
```
documento
  encabezado
    titulo "6 ejemplo" ftitulo
    css "./main.js"
  fencabezado
  cuerpo
    e1 "6 ejemplo" fe1
    div fdiv
    div
      div
        e2 "subtitulo" fe2
        e3 fe3
        e4
        fe4
        p "párrafo 1" fp
        img "http://localhost/sub-1.jpg" "sub-1"
      fdiv
      div
        e2 "subtitulo" fe2
        e3 fe3
        e4 fe4
        p "párrafo 2" fp
        img "http://localhost/sub-2.jpg" "sub-2"
      fdiv
    fdiv
    div
      a "http://localhost" "Ir a inicio" fa
      p "Fin de la página web" fp
      p
      fp
    fdiv
    js "./main.js"
  fcuerpo
fdocumento
```

### 7 ejemplo
```
documento
  encabezado
    titulo ftitulo
    css
  fencabezado
  cuerpo
    e1 fe1
    div
      div
        e2
        p
        img "http://localhost/sub-1.jpg"
      fdiv
      div
        e2 "subtitulo"
        p "párrafo 2" fp
        img "http://localhost/sub-2.jpg" "sub-2"
      fdiv
    fdiv
    div
      a "http://localhost" fa
      p fp
    fdiv
    js "./main.js"
  fcuerpo
fdocumento
```

### 8 ejemplo
```
documento
  encabezado
    titulo "8 ejemplo" ftitulo
    css "./main.js"
  fencabezado
  cuerpo
    e1 "8 ejemplo" fe1
    div
      div
      div
        e2 "subtitulo" fe2
        p "párrafo 1" fp
        img "http://localhost/sub-1.jpg" "sub-1"
      fdiv
      div
        e2 "subtitulo" fe2
        p "párrafo 2" fp
        img "http://localhost/sub-2.jpg"
        div fdiv
      fdiv
    fdiv
    div
      a "http://localhost" "Ir a inicio" fa
      p "Fin de la página web" fp
    fdiv
    js "./main.js"
  fcuerpo
fdocumento
```

### 9 ejemplo
```
documento
  encabezado
    titulo "9 ejemplo" ftitulo
    css "./main.js"
  fencabezado
  cuerpo
    e1 "9 ejemplo" fe1
    div
      div
        e2 fe2
        p fp
        img
      fdiv
      div
        e2 "subtitulo" fe2
        p fp
        img "http://localhost/sub-2.jpg"
        div fdiv
      fdiv
    fdiv
    div
      a "http://localhost" "Ir a inicio" fa
      p "Fin de la página web" fp
    fdiv
    js
  fcuerpo
fdocumento
```

### 10 ejemplo
```
documento
  encabezado
    titulo "10 ejemplo" ftitulo
    css "./main.js"
  fencabezado
  cuerpo
    e1 "10 ejemplo" fe1
    div
      e4 "Subtitulo" fe4
    fdiv
    div
      div
        e2 "subtitulo" fe2
        p "párrafo 1" fp
        a "http://localhost" "Ver más.." fa
        img "http://localhost/sub-1.jpg" "sub-1"
      fdiv
      div fdiv
      e2 "subtitulo" fe2
      p "párrafo 2" fp
      a "http://localhost" "Ver más.." fa
      img "http://localhost/sub-2.jpg"
      div fdiv
    fdiv
    div
      a "http://localhost" "Ir a inicio" fa
      p "Fin de la página web" fp
    fdiv
    js "./main.js"
  fcuerpo
fdocumento
```