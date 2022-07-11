#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415
/* Author: José Rodolfo (jric2002) */
int main() {
  /*
  int x = 10;
  float suma = PI + x;
  printf("La suma es: %.3f", suma);
  */
  /*
  char a = 'a'; //size 1byte    Rango: 0...255
  short b = -15; //size 2byte   Rango: -128...127
  int c = 1024; // size 2bytes  Rango: -32768...32767
  unsigned int d = 128; //size 2bytes  Rango: 0...65535
  long e = 123456; //size 4bytes
  float f = 15.678; //size 4bytes
  double g = 123123.123123; //size 8bytes
  printf("El elemento es: %.2f", f);
  */
  /*
  int num1, num2, suma, resta, mult, div;
  printf("Ingresa el primer numero: ");
  scanf("%i", &num1);
  printf("Ingresa el segundo numero: ");
  scanf("%i", &num2);
  //Process
  suma = num1 + num2;
  resta = num1 - num2;
  mult = num1 * num2;
  div = num1 / num2;
  printf("La suma es: %i\n", suma);
  printf("La resta es: %i\n", resta);
  printf("La multi. es: %i\n", mult);
  printf("La div es: %i\n", div);
  */
  /*
  float cel, fah;
  //Entrada de datos
  printf("Ingrese el dato(celsius): ");
  scanf("%f", &cel);
  //Proceso
  fah = ((9*cel)/5)+32;
  //Salida de datos
  printf("En grados Fahrenheit: %.1f", fah);
  */
  /*
  float co, ca, h;
  //Entrada de datos
  printf("Digite los 2 catetos: ");
  scanf("%f %f", &co, &ca);
  //Proceso
  h = sqrt(pow(co, 2)+pow(ca, 2));
  //Salida de datos
  printf("La hipotenusa del triangulo es: %.1f", h);
  */
  /*
  float angulo, radio, lon;
  //Entrada
  printf("Ingrese el angulo y el radio: ");
  scanf("%f %f", &angulo, &radio);
  //Proceso
  lon = ((angulo*2*PI)/360)*radio;
  //Salida
  printf("La longitud de la circunferencia es: %.2f", lon);
  */
  /*
  float bmayor, bmenor, h, area;
  //Entrada
  printf("Ingresa la base mayor, base menor y la altura: ");
  scanf("%f %f %f", &bmayor, &bmenor, &h);
  //Proceso
  area = ((bmayor + bmenor)*h)/2;
  //Salida
  printf("El area del trapecio es: %.f", area);
  */
  /*
  float pinicial, pfinal;
  printf("Ingrese precio de la compra: ");
  scanf("%f", &pinicial);
  pfinal = (pinicial*3)/20;
  printf("El precio final es: $%.1f", pfinal);
  */
  /*
  float sIn, aum, sFin;
  printf("Ingresa el salario inicial: ");
  scanf("%f", &sIn);
  aum = sIn*0.25;
  sFin = sIn + aum;
  printf("Tu nuevo salario es de: $%.1f", sFin);
  */
  /*
  int h, m, s, t1, t2, t3, total;
  printf("Digite el numero de horas: "); scanf("%i", &h);
  printf("Digite el numero de minutos: "); scanf("%i", &m);
  printf("Digite el numero de segundos: "); scanf("%i", &s);
  t1 = h*3600;
  t2 = m*60;
  t3 = s;
  total = t1 + t2 + t3;
  printf("El equivalente en segundos es: %i", total);
  */
  /*
  int n = 2;
  int a[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("Ingrese el valor para M[%i][%i]: ", (i + 1), (j + 1));
      scanf("%i", &a[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("\n%i", a[i][j]);
    }
  }
  */
  /*
  int *a, b = 2;
  a = &b;
  printf("%x\n", a);
  printf("%i\n", *a);
  printf("%x\n", &a);
  printf(".......\n");
  printf("%i\n", b);
  printf("%x", &b);
  */
  /*
  int numeros[3] = {1, 2, 3};
  int *puntero;
  puntero = numeros;
  printf("%x\n", puntero);
  printf("%x\n", puntero+1);
  printf("%x", puntero+2);
  */
  int a = 2, *b, **c;
  b = &a;
  c = &b;
  printf("%x\n", *b);
  printf("%x", **c);
  return 0;
}