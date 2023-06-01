#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"

HINSTANCE hInst;
/*
0 = negro;
1 = blanco;
2 = gris;
*/
int A[100][100];
int pxi, pyi, pxf, pyf, N;
class Nodo {
public:
    int Color;
    Nodo *SI, *SD, *II, *ID;
    Nodo(int c = 0, Nodo *si = NULL, Nodo *sd = NULL, Nodo *ii = NULL, Nodo *id = NULL)
    {
        Color = c;
        SI = si;
        SD = sd;
        II = ii;
        ID = id;
    }
};
class QuadTree {
public:
    Nodo *Raiz;
    QuadTree() {
        Raiz = NULL;
    }
    void Mostrar(HDC hdc) {
        int tama = (pxf - pxi) /  N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[j][i] == 1) {
                    SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));
                }
                else {
                    SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
                }
                Rectangle(hdc, pxi+i*tama, pyi+j*tama, pxi+(i+1)*tama, pyi+(j+1)*tama);
            }
        }
    }
    void Construir(int xi, int yi, int xf, int yf)
    {
        Cons(xi, yi, xf, yf, Raiz);
    }
    void Cons(int xi, int yi, int xf, int yf, Nodo *&R)
    {
        int i, j;
        int SColor = 0;
        for (i = xi; i <= xf; i++)
        {
            for (j = yi; j <= yf; j++)
            {
                SColor += A[i][j];
            }
        }
        if (SColor == 0) {
            R = new Nodo(0);
        }
        else if (SColor == (xf-xi+1)*(yf-yi+1)) {
            R = new Nodo(1);
        }
        else {
            R = new Nodo(2);
            Cons(xi, yi, (xi+xf)/2, (yi+yf)/2, R->SI);
            Cons(xi, (yi+yf)/2+1, (xi+xf)/2, yf, R->SD);
            Cons((xi+xf)/2+1, (yi+yf)/2+1, xf, yf, R->ID);
            Cons((xi+xf)/2+1, yi, xf, (yi+yf)/2, R->II);
        }
    }
    void MostrarA(HDC hdc, int x, int y, int a)
    {
        MosA(hdc, x, y, a, Raiz);
    }
    void MosA(HDC hdc, int x, int y, int a, Nodo *R)
    {
        if (R != NULL) {
            char Cad[10];
            sprintf(Cad, "%i", R->Color);
            TextOut(hdc, x, y, Cad, strlen(Cad));
            MosA(hdc, x-a/2, y+50, a/4, R->SI);
            MosA(hdc, x-a/6, y+50, a/4, R->SD);
            MosA(hdc, x+a/6, y+50, a/4, R->ID);
            MosA(hdc, x+a/2, y+50, a/4, R->II);
        }
    }
};
QuadTree Q;
BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_LBUTTONDOWN:
        {
            long xPos = GET_X_LPARAM(lParam);
            long yPos = GET_Y_LPARAM(lParam);
            if (xPos < pxf && xPos > pxi && yPos < pyf && yPos > pyi) {
                long tama = (pxf - pxi)/N;
                int x = (xPos-pxi)/tama;
                int y = (yPos-pyi)/tama;
                if (A[y][x] == 0) {
                    A[y][x] = 1;
                }
                else {
                    A[y][x] = 0;
                }
                InvalidateRect(hwndDlg, NULL, true);
            }
        }
    return TRUE;
    case WM_PAINT:
        PAINTSTRUCT ps;
        HDC hdc;
        hdc = BeginPaint(hwndDlg, &ps);
        Q.Mostrar(hdc);
        Q.Construir(0, 0, N - 1, N - 1);
        Q.MostrarA(hdc, 600, 50, 400);
        EndPaint(hwndDlg, &ps);
    return TRUE;
    case WM_INITDIALOG:
    {
        N = 8;
        pxi = 10;
        pyi = 10;
        pxf = pxi + 300;
        pyf = pyi + 300;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = 1;
            }
        }
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
