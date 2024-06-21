#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#include <iostream>
#include <windows.h>
using namespace std;
/* Declaration */
/* Para compilar este archivo abre tu consola y ejecuta el siguiente comando:
g++ -mconsole -mwindows -municode gui_winapi_chatgpt.cpp -o output.exe
*/
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
  // Register the window class
  const wchar_t CLASS_NAME[] = L"MyWindowClass";
  WNDCLASS wc = { };
  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = CLASS_NAME;
  RegisterClass(&wc);
  // Create the window
  HWND hwnd = CreateWindowEx(
    0,
    CLASS_NAME,
    L"Mi primer programa",  // Título de la ventana Unicode
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
    NULL,
    NULL,
    hInstance,
    NULL
  );
  if (hwnd == NULL) {
    return 0;
  }
  ShowWindow(hwnd, nCmdShow);
  MSG msg;
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return 0;
}
/* Definition */
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
  switch (msg) {
    case WM_CREATE:
      cout << "Mi primer programa en c++ usando winapi" << endl;
      break;
    case WM_PAINT: {
      PAINTSTRUCT ps;
      HDC hdc = BeginPaint(hwnd, &ps);
      const wchar_t *texto = L"Hola, ¿Cómo estás?";
      RECT rect;
      GetClientRect(hwnd, &rect);
      rect.left = 20;
      rect.top = 20;
      DrawTextW(hdc, texto, -1, &rect, DT_SINGLELINE | DT_LEFT | DT_TOP);
      EndPaint(hwnd, &ps);
      break;
    }
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    case WM_COMMAND:
      break;
    default:
      return DefWindowProc(hwnd, msg, wParam, lParam);
  }
  return 0;
}