#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"

HINSTANCE hInst;
class Punto {
public:
  int x, y, z;
  Punto(int x = 0, int y = 0, int z = 0) {
    this->x = x;
    this->y = y;
    this->z = z;
  }
};
class Nodo {
public:
  Punto p;
  int eje;
  Nodo *izq, *der;
  Nodo(Punto p, int eje, Nodo *izq = NULL, Nodo *der = NULL) {
    this->p = p;
    this->eje = eje;
    this->izq = izq;
    this->der = der;
  }
};

class _3DTree {
public:
  Nodo *raiz;
  _3DTree() {
    raiz = NULL;
  }
  void insertar(Punto p) {
    inser(p, raiz, 0);
  }
  void inser(Punto p, Nodo *&R, int eje) {
    if (R == NULL)
      R = new Nodo(p, eje);
    else if (R->eje == 0) {
      if (p.x > R->p.x)
        inser(p,R->der,1);
      else
        inser(p,R->izq,1);
    }
    else {
      if(p.y > R->p.y)
        inser(p,R->der,0);
      else
        inser(p,R->izq,0);
    }
  }
};
void dibujarLinea(HDC hdc, double xi, double yi, double xf, double yf) {
  MoveToEx(hdc, xi, yi, NULL);
  LineTo(hdc, xf, yf);
}
INT pr_x, pr_y, pr_z;
BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
      case WM_INITDIALOG:
        pr_x = X_SCROLLBAR + A_SCROLLBAR + 200;
        pr_y = Y_SCROLLBAR + A_SCROLLBAR + 200;
      {
      }
      return TRUE;

      case WM_PAINT:
      {
        PAINTSTRUCT ps;
        HDC hdc;
        hdc = BeginPaint(hwndDlg, &ps);
        dibujarLinea(hdc, pr_x, pr_y, pr_x + 5, pr_y);
        //SelectObject(hdc, CreateSolidBrush(RGB(0, 255, 0)));
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
          case ID_INSERTAR:
            INT v_caja_x, v_caja_y, v_caja_z;
            v_caja_x = GetDlgItemInt(hwndDlg, ID_CAJA_X, NULL, FALSE);
            v_caja_y = GetDlgItemInt(hwndDlg, ID_CAJA_Y, NULL, FALSE);
            v_caja_z = GetDlgItemInt(hwndDlg, ID_CAJA_Z, NULL, FALSE);
            //printf("x: %i\ty: %i\tz: %i\n", v_caja_x, v_caja_y, v_caja_z);
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
