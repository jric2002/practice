# Traductor HTML
Para crear nuestra gramática necesitaremos definir algunas reglas.
## Palabras reservadas (P.R) de nuestro lenguaje
| P.R | Etiqueta HTML |
| :---: | :---: |
| documento | DOCTYPE |
| encabezado | head |
| cuerpo | body |
| titulo | title |
| css | link:css |
| js | script |
| e1 | h1 |
| e2 | h2 |
| e3 | h3 |
| e4 | h4 |
| p | p |
| a | a |
| img | img |
| div | div |

## Ejemplos de código de nuestro lenguaje
### 1 ejemplo
```
documento
  encabezado
    titulo "Hola mundo"
  cuerpo
    e1 "Hola mundo"
    e2 "Autor"
    p "Esto es un párrafo"
    a "http://localhost" "Ir a la página principal"
    div
      img "http://localhost/cat.jpg" "Es un gato"
```

### 2 ejemplo
```
documento
  encabezado
    titulo "2 ejemplo"
    css "./main.js"
  cuerpo
    h1 "2 ejemplo"
    div
      h2 "subtitulo"
      p "párrafo 1"
    div
      h2 "subtitulo"
      p "párrafo 2"
    a "http://localhost" "Ir a inicio"
    p "Fin del página web"
    js "./main.js"
```

### 3 ejemplo
```
documento
  encabezado
    titulo "3 ejemplo"
    css "./main.js"
  cuerpo
    h1 "3 ejemplo"
    div
      div
        h2 "subtitulo"
        p "párrafo 1"
        img "http://localhost/sub-1.jpg" "sub-1"
      div
        h2 "subtitulo"
        p "párrafo 2"
        img "http://localhost/sub-2.jpg" "sub-2"
    div
      a "http://localhost" "Ir a inicio"
      p "Fin de la página web"
    js "./main.js"
```

### 4 ejemplo
```
documento
  encabezado
    titulo "4 ejemplo"
    css "./main.js"
  cuerpo
    h1 "4 ejemplo"
    div
      div
        h2 "subtitulo"
        p "párrafo 1"
        img "http://localhost/sub-1.jpg" "sub-1"
      div
        h2 "subtitulo"
        p "párrafo 2"
        img "http://localhost/sub-2.jpg" "sub-2"
      a "http://localhost" "Ver más"
    div
      a "http://localhost" "Ir a inicio"
      p "Fin de la página web"
    js "./main.js"
```

### 5 ejemplo
```
documento
  encabezado
    titulo "5 ejemplo"
    css "./main.js"
  cuerpo
    h1 "5 ejemplo"
    div
      h2 "subtitulo"
      p "párrafo 1"
      img "http://localhost/sub-1.jpg" "sub-1"
    div
      h2 "subtitulo"
      p "párrafo 2"
      img "http://localhost/sub-2.jpg" "sub-2"
      div
        h3 "subtitulo"
        p "parráfo 3"
        img
    div
      a "http://localhost" "Ir a inicio"
      p "Fin de la página web"
    js "./main.js"
```

### 6 ejemplo
```
documento
  encabezado
    titulo "6 ejemplo"
    css "./main.js"
  cuerpo
    h1 "6 ejemplo"
    div
    div
      div
        h2 "subtitulo"
        h3
        h4
        p "párrafo 1"
        img "http://localhost/sub-1.jpg" "sub-1"
      div
        h2 "subtitulo"
        h3
        h4
        p "párrafo 2"
        img "http://localhost/sub-2.jpg" "sub-2"
    div
      a "http://localhost" "Ir a inicio"
      p "Fin de la página web"
      p
    js "./main.js"
```

### 7 ejemplo
```
documento
  encabezado
    titulo
    css
  cuerpo
    h1
    div
      div
        h2
        p
        img "http://localhost/sub-1.jpg"
      div
        h2 "subtitulo"
        p "párrafo 2"
        img "http://localhost/sub-2.jpg" "sub-2"
    div
      a "http://localhost"
      p
    js "./main.js"
```

### 8 ejemplo
```
documento
  encabezado
    titulo "8 ejemplo"
    css "./main.js"
  cuerpo
    h1 "8 ejemplo"
    div
      div
      div
        h2 "subtitulo"
        p "párrafo 1"
        img "http://localhost/sub-1.jpg" "sub-1"
      div
        h2 "subtitulo"
        p "párrafo 2"
        img "http://localhost/sub-2.jpg"
        div
        div
    div
      a "http://localhost" "Ir a inicio"
      p "Fin de la página web"
    js "./main.js"
```

### 9 ejemplo
```
documento
  encabezado
    titulo "9 ejemplo"
    css "./main.js"
  cuerpo
    h1 "9 ejemplo"
    div
      div
        h2
        p
        img
      div
        h2 "subtitulo"
        p
        img "http://localhost/sub-2.jpg"
        div
    div
      a "http://localhost" "Ir a inicio"
      p "Fin de la página web"
    js
```

### 10 ejemplo
```
documento
  encabezado
    titulo "10 ejemplo"
    css "./main.js"
  cuerpo
    h1 "10 ejemplo"
    div
      h4 "Subtitulo"
    div
      div
        h2 "subtitulo"
        p "párrafo 1"
        a "http://localhost" "Ver más.."
        img "http://localhost/sub-1.jpg" "sub-1"
      div
      h2 "subtitulo"
      p "párrafo 2"
      a "http://localhost" "Ver más.."
      img "http://localhost/sub-2.jpg"
      div
    div
      a "http://localhost" "Ir a inicio"
      p "Fin de la página web"
    js "./main.js"
```