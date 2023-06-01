#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <cstring>
#include "resource.h"
#include "nodo.h"
#include "abb.h"

#define CAJA_DE_TEXTO 1
#define AGREGAR 2

HINSTANCE hInst;
HWND CajaDeTexto, Agregar, Texto, Texto_Valor, ControlEdit;
int LengthText;
char Valor[20];
char Mensaje[] = "Nuevo nodo con valor: ";
int x, y, l;
bool dibujar = false;
std::string Valor_Nodo;
Abb *abb = new Abb();

void dibujarArbol(Nodo *aux, HWND hwndDlg, HDC hdc, int x, int y, int l, int c) {
  if (aux != NULL) {
      dibujarArbol(aux->obtHijoIzq(), hwndDlg, hdc, x - (l * c), y + l, l, c - 1);
      Valor_Nodo = std::to_string(aux->retValor());
      //Texto_Valor = CreateWindowEx(0, "STATIC", Valor_Nodo.c_str(), WS_VISIBLE | WS_CHILD | SS_LEFT, x, y, l, l, hwndDlg, NULL, NULL, NULL);
      Rectangle(hdc, x - l/2, y - l/2, x + l/2, y + l/2);
      dibujarArbol(aux->obtHijoDer(), hwndDlg, hdc, x + (l * c), y + l, l, c - 1);
  }
}

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
      CajaDeTexto = CreateWindowEx(0,"EDIT", "",WS_BORDER | WS_CHILD | WS_VISIBLE,10, 10, 100, 25,hwndDlg, (HMENU) 1, NULL, NULL);
      Agregar = CreateWindowEx(0, "BUTTON", "Agregar", BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD | 0, 120, 10, 80, 25, hwndDlg, (HMENU) 2, 0, 0);
      return TRUE;
    }
    case WM_PAINT:
      if (dibujar) {
        PAINTSTRUCT ps;
        HDC hdc;
        hdc = BeginPaint(hwndDlg, &ps);
        TextOut(hdc, 5, 50, Mensaje, sizeof(Mensaje)/sizeof(char));
        x = 400;
        y = 100;
        l = 30;
        dibujarArbol(abb->retRaiz(), hwndDlg, hdc, x, y, l, (abb->alturaArbol(abb->retRaiz()) - 1));
        EndPaint(hwndDlg, &ps);
      }
    return TRUE;
    case WM_CLOSE:
    {
        EndDialog(hwndDlg, 0);
    }
    return TRUE;
    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        case CAJA_DE_TEXTO:
          return TRUE;
        case AGREGAR:
          LengthText = GetWindowTextLength(CajaDeTexto) + 1;
          TCHAR *Valor = new TCHAR[LengthText];
          GetWindowText(CajaDeTexto, Valor, LengthText);
          Valor[LengthText - 1] = '\0';
          abb->Insertar(abb->retRaiz(), atoi(Valor));
          std::cout << std::endl << "---------------" << std::endl;
          std::cout << "Arbol:" << std::endl;
          abb->Mostrar(abb->retRaiz(), 0);
          Texto = CreateWindowEx(0, "STATIC", Valor, WS_VISIBLE | WS_CHILD | SS_LEFT, 165,50,30,20, hwndDlg, NULL, NULL, NULL);
          dibujar = true;
          InvalidateRect(hwndDlg, NULL, TRUE);
          delete[] Valor;
          return TRUE;
        }
    }
    return TRUE;
    }
    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
