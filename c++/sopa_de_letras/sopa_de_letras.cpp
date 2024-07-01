#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;
/* Compilar: g++ -mconsole -mwindows -municode ./sopa_de_letras.cpp -o output.exe */
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
wstring RemoveSpaces(const wstring& input);
void LoadWordSearch(const char* filename, vector<wstring>& grid);
bool SearchWord(const vector<wstring>& grid, const wstring& word, vector<POINT>& positions);
int GenerateRandomNumber(int, int);
HWND hwndTextbox;
HWND hwndButton;
vector<wstring> wordSearchGrid;
vector<POINT> foundPositions;
wchar_t word[100];
milliseconds search_duration;
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
  const wchar_t CLASS_NAME[] = L"sopa_de_letras";
  WNDCLASS wc = { };
  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = CLASS_NAME;
  RegisterClass(&wc);
  HWND hwnd = CreateWindowEx(
    0,
    CLASS_NAME,
    L"Sopa de Letras",
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
  MSG msg = { };
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return 0;
}
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
  switch (msg) {
    case WM_CREATE: {
      hwndTextbox = CreateWindow(L"EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER,
                                20, 20, 200, 20, hwnd, NULL, NULL, NULL);
      hwndButton = CreateWindow(L"BUTTON", L"Buscar", WS_CHILD | WS_VISIBLE,
                                230, 20, 100, 20, hwnd, (HMENU)1, NULL, NULL);
      // Cargar la sopa de letras desde el archivo
      LoadWordSearch("archivo.txt", wordSearchGrid);
      break;
    }
    case WM_COMMAND: {
      if (LOWORD(wParam) == 1) {
        GetWindowText(hwndTextbox, word, 100);
        // foundPositions.clear();
        auto start = high_resolution_clock::now();
        bool found = SearchWord(wordSearchGrid, word, foundPositions);
        auto stop = high_resolution_clock::now();
        search_duration = duration_cast<milliseconds>(stop - start);
        cout.setf(ios::fixed);
        cout.precision(11);
        if (found) {
          wcout << L"[+] Palabra: " << word << endl;
        }
        else {
          wcout << L"[-] La palabra " << word << " no se encuentra en la sopa de letras." << endl;
        }
        cout << "Tiempo de búsqueda: " << search_duration.count() << " ms" << endl << endl;
        cout.unsetf(ios::fixed);
        InvalidateRect(hwnd, NULL, TRUE);
      }
      break;
    }
    case WM_PAINT: {
      PAINTSTRUCT ps;
      HDC hdc = BeginPaint(hwnd, &ps);
      RECT rect;
      GetClientRect(hwnd, &rect);
      HFONT hFont = CreateFont(20, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Consolas");
      SelectObject(hdc, hFont);
      FillRect(hdc, &rect, CreateSolidBrush(RGB(255, 255, 255)));
      int charWidth = 20;
      int charHeight = 20;
      for (size_t i = 0; i < wordSearchGrid.size(); ++i) {
        for (size_t j = 0; j < wordSearchGrid[i].size(); ++j) {
          bool highlight = false;
          for (const auto& pos : foundPositions) {
            if (pos.x == j && pos.y == i) {
              highlight = true;
              break;
            }
          }
          if (highlight) {
            SetTextColor(hdc, RGB(255, 0, 0));
          } else {
            SetTextColor(hdc, RGB(0, 0, 0));
          }
          wchar_t character = wordSearchGrid[i][j];
          TextOut(hdc, rect.left + 20 + j * charWidth, rect.top + 60 + i * charHeight, &character, 1);
        }
      }
      DeleteObject(hFont);
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
wstring RemoveSpaces(const wstring& input) {
  wstring result;
  copy_if(input.begin(), input.end(), back_inserter(result), [](wchar_t ch) {
    return !isspace(ch);
  });
  return result;
}
void LoadWordSearch(const char* filename, vector<wstring>& grid) {
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    wstring wline(line.begin(), line.end());
    wline = RemoveSpaces(wline);
    grid.push_back(wline);
  }
}
bool SearchWord(const vector<wstring>& grid, const wstring& word, vector<POINT>& positions) {
  int rows = grid.size();
  int cols = grid[0].size();
  int len = word.length();
  int directions[8][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
  for (int y = 0; y < rows; ++y) {
    for (int x = 0; x < cols; ++x) {
      for (const auto& dir : directions) {
        int dx = dir[0];
        int dy = dir[1];
        int nx = x;
        int ny = y;
        int i = 0;
        for (; i < len; ++i) {
          if (nx >= cols || nx < 0 || ny >= rows || ny < 0 || tolower(grid[ny][nx]) != tolower(word[i])) {
            break;
          }
          nx += dx;
          ny += dy;
        }
        if (i == len) {
          for (int j = 0; j < len; ++j) {
            positions.push_back({ x + j * dx, y + j * dy });
          }
          return true;
        }
      }
    }
  }
  return false;
}
int GenerateRandomNumber(int min, int max) {
  return (rand() % (max - min + 1) + min);
}