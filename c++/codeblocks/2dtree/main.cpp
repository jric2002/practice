#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <stdio.h>
#include <string.h>
#include "resource.h"

class Punto
{
public:
    int x, y;
    Punto(int x = 0, int y = 0) {
      this->x = x;
      this->y = y;
    }
};

class Nodo {
public:
    Punto p;
    Nodo *izq, *der;
    int eje;
    Nodo(Punto p, int eje, Nodo* izq = NULL, Nodo* der = NULL) {
      this->p = p;
      this->eje = eje;
      this->izq = izq;
      this->der = der;
    }
};

class tree2d {
public:
    Nodo* raiz;
    tree2d() {
        raiz=NULL;
    }
    void insertar(Punto p)
    {
        inser(p,raiz,0);
    }
    void inser(Punto p, Nodo *&R, int eje)
    {
        if(R == NULL)
            R = new Nodo(p,eje);
        else if(R->eje == 0)
        {
            if(p.x > R->p.x)
                inser(p,R->der,1);
            else
                inser(p,R->izq,1);
        }
        else
        {
            if(p.y > R->p.y)
                inser(p,R->der,0);
            else
                inser(p,R->izq,0);
        }
    }
    void MostrarR(HDC hdc, int pxi, int pyi, int pxf, int pyf)
    {
        Rectangle(hdc, pxi, pyi, pxf, pyf);
        Mos(hdc,pxi,pyi,pxf,pyf,raiz);
    }
    void Mos(HDC hdc,int xi,int yi,int xf,int yf,Nodo* R)
    {
        if(R != NULL)
        {
            if(R->eje == 0){
              MoveToEx(hdc,R->p.x,yi,NULL);
              LineTo(hdc,R->p.x,yf);
              Rectangle(hdc, R->p.x - 3, R->p.y - 3, R->p.x + 3, R->p.y + 3); // dibuja un cuadrado en el punto
              Mos(hdc,R->p.x,yi,xf,yf,R->der);
              Mos(hdc,xi,yi,R->p.x,yf,R->izq);
            }
            else
            {
              MoveToEx(hdc,xi,R->p.y,NULL);
              LineTo(hdc,xf,R->p.y);
              Rectangle(hdc, R->p.x - 3, R->p.y - 3, R->p.x + 3, R->p.y + 3); // dibuja un cuadrado en el punto
              Mos(hdc,xi,R->p.y,xf,yf,R->der);
              Mos(hdc,xi,yi,xf,R->p.y,R->izq);
            }
        }
    }
    void Mostrar(HDC hdc,int xi,int yi,int a)
    {   Mos1(hdc,xi,yi,a,raiz);
    }
    void Mos1(HDC hdc,int xi,int yi,int a,Nodo *R)
    {   if(R!=NULL)
        {   char Cad[20];
            sprintf(Cad,"%i",R->p.x);
            TextOut(hdc,xi,yi,Cad,strlen(Cad));
            sprintf(Cad,"%i",R->p.y);
            TextOut(hdc,xi,yi+15,Cad,strlen(Cad));
            sprintf(Cad,"%i",R->eje);
            TextOut(hdc,xi+30,yi+7,Cad,strlen(Cad));
            //recursivo
            Mos1(hdc,xi+a/2,yi+50,a/2,R->der);
            Mos1(hdc,xi-a/2,yi+50,a/2,R->izq);
        }
    }
};

tree2d Q;
int pxi, pyi, pxf, pyf;
HINSTANCE hInst;

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
        pxi = 30;
        pyi = 30;
        pxf = pxi + 200;
        pyf = pyi + 200;
    }
    return TRUE;

    case WM_LBUTTONDOWN:
    {
        int xPos = GET_X_LPARAM(lParam);
        int yPos = GET_Y_LPARAM(lParam);
        if (xPos > pxi && xPos < pxf && yPos > pyi && yPos < pyf) // Inserta puntos solo en el cuadro
            Q.insertar(Punto(xPos,yPos));
        InvalidateRect(hwndDlg,NULL,TRUE);
    }
    return TRUE;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc;
        hdc = BeginPaint(hwndDlg,&ps);
        char titulo[] = "2DTree";
        TextOut(hdc, pxi, pyi - 20, titulo, strlen(titulo));
        Q.Mostrar(hdc,600,50,400);
        Q.MostrarR(hdc,pxi,pyi,pxf,pyf);
        EndPaint(hwndDlg,&ps);
    }
    return TRUE;
    // cambiar valores de caja de texto
    case WM_MOUSEMOVE:
    {
        long xpos = GET_X_LPARAM(lParam);
        long ypos = GET_Y_LPARAM(lParam);

        char cad[20];
        sprintf(cad,"%i",xpos);
        SetDlgItemText(hwndDlg,EJEX,cad);

        sprintf(cad,"%i",ypos);
        SetDlgItemText(hwndDlg,EJEY,cad);
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
