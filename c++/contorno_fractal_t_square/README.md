# Contorno Fractal - T-square
## Compilar
Para compilar el código simplemente abra su terminal y ejecute:
```
g++ -mconsole -mwindows .\contorno_fractal_t_square.cpp -o .\output.exe
```

En la linea 109, puedes cambiar el numero 100 por un número mas pequeño o uno más grande.  
![Contorno Fractal - T-square](./images/contorno-fractal-t-square-porcion-de-codigo.png)

Aquí te dejo algunos ejemplos:
* Con 100  
![Contorno Fractal - T-square](./images/contorno-fractal-t-square-1.png)
* Con 50  
![Contorno Fractal - T-square](./images/contorno-fractal-t-square-2.png)
* Con 25  
![Contorno Fractal - T-square](./images/contorno-fractal-t-square-3.png)
* Con 12  
![Contorno Fractal - T-square](./images/contorno-fractal-t-square-4.png)
* Con 6  
![Contorno Fractal - T-square](./images/contorno-fractal-t-square-5.png)

De las capturas de pantalla, ¿Te diste cuenta de un pequeño detalle?. Pues, ese espacio que apenas se logra ver entre las lineas es porque la primera linea se dibuja de izquierda a derecha y la segunda linea se dibuja de derecha a izquierda. Ahora, para poder eliminar ese espacio entre lineas se tiene que dibujar la primera linea de izquierda a derecha y luego la segunda linea de izquierda a derecha. Para probarlo, vamos a dibujar lineas para ambos casos, el código para dibujar las lineas lo puedes encontrar en el archivo `dibujando_lineas_prueba.cpp`.

En papel:  
![Dibujando lineas - Prueba en papel](./images/dibujando-lineas-prueba-en-papel.png)

Con código:  
![Dibujando lineas - Prueba con código](./images/dibujando-lineas-prueba.png)

Más información: https://en.wikipedia.org/wiki/T-square_(fractal)