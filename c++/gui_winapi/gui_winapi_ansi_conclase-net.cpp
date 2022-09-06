#include <iostream>
#include <windows.h>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
// Global variables
static TCHAR class_name[] = "Desktop App";
static TCHAR title_text[] = "José Rodolfo";
// Declaración del procedimiento de ventana
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
  wincl.hbrBackground = GetSysColorBrush(COLOR_WINDOW + 1);
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
    300, // Alto en pixels
    HWND_DESKTOP, // La ventana es hija del escritorio
    NULL, // Sin menú
    hThisInstance, // Manipulador de instancia
    NULL // No hay datos de creación de ventana
  );
  // Mostrar la ventana
  ShowWindow(hwnd, SW_SHOWDEFAULT);
  // Bucle de mensajes, se ejecuta hasta que haya error o GetMessage devuelva FALSE
  while (TRUE == GetMessage(&mensaje, NULL, 0, 0)) {
    // Traducir mensajes de teclas virtuales a mensajes de caracteres
    TranslateMessage(&mensaje);
    // Enviar mensaje al procedimiento de ventana
    DispatchMessage(&mensaje);
  }
  // Salir con valor de retorno
  return mensaje.wParam;
}
/* Definition */
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
      static TCHAR greeting[] = "Saludos gente...xD";
      TextOut(
        hdc,
        5, 5,
        greeting,
        sizeof(greeting)/sizeof(TCHAR)
      );
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