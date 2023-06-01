#include <iostream>
#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"
using namespace std;
HINSTANCE hInst;
class Punto
{   public:
    int x,y;
    Punto(int xx=0,int yy=0)
    {   x=xx;
        y=yy;
    }
};
class Nodo
{   public:
    Punto P;
    Nodo *SI,*SD,*II,*ID;
    Nodo(Punto p,Nodo *si=NULL,Nodo *sd=NULL,Nodo *ii=NULL,Nodo *id=NULL)
    {   P=p;
        SI=si;
        SD=sd;
        II=ii;
        ID=id;
    }
};
class Quadtree
{   public:
    Nodo *Raiz;
    Quadtree()
    {   Raiz=NULL;
    }
    void Insertar(Punto p)
    {   Ins(p,Raiz);
    }
    void Ins(Punto p,Nodo *&R)
    {   if(R==NULL)
            R=new Nodo(p);
        else
        {   if(p.x<R->P.x)
            {   if(p.y<R->P.y)
                    Ins(p,R->SI);
                else
                    Ins(p,R->II);
            }
            else
            {   if(p.y<R->P.y)
                    Ins(p,R->SD);
                else
                    Ins(p,R->ID);
            }
        }
    }
    void Mostrar(HDC hdc,int xi,int yi,int a)
    {   Mos(hdc,xi,yi,a,Raiz);
    }
    void Mos(HDC hdc,int xi,int yi,int a,Nodo *R)
    {   if(R!=NULL)
        {   char Cad[20];
            sprintf(Cad,"%i",R->P.x);
            TextOut(hdc,xi,yi,Cad,strlen(Cad));
            sprintf(Cad,"%i",R->P.y);
            TextOut(hdc,xi,yi+20,Cad,strlen(Cad));
            Mos(hdc,xi-a/2,yi+50,a/4,R->SI);
            Mos(hdc,xi-a/6,yi+50,a/4,R->SD);
            Mos(hdc,xi+a/6,yi+50,a/4,R->II);
            Mos(hdc,xi+a/2,yi+50,a/4,R->ID);
        }
    }
    void MostrarR(HDC hdc,int xi,int yi,int xf,int yf)
     {
         Rectangle(hdc, xi,yi,xf,yf);
         MosR(hdc,xi,yi,xf,yf,Raiz);
     }
     void MosR(HDC hdc,int xi, int yi, int xf,int yf,Nodo *R)
     {
         if(R!=NULL)
         {
             MoveToEx(hdc,xi,R->P.y,NULL);
             LineTo(hdc,xf,R->P.y);
             MoveToEx(hdc, R->P.x ,yi,NULL);
             LineTo(hdc,R->P.x,yf);
             MosR(hdc, xi,yi,R->P.x,R->P.y,R->SI);
             MosR(hdc, R->P.x,yi,xf,R->P.y,R->SD);
             MosR(hdc, xi,R->P.y,R->P.x,yf,R->II);
             MosR(hdc, R->P.x,R->P.y,xf,yf,R->ID);

         }
     }

};
Quadtree Q;
int pxi,pyi,pxf,pyf;
BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{   switch(uMsg)
    {   case WM_INITDIALOG:
        {
           pxi=10;
           pyi=60;
           pxf=pxi+200;
           pyf=pyf+200;
        }
        return TRUE;
        case WM_PAINT:
        {   HDC hdc;
            PAINTSTRUCT ps;
            hdc=BeginPaint(hwndDlg,&ps);
            Q.Mostrar(hdc,600,50,500);
            Q.MostrarR(hdc, pxi,pyi,pxf,pyf);
            EndPaint(hwndDlg,&ps);
        }
        return TRUE;
        case WM_LBUTTONDOWN:
        {   long xpos=GET_X_LPARAM(lParam);
            long ypos=GET_Y_LPARAM(lParam);
            Q.Insertar(Punto(xpos,ypos));
            InvalidateRect(hwndDlg,NULL,TRUE);
        }
        return TRUE;
        case WM_MOUSEMOVE:
        {   long xpos=GET_X_LPARAM(lParam);
            long ypos=GET_Y_LPARAM(lParam);
            char Cad[20];
            sprintf(Cad,"%i",xpos);
            SetDlgItemText(hwndDlg,EJEX,Cad);
            sprintf(Cad,"%i",ypos);
            SetDlgItemText(hwndDlg,EJEY,Cad);
        }
        return TRUE;
        case WM_CLOSE:
        {   EndDialog(hwndDlg, 0);
        }
        return TRUE;
        case WM_COMMAND:
        {   switch(LOWORD(wParam))
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
