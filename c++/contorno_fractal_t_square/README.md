# Contorno Fractal - T-square

![](./images/contorno-fractal-t-square.jpg)

## Compilar
Para compilar el código simplemente abra su terminal y ejecute:
```
g++ -mconsole -mwindows .\contorno_fractal_t_square.cpp -o .\output.exe
```

En la linea 108, puedes cambiar el numero 100 por un número mas pequeño o uno más grande.  
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

## Nota
Para dibujar 2 o más lineas debes tener en cuenta la dirección ya que puede que obtengas espacios entre lineas, es por eso que hice 3 pruebas para que veas como se dibujan las lineas en distintas direcciones. El ejemplo lo puedes en contrar en el archivo `dibujando_lineas_prueba.cpp`.

En papel:  
![Dibujando lineas - Prueba en papel](./images/dibujando-lineas-prueba-en-papel.jpg)

Con código:  
![Dibujando lineas - Prueba con código](./images/dibujando-lineas-prueba.png)

Más información: https://en.wikipedia.org/wiki/T-square_(fractal)