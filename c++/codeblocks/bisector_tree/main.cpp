#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <math.h>
#include <windows.h>
#include <windowsx.h>
#include <map>
#include <vector>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"
using namespace std;
HINSTANCE hInst;
int pxi,pyi,pxf,pyf;
void SetPixel2(HDC hdc,int x,int y,COLORREF Color)
{   if(x>pxi&&x<pxf&&y>pyi&&y<pyf)
        SetPixel(hdc, x, y, Color);
}
void Draw8Points(HDC hdc,int xc,int yc, int a, int b,COLORREF Color)
{   SetPixel2(hdc, xc+a, yc+b, Color);
    SetPixel2(hdc, xc-a, yc+b, Color);
    SetPixel2(hdc, xc-a, yc-b, Color);
    SetPixel2(hdc, xc+a, yc-b, Color);
    SetPixel2(hdc, xc+b, yc+a, Color);
    SetPixel2(hdc, xc-b, yc+a, Color);
    SetPixel2(hdc, xc-b, yc-a, Color);
    SetPixel2(hdc, xc+b, yc-a, Color);
}
void CircleBresenham(HDC hdc,int xc,int yc, int R,int rrr,COLORREF color)
{   int x=0,y=R;
    int d=1-R;
    Draw8Points(hdc,xc,yc,x,y,color);
    while(x<y)
    {   if(d<0)
            d+=2*x+2;
        else
        {   d+=2*(x-y)+5;
            y-=rrr;
        }
        x+=rrr;
        Draw8Points(hdc,xc,yc,x,y,color);
    }
}
void line(HDC hdc,int x0, int y0, int x1, int y1,COLORREF Color)
{   int dx, dy, p, x, y;
  dx=x1-x0;
  dy=y1-y0;
  x=x0;
  y=y0;
  p=2*dy-dx;
  while(x<x1)
  {	if(p>=0)
    {   SetPixel2(hdc,x,y,Color);
      y=y+1;
      p=p+2*dy-2*dx;
    }
    else
    {   SetPixel2(hdc,x,y,Color);
      p=p+2*dy;
    }
    x=x+1;
  }
}
class Punto
{   public:
    int x,y;
    Punto(int _x=0,int _y=0)
    {   x=_x;
        y=_y;
    }
};
class Nodo
{   public:
    vector <Punto> P;
    vector <float> R;
    Nodo *A, *B;
    Nodo(vector <Punto> PP,vector <float> RR)
    {   P=PP;
        R=RR;
        A=B=NULL;
    }
};
class BisectorTree
{   public:
    Nodo *Raiz;
    vector <Punto> Ps;
    BisectorTree()
    {   Raiz=NULL;
    }
    float distP(Punto P1,Punto P2)
    {   return (sqrt((P1.x-P2.x)*(P1.x-P2.x)+(P1.y-P2.y)*(P1.y-P2.y)));
    }
    float LlenarPuntos(int Num)
    {   for(int i=0;i<Num;i++)
        {   Punto P;
            P.x=10+rand()%(460-10);
            P.y=50+rand()%(500-50);
            Ps.push_back(P);
        }
    }
    void MostrarP(HDC hdc)
    {   for(int i=0;i<Ps.size();i++)
        {   CircleBresenham(hdc,Ps[i].x,Ps[i].y,2,1,RGB(255,0,0));
        }
    }
    vector <Punto> Ordenar(vector <Punto> PP)
    {   if(PP.size()>2)
        {   float D=0;
            int p1=0,p2=0;
            for(int i=0;i<PP.size();i++)
            {   for(int j=i+1;j<PP.size();j++)
                {   if(D<distP(PP[i],PP[j]))
                    {   D=distP(PP[i],PP[j]);
                        p1=i;
                        p2=j;
                    }
                }
            }
            Punto T=PP[0];
            PP[0]=PP[p1];
            PP[p1]=T;
            T=PP[1];
            PP[1]=PP[p2];
            PP[p2]=T;
        }
        return PP;
    }
    void ConstruirP()
    {   ConsP(Raiz,Ps);
    }
    void ConsP(Nodo *&R,vector <Punto> PP)
    {   vector <Punto> P1;
        vector <Punto> P2;
        vector <Punto> In;
        vector <float> Ra(2,0);
        if(R==Raiz)
            PP=Ordenar(PP);
        if(PP.size()>2)
        {   for(int i=2;i<PP.size();i++)
            {   if(distP(PP[0],PP[i])<distP(PP[1],PP[i]))
                {   P1.push_back(PP[i]);
                    if(distP(PP[0],PP[i])>Ra[0])
                        Ra[0]=distP(PP[0],PP[i]);
                }
                else
                {   P2.push_back(PP[i]);
                    if(distP(PP[1],PP[i])>Ra[1])
                        Ra[1]=distP(PP[1],PP[i]);
                }
            }
            In.insert(In.end(), PP.begin(), PP.begin()+2 );
            R=new Nodo(In,Ra);
            P1=Ordenar(P1);
            P2=Ordenar(P2);
            ConsP(R->A,P1);
            ConsP(R->B,P2);
        }
        else if(PP.size()>0)
        {   R=new Nodo(PP,Ra);
        }
    }
    void MostrarR(HDC hdc)
    {   MosR(hdc,Raiz,Punto(0,0));
    }
    void MosR(HDC hdc,Nodo *R,Punto M)
    {   if(R!=NULL)
        {   if(R==Raiz)
            {   if((R->P).size()==2)
                {   MoveToEx(hdc,(R->P[0]).x,(R->P[0]).y,NULL);
                    LineTo(hdc,(R->P[1]).x,(R->P[1]).y);
                    CircleBresenham(hdc,(R->P[0]).x,(R->P[0]).y,R->R[0]+4,1,RGB(255,0,0));
                    CircleBresenham(hdc,(R->P[1]).x,(R->P[1]).y,R->R[1]+4,1,RGB(0,0,255));
                }
            }
            else
            {   for(int i=0;i<(R->P).size();i++)
                {   MoveToEx(hdc,M.x,M.y,NULL);
                    LineTo(hdc,(R->P[i]).x,(R->P[i]).y);
                    if(i==0)
                        CircleBresenham(hdc,(R->P[i]).x,(R->P[i]).y,R->R[i]+4,1,RGB(255,0,0));
                    else
                        CircleBresenham(hdc,(R->P[i]).x,(R->P[i]).y,R->R[i]+4,1,RGB(0,0,255));
                }
            }
            MosR(hdc,R->A,R->P[0]);
            MosR(hdc,R->B,R->P[1]);
        }
    }
    void Mostrar(HDC hdc,int x,int y,int a)
    {   Mos(hdc,Raiz,x,y,a);
    }
    void Mos(HDC hdc,Nodo *R,int x,int y,int a)
    {   if(R!=NULL)
        {   char Cad[30];
            if((R->P).size()>0)
            {   sprintf(Cad,"(%i , %i)",(R->P[0]).x,(R->P[0]).y);
                TextOut(hdc,x,y,Cad,strlen(Cad));
            }
            if((R->P).size()>1)
            {   sprintf(Cad,"(%i , %i)",(R->P[1]).x,(R->P[1]).y);
                TextOut(hdc,x,y+15,Cad,strlen(Cad));
            }
            Mos(hdc,R->A,x-a/2,y+40,a/2);
            Mos(hdc,R->B,x+a/2,y+40,a/2);
        }
    }
};
BisectorTree A;
BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{   switch(uMsg)
    {   case WM_PAINT:
        {   PAINTSTRUCT ps;
            HDC hdc;
            hdc=BeginPaint(hwndDlg,&ps);
            Rectangle(hdc,pxi,pyi,pxf,pyf);
//            A.Crear1(hdc);
            A.MostrarP(hdc);
            A.MostrarR(hdc);
            A.Mostrar(hdc,800,50,500);
            EndPaint(hwndDlg,&ps);
        }
        return TRUE;
        case WM_LBUTTONDOWN:
        {   long xPos = GET_X_LPARAM(lParam);
            long yPos = GET_Y_LPARAM(lParam);
            if(xPos<pxf&&xPos>pxi&&yPos<pyf&&yPos>pyi)
            {   A.Ps.push_back(Punto((int)xPos,(int)yPos));
                A.ConstruirP();
                InvalidateRect(hwndDlg,NULL,true);
            }

        }
        return TRUE;
        case WM_INITDIALOG:
        {   pxi=10,pyi=50,pxf=pxi+450,pyf=pyi+450;
            //A.LlenarPuntos(10);
            A.ConstruirP();
        }
        return TRUE;
        case WM_MOUSEMOVE:
        {   long xPos = GET_X_LPARAM(lParam);
            long yPos = GET_Y_LPARAM(lParam);
            char Cad[20];
            sprintf(Cad,"%i",xPos);
            SetDlgItemText(hwndDlg,EDITX,Cad);
            sprintf(Cad,"%i",yPos);
            SetDlgItemText(hwndDlg,EDITY,Cad);
            if(xPos<pxf&&xPos>pxi&&yPos<pyf&&yPos>pyi)
            { //  InvalidateRect(hwndDlg,NULL,true);
            }
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
{   srand(time(NULL));
    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
