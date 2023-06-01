#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"
HINSTANCE hInst;
using namespace std;
int EditDist(string& a,string& b) // Distancia de Edicion // Prog dinamica O(m*n)
{   int m = a.length(), n = b.length();
    int dp[m+1][n+1]={{0}};
    //vector < vector <int> > dp(m+1, vector<int>(n+1, 0));
    for (int i=0; i<=m; i++) // llenando casos base
        dp[i][0] = i;
    for (int j=0; j<=n; j++)
        dp[0][j] = j;
    for (int i=1; i<=m; i++) // llenar matriz prog dinamica
    {   for (int j=1; j<=n; j++)
        {   if (a[i-1] != b[j-1])
                dp[i][j] = min(1+dp[i-1][j],     //borrar
                            min(1 + dp[i][j-1],  //insertar
                             1 + dp[i-1][j-1])); //reemplazar
            else
                dp[i][j] = dp[i-1][j-1];
        }
    }
    return dp[m][n];
}
class Nodo
{   public:
    string Palabra; // Declara una variable para almacenar la palabra
    map <int,Nodo *> Sig; // Declara una estructura tipo map que tiene como clave "Distancia de Edicion" y como valor un puntero tipo Nodo
    Nodo(string P="")
    {   Palabra=P; // Por defecto la variable es una cadena vacia
    }
};
class ArbolBK
{   public:
    Nodo *Raiz; // Raiz del Arbol
    ArbolBK()
    {   Raiz=NULL; // Valor de la Raiz por defecto
    }
    void InsertarBloque(string S) // Inserta todas las palabras de la cadena S
    {   string token;
        stringstream cins(S); // Crea un buffer de cadenas
        while(getline(cins,token,' '))
            Insertar(token); // Inserta cada palabra del buffer en el arbol
    }
    void Insertar(string S) // Funcion que Inserta una palabra
    {   if(Raiz==NULL) // Verifica si el arbol esta vacio
            Raiz=new Nodo(S); // Se agrega el primer nodo al arbol
        else
            Ins(Raiz,S); // Agrega otro nodo al arbol
    }
    void Ins(Nodo *&R,string S) // Funcion que busca un lugar y agrega un nuevo Nodo al Arbol
    {   int dist=EditDist(R->Palabra,S); // Obtiene la distancia de edicion
        if(dist>0)
        {   if((R->Sig).find(dist)==(R->Sig).end()) // Busca la "dist" dentro del mapa del Nodo R
                (R->Sig)[dist]=new Nodo(S); // Agrega al mapa como clave = "dist" y valor = nuevo_nodo
            else
                Ins((R->Sig)[dist],S); // Se llama recursivamente hasta que no encuentre el valor "dist" dentro del mapa del Nodo R
        }
    }
    void Mostrar(long T) // Esta funcion muestra los valores con consola
    {   if(Raiz!=NULL)
            Mos(Raiz,T); // Mos() se llama solo si el arbol no esta vacio
        cout<<endl;
    }
    void Mos(Nodo *R,long T) // Muestra las palabras por consola
    {   cout<<T<<" -> "<<R->Palabra<<endl; // Imprime la Distancia de Edicion y la palabra
        map <int,Nodo *>::iterator it; // Declara un iterador de map
        for(it=(R->Sig).begin();it!=(R->Sig).end();it++) // Recorre cada elemento que esta en el mapa del Nodo
            Mos((*it).second,T*10+(*it).first);
    }
    void MostrarW(HDC hdc,int x,int y,int a)
    {   if(Raiz!=NULL)
            MosW(hdc,Raiz,x,y,a); // MosW() se llama solo si el arbol no esta vacio
    }
    void MosW(HDC hdc,Nodo *R,int x,int y,int a) // Muestra las palabras y la distancia de edicion graficamente
    {   map <int,Nodo *>::iterator it; // Declara un iterator de map
        int ii,ancho,tam=(R->Sig).size(); // Se declaran variables
        if(tam>0) // Verifica si hay elementos en el mapa del Nodo R
        {   ancho=a/tam; // Espacio entre cada elemento
            for(ii=0,it=(R->Sig).begin();it!=(R->Sig).end();it++,ii++) // Recorre cada uno de los elementos del mapa del Nodo R
            {   MoveToEx(hdc,x,y,NULL);
                LineTo(hdc,x+ii*ancho-a/2,y+100); // Se dibuja una linea para relacionar cada Nodo con sus Hijos
                MosW(hdc,(*it).second,x+ii*ancho-a/2,y+100,ancho-15); // Se llama recursivamente hasta que no se cumpla la condicion
                char Cad2[10]; // Declara una cadena para guardar la distancia de edicion
                sprintf(Cad2,"%i",(*it).first); // Guarda la distancia de edicion en Cad2
                TextOut(hdc,x+ii*ancho-a/2-10,y+100-5,Cad2,strlen(Cad2)); // Muestra graficamente la Distancia de edicion
            }
        }
        char Cad[2]=" "; // Declara una cadena para guardar cada caracter de la palabra
        for(ii=0;ii<strlen((R->Palabra).c_str());ii++) // Muestra cada caracter en una nueva linea
        {   Cad[0]=((R->Palabra).c_str())[ii]; // Almacena un caracter en Cad[0]
            TextOut(hdc,x+1,y+1+ii*14,Cad,1); // Muestra el caracter
        }
    }
    vector <string> similar(Nodo *R,string S,int Tol) // Funcion devuelve un vector de cadenas similares a la cadena S
    {   int dist, var;
        vector <string> ret;
        if(R!=NULL)
        {   dist=EditDist(R->Palabra,S); // Obtiene la distancia de edicion
            if(dist<=Tol) // Verifica si la distancia de edici�n es menor o igual que Tol
                ret.push_back(R->Palabra); // Agregar la cadena al vector "ret"
            var=dist-Tol;
            if(var<0)
                var=1;
            vector <string> tmp; // Declara un vector de cadenas temporal
            for(;var<dist+Tol;var++)
            {   if((R->Sig).find(var)!=(R->Sig).end()) // Busca la distancia de edicion dentro del mapa del Nodo R
                {   tmp=similar((R->Sig)[var],S,Tol); // Se llama recursivamente hasta que R sea NULL
                    ret.insert(ret.end(),tmp.begin(),tmp.end()); // Se inserta todos los elementos del vector "tmp" en "ret"
                }
            }
        }
        return ret; // Retorna el vector de cadenas "ret"
    }
};
ArbolBK A; // Se crea un instancia (objeto) de la clase ArbolBK
BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{   switch(uMsg)
    {   case WM_PAINT:
        {   PAINTSTRUCT ps;
            HDC hdc;
            hdc=BeginPaint(hwndDlg,&ps);
            A.MostrarW(hdc,650,50,700); // Muestra todas las palabras del arbol
            A.Mostrar(1); // Muestra por consola la Distancia de Edicion y la palabra
            EndPaint(hwndDlg,&ps);
        }
        case WM_INITDIALOG:
        {
        }
        return TRUE;
        case WM_CLOSE:
        {   EndDialog(hwndDlg, 0);
        }
        return TRUE;
        case WM_COMMAND:
        {   switch(LOWORD(wParam))
            {   case INSERTAR:
                {   char Cad[500];
                    GetDlgItemText(hwndDlg,PAL,Cad,500);
                    A.InsertarBloque(Cad); // Inserta la cadena en el arbol
                    InvalidateRect(hwndDlg,NULL,true);
                }
                return TRUE;
                case BUSCAR:
                {   char Cad2[20];
                    GetDlgItemText(hwndDlg,BUSQ,Cad2,20);
                    int Tol=GetDlgItemInt(hwndDlg,TOL,NULL,NULL);
                    vector <string> R=A.similar(A.Raiz,Cad2,Tol); // Almacena un vector de cadenas
                    stringstream ss; // Declara un buffer de cadenas
                    for(int i=0;i<R.size();i++)
                        ss<<R[i]<<" "; // Redirige cada elemento del vector R al buffer de cadenas
                    SetDlgItemTextA(hwndDlg,RESUL,(ss.str()).c_str());
                }
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
