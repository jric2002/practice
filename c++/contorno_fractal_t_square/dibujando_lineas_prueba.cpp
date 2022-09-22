#include <iostream>
#include <windows.h>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
// Global variables
static TCHAR class_name[] = "Desktop App";
static TCHAR title_text[] = "Dibujando lineas - Prueba";
// Declaración del procedimiento de ventana
void dibujarLinea(HDC, int, int, int, int);
int width, height;
int x_ini, y_ini;
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
    500, // Ancho en pixels
    500, // Alto en pixels
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
void dibujarLinea(HDC hdc, int xi, int yi, int xf, int yf) {
  MoveToEx(hdc, xi, yi, NULL);
  LineTo(hdc, xf, yf);
}
// Esta función es invocada por la función DispatchMessage()
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT mensaje, WPARAM wParam, LPARAM lParam) {
  switch (mensaje) { // Manipulador de mensaje
    case WM_CREATE:
      cout << title_text << endl;
      RECT rect;
      GetWindowRect(hwnd, &rect);
      width = (rect.right - rect.left);
      height = (rect.bottom - rect.top);
      x_ini = width/5 + 100;
      y_ini = height/12 + 75;
      break;
    case WM_PAINT:
      PAINTSTRUCT ps;
      HDC hdc;
      hdc = BeginPaint(hwnd, &ps);
      static TCHAR titulo1[] = "Prueba 1:";
      static TCHAR prueba_11[] = "* 1 linea se dibuja de izquierda a derecha.";
      static TCHAR prueba_12[] = "* 2 linea se dibuja de derecha a izquierda.";
      TextOut(hdc, width/5, height/12 - 20, titulo1, strlen(titulo1));
      TextOut(hdc, width/5, height/12, prueba_11, strlen(prueba_11));
      TextOut(hdc, width/5, height/12 + 20, prueba_12, strlen(prueba_12));
      dibujarLinea(hdc, x_ini, y_ini, x_ini + 20, y_ini);
      dibujarLinea(hdc, x_ini + 40, y_ini, x_ini + 20, y_ini);
      static TCHAR titulo2[] = "Prueba 2:";
      static TCHAR prueba_21[] = "* 1 linea se dibuja de izquierda a derecha.";
      static TCHAR prueba_22[] = "* 2 linea se dibuja de izquierda a derecha.";
      TextOut(hdc, width/5, (3 * height)/12 + 10, titulo2, strlen(titulo2));
      TextOut(hdc, width/5, (3 * height)/12 + 30, prueba_21, strlen(prueba_21));
      TextOut(hdc, width/5, (3 * height)/12 + 50, prueba_22, strlen(prueba_22));
      dibujarLinea(hdc, x_ini, y_ini + 110, x_ini + 20, y_ini + 110);
      dibujarLinea(hdc, x_ini + 20, y_ini + 110, x_ini + 40, y_ini + 110);
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