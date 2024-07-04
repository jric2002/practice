#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

#include <windows.h>
#include <ctime>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void DrawDigit(HDC hdc, int number, int x, int y, int size, COLORREF onColor, COLORREF offColor);
void DrawSegment(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
  const wchar_t CLASS_NAME[] = L"MyWindowClass";
  WNDCLASS wc = { };
  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = CLASS_NAME;
  RegisterClass(&wc);

  HWND hwnd = CreateWindowEx(
    0,
    CLASS_NAME,
    L"Reloj Digital",
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, 800, 400,
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

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  switch (uMsg) {
    case WM_CREATE:
      SetTimer(hwnd, 1, 1000, NULL);
      break;

    case WM_TIMER:
      InvalidateRect(hwnd, NULL, TRUE);
      break;

    case WM_PAINT: {
      PAINTSTRUCT ps;
      HDC hdc = BeginPaint(hwnd, &ps);

      time_t now = time(0);
      struct tm *ltm = localtime(&now);

      int hours = ltm->tm_hour;
      int minutes = ltm->tm_min;
      int seconds = ltm->tm_sec;

      COLORREF onColor = RGB(100, 255, 100);  // Color verde para segmentos encendidos
      COLORREF offColor = RGB(50, 50, 50); // Color gris oscuro para segmentos apagados

      DrawDigit(hdc, hours / 10, 50, 50, 100, onColor, offColor);
      DrawDigit(hdc, hours % 10, 160, 50, 100, onColor, offColor);
      DrawDigit(hdc, minutes / 10, 320, 50, 100, onColor, offColor);
      DrawDigit(hdc, minutes % 10, 430, 50, 100, onColor, offColor);
      DrawDigit(hdc, seconds / 10, 590, 50, 100, onColor, offColor);
      DrawDigit(hdc, seconds % 10, 700, 50, 100, onColor, offColor);

      EndPaint(hwnd, &ps);
      break;
    }

    case WM_DESTROY:
      PostQuitMessage(0);
      break;

    default:
      return DefWindowProc(hwnd, uMsg, wParam, lParam);
  }
  return 0;
}

void DrawDigit(HDC hdc, int number, int x, int y, int size, COLORREF onColor, COLORREF offColor) {
  const int segmentLength = size;
  const int segmentWidth = size / 5;

  // Definimos los segmentos de un dígito de 7 segmentos
  RECT segments[7] = {
    {x + segmentWidth, y, x + segmentLength - segmentWidth, y + segmentWidth},  // Segmento superior
    {x + segmentLength - segmentWidth, y + segmentWidth, x + segmentLength, y + segmentLength / 2},  // Segmento superior derecho
    {x + segmentLength - segmentWidth, y + segmentLength / 2, x + segmentLength, y + segmentLength - segmentWidth},  // Segmento inferior derecho
    {x + segmentWidth, y + segmentLength - segmentWidth, x + segmentLength - segmentWidth, y + segmentLength},  // Segmento inferior
    {x, y + segmentLength / 2, x + segmentWidth, y + segmentLength - segmentWidth},  // Segmento inferior izquierdo
    {x, y + segmentWidth, x + segmentWidth, y + segmentLength / 2},  // Segmento superior izquierdo
    {x + segmentWidth, y + segmentLength / 2 - segmentWidth / 2, x + segmentLength - segmentWidth, y + segmentLength / 2 + segmentWidth / 2}  // Segmento central
  };

  // Definimos qué segmentos deben encenderse para cada número
  bool on[10][7] = {
    {true, true, true, false, true, true, true},  // 0
    {false, false, true, false, false, true, false},  // 1
    {true, false, true, true, true, false, true},  // 2
    {true, false, true, true, false, true, true},  // 3
    {false, true, true, true, false, true, false},  // 4
    {true, true, false, true, false, true, true},  // 5
    {true, true, false, true, true, true, true},  // 6
    {true, false, true, false, false, true, false},  // 7
    {true, true, true, true, true, true, true},  // 8
    {true, true, true, true, false, true, true}   // 9
  };

  // Dibujamos los segmentos necesarios para el número dado
  for (int i = 0; i < 7; ++i) {
    HBRUSH brush = CreateSolidBrush(on[number][i] ? onColor : offColor);
    FillRect(hdc, &segments[i], brush);
    DeleteObject(brush);
  }
}
