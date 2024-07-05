#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

#include <windows.h>
#include <string>
#include <iostream>
using namespace std;
#define IDC_EDIT 101
#define IDC_BUTTON 102
/* Compilar: g++ -mconsole -mwindows -municode visualizador_de_numeros_formato_digital.cpp -o output.exe */
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
HWND hEdit, hButton;
int currentDigit = -1;
void DrawSegment(HDC hdc, int x, int y, int segment, bool active) {
  const int segmentWidth = 100;
  const int segmentHeight = 120;
  const int segmentSpacing = 20;
  COLORREF color = active ? RGB(0, 200, 0) : RGB(200, 200, 200);
  HBRUSH hBrush = CreateSolidBrush(color);
  HGDIOBJ hOldBrush = SelectObject(hdc, hBrush);
  POINT points[6];
  switch (segment) {
    case 0: // Top
      points[0] = { x, y };
      points[1] = { x + segmentWidth, y };
      points[2] = { x + segmentWidth - segmentSpacing, y + segmentSpacing };
      points[3] = { x + segmentSpacing, y + segmentSpacing };
      break;
    case 1: // Top-right
      points[0] = { x + segmentWidth, y };
      points[1] = { x + segmentWidth - segmentSpacing, y + segmentSpacing };
      points[2] = { x + segmentWidth - segmentSpacing, y + segmentHeight - segmentSpacing };
      points[3] = { x + segmentWidth, y + segmentHeight };
      break;
    case 2: // Bottom-right
      points[0] = { x + segmentWidth, y + segmentHeight };
      points[1] = { x + segmentWidth - segmentSpacing, y + segmentHeight + segmentSpacing };
      points[2] = { x + segmentWidth - segmentSpacing, y + (2 * segmentHeight) - segmentSpacing };
      points[3] = { x + segmentWidth, y + 2 * segmentHeight };
      break;
    case 3: // Bottom
      points[0] = { x, y + 2 * segmentHeight };
      points[1] = { x + segmentWidth, y + 2 * segmentHeight };
      points[2] = { x + segmentWidth - segmentSpacing, y + 2 * segmentHeight - segmentSpacing };
      points[3] = { x + segmentSpacing, y + 2 * segmentHeight - segmentSpacing };
      break;
    case 4: // Bottom-left
      points[0] = { x, y + segmentHeight };
      points[1] = { x + segmentSpacing, y + segmentHeight + segmentSpacing };
      points[2] = { x + segmentSpacing, y + 2 * segmentHeight - segmentSpacing };
      points[3] = { x, y + 2 * segmentHeight };
      break;
    case 5: // Top-left
      points[0] = { x, y };
      points[1] = { x + segmentSpacing, y + segmentSpacing };
      points[2] = { x + segmentSpacing, y + segmentHeight - segmentSpacing };
      points[3] = { x, y + segmentHeight };
      break;
    case 6: // Middle
      points[0] = { x, y + segmentHeight };
      points[1] = { x + segmentSpacing, y + segmentHeight - segmentSpacing / 2 };
      points[2] = { x + segmentWidth - segmentSpacing, y + segmentHeight - segmentSpacing / 2 };
      points[3] = { x + segmentWidth, y + segmentHeight };
      points[4] = { x + segmentWidth - segmentSpacing, y + segmentHeight + segmentSpacing / 2 };
      points[5] = { x + segmentSpacing, y + segmentHeight + segmentSpacing / 2 };
      break;
  }
  if (segment == 6) {
    Polygon(hdc, points, 6);
  }
  else {
    Polygon(hdc, points, 4);
  }
  SelectObject(hdc, hOldBrush);
  DeleteObject(hBrush);
}
void DrawDigit(HDC hdc, int x, int y, int digit) {
  // Cada fila representa un digito (0-9), cada columna representa un segmento (0-6)
  const bool segments[10][7] = {
    { true, true, true, true, true, true, false }, // 0
    { false, true, true, false, false, false, false }, // 1
    { true, true, false, true, true, false, true }, // 2
    { true, true, true, true, false, false, true }, // 3
    { false, true, true, false, false, true, true }, // 4
    { true, false, true, true, false, true, true }, // 5
    { true, false, true, true, true, true, true }, // 6
    { true, true, true, false, false, false, false }, // 7
    { true, true, true, true, true, true, true }, // 8
    { true, true, true, true, false, true, true } // 9
  };
  for (int i = 0; i < 7; ++i) {
    // Draw inactive segment (shadow)
    DrawSegment(hdc, x, y, i, false);
    // Draw active segment if needed
    if (segments[digit][i]) {
      DrawSegment(hdc, x, y, i, true);
    }
  }
}
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
  // Register the window class
  const wchar_t CLASS_NAME[] = L"MyWindowClass";
  WNDCLASS wc = {};
  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = CLASS_NAME;
  RegisterClass(&wc);
  // Create the window
  HWND hwnd = CreateWindowEx(
    0,
    CLASS_NAME,
    L"Visualizador de Números",
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, 350, 500,
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
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
  switch (msg) {
    case WM_CREATE: {
      hEdit = CreateWindowEx(
        0, L"EDIT", L"",
        WS_CHILD | WS_VISIBLE | WS_BORDER,
        50, 50, 200, 20,
        hwnd, (HMENU)IDC_EDIT, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL
      );
      hButton = CreateWindowEx(
        0, L"BUTTON", L"Mostrar Número",
        WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        50, 80, 200, 30,
        hwnd, (HMENU)IDC_BUTTON, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL
      );
      break;
    }
    case WM_COMMAND: {
      if (LOWORD(wParam) == IDC_BUTTON) {
        wchar_t buffer[2];
        GetWindowText(hEdit, buffer, 2);
        currentDigit = _wtoi(buffer);
        if (currentDigit >= 0 && currentDigit <= 9) {
          InvalidateRect(hwnd, NULL, TRUE);
        } else {
          MessageBox(hwnd, L"Por favor, ingrese un número entre 0 y 9", L"Error", MB_OK | MB_ICONERROR);
        }
      }
      break;
    }
    case WM_PAINT: {
      PAINTSTRUCT ps;
      HDC hdc = BeginPaint(hwnd, &ps);
      if (currentDigit >= 0 && currentDigit <= 9) {
        DrawDigit(hdc, 100, 140, currentDigit);
      }
      EndPaint(hwnd, &ps);
      break;
    }
    case WM_DESTROY: {
      PostQuitMessage(0);
      break;
    }
    default:
      return DefWindowProc(hwnd, msg, wParam, lParam);
  }
  return 0;
}