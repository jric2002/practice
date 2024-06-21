#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
/* Author: José Rodolfo (jric2002) */
/* Declaration */
/* Para compilar este archivo abre tu consola y ejecuta el siguiente comando:
g++ -mconsole -mwindows -municode gui_winapi_unicode.cpp -o output.exe
*/
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
  // Register the window class.
  const wchar_t CLASS_NAME[] = L"My first program";
  WNDCLASS wc = { };
  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = CLASS_NAME;
  RegisterClass(&wc);
  // Create the window.
  HWND hwnd = CreateWindowEx(
    0, // Optional window styles.
    CLASS_NAME, // Window class
    L"José Rodolfo", // Window text
    WS_OVERLAPPEDWINDOW, // Window style
    // Size and position
    CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
    NULL, // Parent window
    NULL, // Menu
    hInstance, // Instance handle
    NULL // Additional application data
    );
  if (hwnd == NULL) {
    return 0;
  }
  ShowWindow(hwnd, nCmdShow);
  // Run the message loop.
  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0) > 0) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return 0;
}
/* Definition */
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  switch (uMsg) {
    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;
    case WM_PAINT:
      PAINTSTRUCT ps;
      HDC hdc = BeginPaint(hwnd, &ps);
      // All painting occurs here, between BeginPaint and EndPaint.
      FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
      EndPaint(hwnd, &ps);
      return 0;
  }
  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}