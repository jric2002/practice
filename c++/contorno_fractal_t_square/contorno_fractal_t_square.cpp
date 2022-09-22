#include <iostream>
#include <windows.h>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
// Global variables
static TCHAR class_name[] = "Desktop App";
static TCHAR title_text[] = "Contorno fractal - T-square";
// Declaración del procedimiento de ventana
//void dibujarObjeto(HDC, int, int, int);
void dibujarLinea(HDC, int, int, int, int);
void dibujarBordeEsquinaSI(HDC, int, int, int);
void dibujarBordeEsquinaSD(HDC, int, int, int);
void dibujarBordeEsquinaII(HDC, int, int, int);
void dibujarBordeEsquinaID(HDC, int, int, int);
void dibujarEsquina(HDC, int, int, int, int);
void contornoFractal(HDC, int, int, int);
//void L(HDC, int, int, int, int);
int width, height;
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(
  HINSTANCE hThisInstance,
  HINSTANCE hPrevInstance,
  LPSTR lpszArgument,
  int nFunsterStil
) {
  HWND hwnd; // Manipulador de ventana
  MSG mensaje; // Mensajes recibidos por la aplicación
  WNDCLASSEX wincl; // Estructura de datos para la clase de ventana
  // Estructura de la ventana
  wincl.hInstance = hThisInstance;
  wincl.lpszClassName = LPCSTR(class_name);
  wincl.lpfnWndProc = WindowProcedure; // Esta función es invocada por Windows
  wincl.style = CS_DBLCLKS; // Captura los doble-clicks
  wincl.cbSize = sizeof(WNDCLASSEX);
  // Usar icono y puntero por defector
  wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
  wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
  wincl.lpszMenuName = NULL; // Sin menú
  wincl.cbClsExtra = 0; // Sin información adicional para la
  wincl.cbWndExtra = 0; // clase o la ventana
  // Usar el color de fondo por defecto para la ventana
  //wincl.hbrBackground = GetSysColorBrush(COLOR_WINDOW + 5);
  wincl.hbrBackground = (HBRUSH)(COLOR_WINDOW + 11);
  // Registrar la clase de ventana, si falla, salir del programa
  if (!RegisterClassEx(&wincl)) return 0;
  // La clase está registrada, crear la ventana
  hwnd = CreateWindowEx(
    0, // Posibilidades de variación
    class_name, // Nombre de la clase
    title_text, // Texto del título
    WS_OVERLAPPEDWINDOW, // Tipo por defecto
    CW_USEDEFAULT, // Windows decide la posición
    CW_USEDEFAULT, // donde se coloca la ventana
    600, // Ancho en pixels
    600, // Alto en pixels
    HWND_DESKTOP, // La ventana es hija del escritorio
    NULL, // Sin menú
    hThisInstance, // Manipulador de instancia
    NULL // No hay datos de creación de ventana
  );
  // Mostrar la ventana
  ShowWindow(hwnd, SW_SHOWDEFAULT);
  // Bucle de mensajes, se ejecuta hasta que haya error o GetMessage devuelva FALSE
  while (GetMessage(&mensaje, NULL, 0, 0) == TRUE) {
    // Traducir mensajes de teclas virtuales a mensajes de caracteres
    TranslateMessage(&mensaje);
    // Enviar mensaje al procedimiento de ventana
    DispatchMessage(&mensaje);
  }
  // Salir con valor de retorno
  return mensaje.wParam;
}
/* Definition */
/*void dibujarObjeto(HDC hdc, int x, int y, int a) {
  MoveToEx(hdc, x, y, NULL);
  LineTo(hdc, x + a, y);
  MoveToEx(hdc, x + a, y, NULL);
  LineTo(hdc, x + a, y + a);
  MoveToEx(hdc, x + a, y + a, NULL);
  LineTo(hdc, x, y + a);
  MoveToEx(hdc, x, y + a, NULL);
  LineTo(hdc, x, y);
}*/
void dibujarLinea(HDC hdc, int xi, int yi, int xf, int yf) {
  MoveToEx(hdc, xi, yi, NULL);
  LineTo(hdc, xf, yf);
}
// Dibujar bordes de esquina SI, SD, II, ID
void dibujarBordeEsquinaSI(HDC hdc, int x, int y, int a) {
  dibujarLinea(hdc, x, y, x, y + (a / 2)); // Borde SI -> Izq
  dibujarLinea(hdc, x, y, x + (a / 2), y); // Borde SI -> Sup
}
void dibujarBordeEsquinaSD(HDC hdc, int x, int y, int a) {
  dibujarLinea(hdc, x, y + (a / 2), x, y); // Borde SD -> Der
  dibujarLinea(hdc, x - (a / 2), y, x, y); // borde SD -> Sup
}
void dibujarBordeEsquinaII(HDC hdc, int x, int y, int a) {
  dibujarLinea(hdc, x, y - (a / 2), x, y); // Borde II -> Izq
  dibujarLinea(hdc, x, y, x + (a / 2), y); // Borde II -> Inf
}
void dibujarBordeEsquinaID(HDC hdc, int x, int y, int a) {
  dibujarLinea(hdc, x, y - (a / 2), x, y); // Borde ID -> Der
  dibujarLinea(hdc, x - (a / 2), y, x, y); // Borde ID -> Inf
}

void dibujarEsquina(HDC hdc, int x, int y, int a, int lu) {
  if (a > 6) { // Prueba cambiando el valor de 20 por 10 o tal vez 50
    if (lu == 1) {
      dibujarLinea(hdc, x - (a / 4), y - (a / 2), x + (a / 4), y - (a / 2)); // Superior
      dibujarLinea(hdc, x - (a / 2), y - (a / 4), x - (a / 2), y + (a / 4)); // Izquierda
      dibujarLinea(hdc, x, y + (a / 2), x - (a / 4), y + (a / 2)); // Inferior
      dibujarLinea(hdc, x + (a / 2), y, x + (a / 2), y - (a / 4)); // Derecha
      dibujarEsquina(hdc, x - (a / 2), y - (a / 2), a / 2, 1); // SI
      dibujarEsquina(hdc, x + (a / 2), y - (a / 2), a / 2, 2); // SD
      dibujarEsquina(hdc, x - (a / 2), y + (a / 2), a / 2, 3); // II
    }
    else if (lu == 2) {
      dibujarLinea(hdc, x - (a / 4), y - (a / 2), x + (a / 4), y - (a / 2)); // Superior
      dibujarLinea(hdc, x - (a / 2), y, x - (a / 2), y - (a / 4)); // Izquierda
      dibujarLinea(hdc, x, y + (a / 2), x + (a / 4), y + (a / 2)); // Inferior
      dibujarLinea(hdc, x + (a / 2), y - (a / 4), x + (a / 2), y + (a / 4)); // Derecha
      dibujarEsquina(hdc, x + (a / 2), y - (a / 2), a / 2, 2); // SD
      dibujarEsquina(hdc, x - (a / 2), y - (a / 2), a / 2, 1); // SI
      dibujarEsquina(hdc, x + (a / 2), y + (a / 2), a / 2, 4); // ID
    }
    else if (lu == 3) {
      dibujarLinea(hdc, x, y - (a / 2), x - (a / 4), y - (a / 2)); // Superior
      dibujarLinea(hdc, x - (a / 2), y - (a / 4), x - (a / 2), y + (a / 4)); // Izquierda
      dibujarLinea(hdc, x - (a / 4), y + (a / 2), x + (a / 4), y + (a / 2)); // Inferior
      dibujarLinea(hdc, x + (a / 2), y, x + (a / 2), y + (a / 4)); // Derecha
      dibujarEsquina(hdc, x - (a / 2), y + (a / 2), a / 2, 3); // II
      dibujarEsquina(hdc, x - (a / 2), y - (a / 2), a / 2, 1); // SI
      dibujarEsquina(hdc, x + (a / 2), y + (a / 2), a / 2, 4); // ID
    }
    else {
      dibujarLinea(hdc, x, y - (a / 2), x + (a / 4), y - (a / 2)); // Superior
      dibujarLinea(hdc, x - (a / 2), y, x - (a / 2), y + (a / 4)); // Izquierda
      dibujarLinea(hdc, x - (a / 4), y + (a / 2), x + (a / 4), y + (a / 2)); // Inferior
      dibujarLinea(hdc, x + (a / 2), y - (a / 4), x + (a / 2), y + (a / 4)); // Derecha
      dibujarEsquina(hdc, x + (a / 2), y + (a / 2), a / 2, 4); // ID
      dibujarEsquina(hdc, x + (a / 2), y - (a / 2), a / 2, 2); // SD
      dibujarEsquina(hdc, x - (a / 2), y + (a / 2), a / 2, 3); // II
    }
  }
  else {
    if (lu == 1) {
        dibujarBordeEsquinaSI(hdc, x, y, a);
        /*dibujarBordeEsquinaSD(hdc, x, y, a);
        dibujarBordeEsquinaII(hdc, x, y, a);*/
    }
    else if (lu == 2) {
      //dibujarBordeEsquinaSI(hdc, x, y, a);
      dibujarBordeEsquinaSD(hdc, x, y, a);
      //dibujarBordeEsquinaID(hdc, x, y, a);
    }
    else if (lu == 3) {
      //dibujarBordeEsquinaSI(hdc, x, y, a);
      dibujarBordeEsquinaII(hdc, x, y, a);
      //dibujarBordeEsquinaID(hdc, x, y, a);
    }
    else {
      //dibujarBordeEsquinaSD(hdc, x, y, a);
      //dibujarBordeEsquinaII(hdc, x, y, a);
      dibujarBordeEsquinaID(hdc, x, y, a);
    }
  }
}
void contornoFractal(HDC hdc, int x, int y, int a) {
  //Rectangle(hdc, x-a, y-a, x+a, y+a);
  //dibujarObjeto(hdc, x -(a / 2), y - (a / 2), a);
  dibujarLinea(hdc, x - (a / 4), y - (a / 2), x + (a / 4), y - (a / 2));
  dibujarLinea(hdc, x - (a / 4), y + (a / 2), x + (a / 4), y + (a / 2));
  dibujarLinea(hdc, x - (a / 2), y - (a / 4), x - (a / 2), y + (a / 4));
  dibujarLinea(hdc, x + (a / 2), y - (a / 4), x + (a / 2), y + (a / 4));
  // SI = 1; SD = 2; II = 3; ID = 4;
  // SI = superior izquierdo
  // SD = superior derecho
  // II = inferior izquierdo
  // ID = inferior derecho
  dibujarEsquina(hdc, x - (a / 2), y - (a / 2), a / 2, 1); // SI
  dibujarEsquina(hdc, x + (a / 2), y - (a / 2), a / 2, 2); // SD
  dibujarEsquina(hdc, x - (a / 2), y + (a / 2), a / 2, 3); // II
  dibujarEsquina(hdc, x + (a / 2), y + (a / 2), a / 2, 4); // ID
}
/*void L(HDC hdc, int xi, int yi, int xf, int yf) {
  MoveToEx(hdc, xi, yi, NULL);
  LineTo(hdc, xf, yf);
}*/
// Esta función es invocada por la función DispatchMessage()
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT mensaje, WPARAM wParam, LPARAM lParam) {
  switch (mensaje) { // Manipulador de mensaje
    case WM_CREATE:
      cout << title_text << endl;
      break;
    case WM_PAINT:
      PAINTSTRUCT ps;
      HDC hdc;
      hdc = BeginPaint(hwnd, &ps);
      RECT rect;
      GetWindowRect(hwnd, &rect);
      width = (rect.right - rect.left);
      height = (rect.bottom - rect.top);
      contornoFractal(hdc, width/2, height/2, 200);
      //L(hdc, 50, 50, 400, 400);
      EndPaint(hwnd, &ps);
      break;
    case WM_DESTROY:
      PostQuitMessage(0); // Envía el mensaje WM_QUIT a la cola de mensajes
      break;
    default: // Mensajes que no queremos manejar
      return DefWindowProc(hwnd, mensaje, wParam, lParam);
      break;
  }
  return 0;
}