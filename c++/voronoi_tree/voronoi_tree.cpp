#include <iostream>
#include <windows.h>
#include <windowsx.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
/* Declaration */
class Punto {
  public:
    int x, y;
    Punto(int, int);
};
class Nodo {
  public:
    Nodo *a, *b, *c;
    vector<Punto> puntos;
    vector<double> radios;
    vector<int> orden;
    Nodo(vector<Punto>, vector<double>, vector<int>);
};
class VoronoiTree {
  public:
    Nodo *raiz;
    vector<Punto> ps;
    int orden;
    VoronoiTree();
    void construir(Punto);
    void cons(Nodo *&, Punto);
    void dibujarMediatriz(HDC);
    void dibujarM(HDC, Nodo *&);
    void unirPuntos(HDC);
    void unirP(HDC, Nodo *&);
    void mostrarNodos(HDC, int, int, int);
    void mostrarPuntos(HDC);
    void mosP(HDC, Nodo *&);
    void mosN(HDC, Nodo *&, int, int, int);
    vector<Punto> busquedaPorRadio(Punto, int);
    void busquedaPR(Nodo *&, vector<Punto> *, Punto, int);
    vector<Punto> busquedaPorNCercanos(Punto, int);
    void busquedaPorNC(Nodo *&, vector<pair<Punto, double>> *, Punto);
    double distancia(Punto, Punto);
    Punto puntoMedio(Punto, Punto);
};
// Global variables
static TCHAR class_name[] = "Desktop App";
static TCHAR title_text[] = "Voronoi-Tree - Diagram";
vector<Punto> ps;
// Declaración del procedimiento de ventana
void SetPixel2(HDC, int, int, COLORREF);
void Draw8Points(HDC, int, int, int, int, COLORREF);
void CircleBresenham(HDC, int, int, int, int, COLORREF);
void dibujarLinea(HDC, int, int, int, int);
VoronoiTree vt;
string output;
HWND hejex, hejey;
HWND punto_b1, radio_c;
HWND punto_b2, npuntos;
HWND boton_buscar_r, boton_buscar_nc;
HWND boton_eliminar_up;
char c_x[10], c_y[10];
char c_radio_c[10], c_npuntos[10];
int i_radio_c, i_npuntos;
vector<Punto> resultados;
bool estado_b_buscar_r, estado_b_buscar_nc;
int width, height;
int x, y;
int radio;
vector<int> pos_caja(4, 0);
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(
  HINSTANCE hThisInstance,
  HINSTANCE hPrevInstance,
  LPSTR lpszArgument,
  int nFunsterStil
) {
  HWND hwnd; // Manipulador de ventana
  MSG mensaje; // Mensajes recibidos por la aplicación
  WNDCLASSEX wincl; // Estructura de datos para la clase de ventana
  // Estructura de la ventana
  wincl.hInstance = hThisInstance;
  wincl.lpszClassName = LPCSTR(class_name);
  wincl.lpfnWndProc = WindowProcedure; // Esta función es invocada por Windows
  wincl.style = CS_DBLCLKS; // Captura los doble-clicks
  wincl.cbSize = sizeof(WNDCLASSEX);
  // Usar icono y puntero por defector
  wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
  wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
  wincl.lpszMenuName = NULL; // Sin menú
  wincl.cbClsExtra = 0; // Sin información adicional para la
  wincl.cbWndExtra = 0; // clase o la ventana
  // Usar el color de fondo por defecto para la ventana
  //wincl.hbrBackground = GetSysColorBrush(COLOR_WINDOW + 5);
  wincl.hbrBackground = (HBRUSH)(COLOR_WINDOW + 11);
  // Registrar la clase de ventana, si falla, salir del programa
  if (!RegisterClassEx(&wincl)) return 0;
  // La clase está registrada, crear la ventana
  hwnd = CreateWindowEx(
    0, // Posibilidades de variación
    class_name, // Nombre de la clase
    title_text, // Texto del título
    WS_OVERLAPPEDWINDOW, // Tipo por defecto
    CW_USEDEFAULT, // Windows decide la posición
    CW_USEDEFAULT, // donde se coloca la ventana
    1300, // Ancho en pixels
    750, // Alto en pixels
    HWND_DESKTOP, // La ventana es hija del escritorio
    NULL, // Sin menú
    hThisInstance, // Manipulador de instancia
    NULL // No hay datos de creación de ventana
  );
  // Mostrar la ventana
  ShowWindow(hwnd, SW_SHOWDEFAULT);
  // Bucle de mensajes, se ejecuta hasta que haya error o GetMessage devuelva FALSE
  while (GetMessage(&mensaje, NULL, 0, 0) == TRUE) {
    // Traducir mensajes de teclas virtuales a mensajes de caracteres
    TranslateMessage(&mensaje);
    // Enviar mensaje al procedimiento de ventana
    DispatchMessage(&mensaje);
  }
  // Salir con valor de retorno
  return mensaje.wParam;
}
/* Definition */
Punto::Punto(int x = 0, int y = 0) {
  this->x = x;
  this->y = y;
}
Nodo::Nodo(vector<Punto> p, vector<double> r, vector<int> o) {
  this->a = NULL;
  this->b = NULL;
  this->c = NULL;
  this->puntos = p;
  this->radios = r;
  this->orden = o;
}
VoronoiTree::VoronoiTree() {
  this->raiz = NULL;
  this->orden = 0;
}
void VoronoiTree::construir(Punto nuevo_punto) {
  cons(raiz, nuevo_punto);
}
void VoronoiTree::cons(Nodo *&r, Punto nuevo_punto) {
  int i = 0, pos_p;
  double d, dist_min = INT32_MAX;
  if (r == NULL) {
    orden++;
    r = new Nodo(vector<Punto>{nuevo_punto}, vector<double>{0}, vector<int>{orden});
  }
  else {
    if (r->puntos.size() < 3) {
      r->puntos.push_back(nuevo_punto);
      r->radios.push_back(0);
      orden++;
      r->orden.push_back(orden);
    }
    else {
      for (Punto p : r->puntos) {
        d = distancia(nuevo_punto, p);
        if (d < dist_min) {
          dist_min = d;
          pos_p = i;
        }
        i++;
      }
      d = distancia((r->puntos).at(pos_p), nuevo_punto);
      if (d > (r->radios).at(pos_p)) {
        (r->radios).at(pos_p) = d;
      }
      if (pos_p == 0) {
        cons(r->a, nuevo_punto);
      }
      else if (pos_p == 1) {
        cons(r->b, nuevo_punto);
      }
      else {
        cons(r->c, nuevo_punto);
      }
    }
  }
}
void VoronoiTree::dibujarMediatriz(HDC hdc) {
  dibujarM(hdc, raiz);
}
void VoronoiTree::dibujarM(HDC hdc, Nodo *&r) {
  if (r != NULL) {
    float x3, y3, xi, yi, xf, yf, m;
    for (int i = 0; i < (r->puntos.size() - 1); i++) {
      for (int j = i + 1; j < r->puntos.size(); j++) {
        x3 = (float)(((r->puntos).at(i)).x + ((r->puntos).at(j)).x)/2;
        y3 = (float)(((r->puntos).at(i)).y + ((r->puntos).at(j)).y)/2;
        m = (float)(((r->puntos).at(j)).y - ((r->puntos).at(i)).y)/(((r->puntos).at(j)).x - ((r->puntos).at(i)).x);
        xi = (float)pos_caja[0];
        xf = (float)pos_caja[2];
        yi = y3 - ((xi - x3)/m);
        yf = y3 - ((xf - x3)/m);
        if (yi < pos_caja[1]) {
          yi = pos_caja[1];
          xi = x3 - (m * (yi - y3));
        }
        if (yf > pos_caja[3]) {
          yf = pos_caja[3];
          xf = x3 - (m * (yf - y3));
        }
        // cout << "xi: " << xi << " yi: " << yi << "\txf: " << xf << " yf: " << yf << endl;
        dibujarLinea(hdc, (int)xi, (int)yi, (int)xf, (int)yf);
      }
    }
    dibujarM(hdc, r->a);
    dibujarM(hdc, r->b);
    dibujarM(hdc, r->c);
  }
}
void VoronoiTree::unirPuntos(HDC hdc) {
  unirP(hdc, raiz);
}
void VoronoiTree::unirP(HDC hdc, Nodo *&r) {
  if (r != NULL) {
    int xi, yi, xf, yf;
    for (int i = 0; i < (r->puntos.size() - 1); i++) {
      for (int j = i + 1; j < r->puntos.size(); j++) {
        xi = (r->puntos).at(i).x;
        yi = (r->puntos).at(i).y;
        xf = (r->puntos).at(j).x;
        yf = (r->puntos).at(j).y;
        dibujarLinea(hdc, xi, yi, xf, yf);
      }
    }
    unirP(hdc, r->a);
    unirP(hdc, r->b);
    unirP(hdc, r->c);
  }
}
void VoronoiTree::mostrarNodos(HDC hdc, int x, int y, int a) {
  mosN(hdc, raiz, x, y, a);
}
void VoronoiTree::mosN(HDC hdc, Nodo *&r, int x, int y, int a) {
  if (r != NULL) {
    int s = 0;
    SetTextColor(hdc, RGB(0, 0, 0));
    CreateFont(10, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
    for (Punto p : r->puntos) {
      output = "(" + to_string(p.x) + "," + to_string(p.y) + ")";
      TextOut(hdc, x, y + s, (output.c_str()), output.length());
      s += 15;
    }
    mosN(hdc, r->a, x - a/2, y + 100, a/2);
    mosN(hdc, r->b, x, y + 100, a/2);
    mosN(hdc, r->c, x + a/2, y + 100, a/2);
  }
}
void VoronoiTree::mostrarPuntos(HDC hdc) {
  mosP(hdc, raiz);
}
void VoronoiTree::mosP(HDC hdc, Nodo *& r) {
  if (r != NULL) {
    int radio_aux = 4;
    Punto p;
    double radio;
    int orden;
    SetTextColor(hdc, RGB(0, 150, 0));
    for (int i = 0; i < (r->puntos).size(); i++) {
      p = (r->puntos).at(i);
      radio = (r->radios).at(i);
      orden = (r->orden).at(i);
      // Mostrar numero de orden del punto
      output = to_string(orden);
      TextOut(hdc, p.x - 11, p.y + 5, (output.c_str()), output.length());
      // Mostrar posicion X, Y
      cout << orden << " " << "Punto -> " << "(" << p.x << ", " << p.y << ")" << endl;
      output = "(" + to_string((int)(p.x)) + "," + to_string((int)(p.y)) + ")";
      TextOut(hdc, p.x + 5, p.y + 5, (output.c_str()), output.length());
      // SelectObject(hdc, CreateSolidBrush(RGB(0, 150, 0)));
      // Ellipse(hdc, p.x - radio_aux, p.y - radio_aux, p.x + radio_aux, p.y + radio_aux);
      CircleBresenham(hdc, p.x, p.y, radio_aux, 1, RGB(0, 150, 0));
      CircleBresenham(hdc, p.x, p.y, radio_aux - 2, 1, RGB(0, 150, 0));
      CircleBresenham(hdc, p.x, p.y, radio_aux - 3, 1, RGB(0, 150, 0));
      // Dibujar radio de cobertura de cada punto
      if (radio != 0) {
        CircleBresenham(hdc, p.x, p.y, radio + radio_aux, 1, RGB(230, 150, 0));
      }
    }
    mosP(hdc, r->a);
    mosP(hdc, r->b);
    mosP(hdc, r->c);
  }
}
double VoronoiTree::distancia(Punto p1, Punto p2) {
  return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}
vector<Punto> VoronoiTree::busquedaPorRadio(Punto pb, int radio) {
  vector<Punto> pe;
  busquedaPR(raiz, &pe, pb, radio);
  return pe;
}
void VoronoiTree::busquedaPR(Nodo *&r, vector<Punto> *pe, Punto pb, int radio) {
  if (r != NULL) {
    for (Punto p : r->puntos) {
      if (distancia(pb, p) <= radio) {
        pe->push_back(p);
      }
    }
    busquedaPR(r->a, pe, pb, radio);
    busquedaPR(r->b, pe, pb, radio);
    busquedaPR(r->c, pe, pb, radio);
  }
}
vector<Punto> VoronoiTree::busquedaPorNCercanos(Punto pb, int n) {
  vector<Punto> pe;
  if (n <= ps.size()) {
    vector<pair<Punto, double>> pd;
    busquedaPorNC(raiz, &pd, pb);
    sort(pd.begin(), pd.end(), [](pair<Punto, double> a, pair<Punto, double> b) -> bool {
      return (a.second < b.second);
    });
    /* for (int i = 0; i < pd.size(); i++) {
      cout << "(" << pd.at(i).first.x << "," << pd.at(i).first.y << "; " << pd.at(i).second << "), ";
    }
    cout << endl; */
    for (int i = 0; i < n; i++) {
      pe.push_back(pd.at(i).first);
    }
  }
  return pe;
}
void VoronoiTree::busquedaPorNC(Nodo *&r, vector<pair<Punto, double>> *pd, Punto pb) {
  if (r != NULL) {
    for (Punto p : r->puntos) {
      pd->push_back(make_pair(p, distancia(pb, p)));
    }
    busquedaPorNC(r->a, pd, pb);
    busquedaPorNC(r->b, pd, pb);
    busquedaPorNC(r->c, pd, pb);
  }
}
Punto VoronoiTree::puntoMedio(Punto a, Punto b) {
  Punto m;
  m.x = (a.x + b.x)/2;
  m.y = (a.y + b.y)/2;
  return m;
}
void SetPixel2(HDC hdc, int x, int y, COLORREF Color) {
  if(x > pos_caja[0] && x < pos_caja[2] && y > pos_caja[1] && y < pos_caja[3]) {
    SetPixel(hdc, x, y, Color);
  }
}
void Draw8Points(HDC hdc, int xc, int yc, int a, int b, COLORREF Color) {
  SetPixel2(hdc, xc+a, yc+b, Color);
  SetPixel2(hdc, xc-a, yc+b, Color);
  SetPixel2(hdc, xc-a, yc-b, Color);
  SetPixel2(hdc, xc+a, yc-b, Color);
  SetPixel2(hdc, xc+b, yc+a, Color);
  SetPixel2(hdc, xc-b, yc+a, Color);
  SetPixel2(hdc, xc-b, yc-a, Color);
  SetPixel2(hdc, xc+b, yc-a, Color);
}
void CircleBresenham(HDC hdc, int xc, int yc, int R, int rrr, COLORREF color) {
  int x = 0, y = R;
  int d = 1 - R;
  Draw8Points(hdc, xc, yc, x, y, color);
  while(x < y) {
    if(d < 0) {
      d += 2*x + 2;
    }
    else {
      d += 2*(x - y) + 5;
      y -= rrr;
    }
    x += rrr;
    Draw8Points(hdc, xc, yc, x, y, color);
  }
}
void dibujarLinea(HDC hdc, int xi, int yi, int xf, int yf) {
  MoveToEx(hdc, xi, yi, NULL);
  LineTo(hdc, xf, yf);
}
void ejemplo1() {
  vector<Punto> ejemplo_puntos;
  ejemplo_puntos.push_back(Punto(179, 479));
  ejemplo_puntos.push_back(Punto(309, 305));
  ejemplo_puntos.push_back(Punto(411, 460));
  ejemplo_puntos.push_back(Punto(92, 523));
  ejemplo_puntos.push_back(Punto(167, 572));
  ejemplo_puntos.push_back(Punto(244, 249));
  ejemplo_puntos.push_back(Punto(328, 185));
  ejemplo_puntos.push_back(Punto(383, 241));
  ejemplo_puntos.push_back(Punto(411, 550));
  ejemplo_puntos.push_back(Punto(494, 513));
  for (Punto p : ejemplo_puntos) {
    vt.construir(p);
  }
}
// Esta función es invocada por la función DispatchMessage()
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT mensaje, WPARAM wParam, LPARAM lParam) {
  switch (mensaje) { // Manipulador de mensaje
    case WM_CREATE:
      cout << title_text << endl;
      estado_b_buscar_r = false;
      estado_b_buscar_nc = false;
      pos_caja[0] = 10;
      pos_caja[1] = 150;
      pos_caja[2] = 650;
      pos_caja[3] = 650;
      // Ejemplo 1
      ejemplo1();
      hejex = CreateWindow(
        "EDIT",
        NULL,
        ES_LEFT | WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP,
        30, 10, 50, 20,
        hwnd,
        (HMENU)100,
        NULL,
        NULL
      );
      hejey = CreateWindow(
        "EDIT",
        NULL,
        ES_LEFT | WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP,
        130, 10, 50, 20,
        hwnd,
        (HMENU)101,
        NULL,
        NULL
      );
      radio_c = CreateWindow(
        "EDIT",
        NULL,
        ES_LEFT | WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP,
        50, 50, 50, 25,
        hwnd,
        (HMENU)102,
        NULL,
        NULL
      );
      boton_buscar_r = CreateWindowEx(
        0,
        "BUTTON",
        "Buscar por radio",
        ES_LEFT | WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP,
        130, 50, 120, 25,
        hwnd,
        (HMENU)200,
        NULL,
        NULL
      );
      npuntos = CreateWindow(
        "EDIT",
        NULL,
        ES_LEFT | WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP,
        50, 90, 50, 25,
        hwnd,
        (HMENU)103,
        NULL,
        NULL
      );
      boton_buscar_nc = CreateWindowEx(
        0,
        "BUTTON",
        "Buscar por N puntos cercanos",
        ES_LEFT | WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP,
        130, 90, 210, 25,
        hwnd,
        (HMENU)201,
        NULL,
        NULL
      );
      /* boton_eliminar_up = CreateWindowEx(
        0,
        "BUTTON",
        "Eliminar ultimo punto",
        ES_LEFT | WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP,
        375, 90, 150, 25,
        hwnd,
        (HMENU)202,
        NULL,
        NULL
      ); */
      break;
    case WM_PAINT:
      PAINTSTRUCT ps;
      HDC hdc;
      hdc = BeginPaint(hwnd, &ps);
      RECT rect;
      GetWindowRect(hwnd, &rect);
      width = (rect.right - rect.left);
      height = (rect.bottom - rect.top);
      // output = to_string(x) + ", " + to_string(y);
      output = "x:";
      TextOut(hdc, 10, 10, (output.c_str()), output.length());
      output = "y:";
      TextOut(hdc, 110, 10, (output.c_str()), output.length());
      SetTextColor(hdc, RGB(0, 0, 255));
      output = "radio:";
      TextOut(hdc, 10, 50, (output.c_str()), output.length());
      SetTextColor(hdc, RGB(255, 0, 0));
      output = "N:";
      TextOut(hdc, 10, 90, (output.c_str()), output.length());
      SetTextColor(hdc, RGB(0, 0, 0));
      Rectangle(hdc, pos_caja[0], pos_caja[1], pos_caja[2], pos_caja[3]);
      output = "(" + to_string((int)(pos_caja[0])) + "," + to_string((int)(pos_caja[1])) + ")";
      TextOut(hdc, pos_caja[0], pos_caja[1] - 20, (output.c_str()), output.length());
      output = "(" + to_string((int)(pos_caja[2])) + "," + to_string((int)(pos_caja[3])) + ")";
      TextOut(hdc, pos_caja[2], pos_caja[3], (output.c_str()), output.length());
      radio = 5;
      if (estado_b_buscar_r) {
        GetDlgItemText(hwnd, GetDlgCtrlID(hejex), c_x, 10); // posicion X
        GetDlgItemText(hwnd, GetDlgCtrlID(hejey), c_y, 10); // posicion Y
        GetDlgItemText(hwnd, GetDlgCtrlID(radio_c), c_radio_c, 10); // radio
        x = atoi(c_x);
        y = atoi(c_y);
        i_radio_c = atoi(c_radio_c);
        // Mostrar Punto X, Y
        output = "(" + string(c_x) + "," + string(c_y) + ")";
        SetTextColor(hdc, RGB(0, 0, 255));
        TextOut(hdc, x + 5, y + 5, (output.c_str()), output.length());
        cout << endl;
        cout << "[+] Busqueda por radio" << endl;
        cout << "Punto: (" << x << ", " << y << ")\t" << "radio: " << i_radio_c << endl;
        resultados = vt.busquedaPorRadio(Punto(x, y), i_radio_c);
        cout << "Nro puntos encontrados: " << resultados.size() << endl;
        cout << "Resultado: ";
        for (Punto p : resultados) {
          cout << "(" << p.x << ", " << p.y << ")" << " ";
        }
        cout << endl;
        cout.width(20);
        cout.fill('-');
        cout << "" << endl;
        // Dibujar el punto y radio de cobertura
        SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 255)));
        Ellipse(hdc, x - radio, y - radio, x + radio, y + radio);
        CircleBresenham(hdc, x, y, i_radio_c, 1, RGB(0, 0, 255));
        // SelectObject(hdc, GetStockObject(HOLLOW_BRUSH));
        // Ellipse(hdc, x - i_radio_c, y - i_radio_c, x + i_radio_c, y + i_radio_c);
        estado_b_buscar_r = false;
      }
      if (estado_b_buscar_nc) {
        GetDlgItemText(hwnd, GetDlgCtrlID(hejex), c_x, 10); // posicion X
        GetDlgItemText(hwnd, GetDlgCtrlID(hejey), c_y, 10); // posicion Y
        GetDlgItemText(hwnd, GetDlgCtrlID(npuntos), c_npuntos, 10); // N
        x = atoi(c_x);
        y = atoi(c_y);
        i_npuntos = atoi(c_npuntos);
        // Mostrar Punto X, Y
        output = "(" + string(c_x) + "," + string(c_y) + ")";
        SetTextColor(hdc, RGB(255, 0, 0));
        TextOut(hdc, x + 5, y + 5, (output.c_str()), output.length());
        cout << endl;
        cout << "[+] Busqueda de N puntos mas cercanos" << endl;
        cout << "Punto: (" << x << ", " << y << ")\t" << "N: " << i_npuntos << endl;
        resultados = vt.busquedaPorNCercanos(Punto(x, y), i_npuntos);
        cout << "Nro puntos encontrados: " << resultados.size() << endl;
        cout << "Resultado: ";
        for (Punto p : resultados) {
          cout << "(" << p.x << ", " << p.y << ")" << " ";
        }
        cout << endl;
        cout.width(20);
        cout.fill('-');
        cout << "" << endl;
        // Dibujar el punto y radio de cobertura (max distancia del conjunto de puntos mas cercanos)
        i_radio_c = (int)(vt.distancia(Punto(x, y), resultados.at(resultados.size() - 1)));
        SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));
        Ellipse(hdc, x - radio, y - radio, x + radio, y + radio);
        CircleBresenham(hdc, x, y, (i_radio_c + radio), 1, RGB(255, 0, 0));
        estado_b_buscar_nc = false;
      }
      // Dibujar los puntos dentro del area rectangular
      vt.mostrarPuntos(hdc);
      cout.width(20);
      cout.fill('-');
      cout << "" << endl;
      // Dibujar mediatriz
      // vt.dibujarMediatriz(hdc);
      // Unir puntos
      vt.unirPuntos(hdc);
      // Mostrar los nodos y puntos como texto
      vt.mostrarNodos(hdc, (3 * width)/4, 20, 350);
      EndPaint(hwnd, &ps);
      break;
    case WM_LBUTTONDOWN:
      x = GET_X_LPARAM(lParam);
      y = GET_Y_LPARAM(lParam);
      if (x > pos_caja[0] && x < pos_caja[2] && y > pos_caja[1] && y < pos_caja[3]) {
        vt.ps.push_back(Punto(x, y));
        vt.construir(Punto(x, y));
        InvalidateRect(hwnd, NULL, true);
      }
      break;
    case WM_MOUSEMOVE:
      /* x = GET_X_LPARAM(lParam);
      y = GET_Y_LPARAM(lParam);
      if (x > pos_caja[0] && x < pos_caja[2] && y > pos_caja[1] && y < pos_caja[3]) {
        SetDlgItemText(hwnd, 100, to_string(x).c_str());
        SetDlgItemText(hwnd, 101, to_string(y).c_str());
      } */
      break;
    case WM_COMMAND:
      switch (LOWORD(wParam)) {
        case 200:
          estado_b_buscar_r = true;
          InvalidateRect(hwnd, NULL, true);
          break;
        case 201:
          estado_b_buscar_nc = true;
          InvalidateRect(hwnd, NULL, true);
          break;
        /* case 202:
          cout << "Eliminar ultimo punto" << endl;
          if (vt.ps.size() >= 1) {
            vt.ps.pop_back();
            InvalidateRect(hwnd, NULL, true);
          }
          break; */
        default:
          break;
      }
      break;
    case WM_DESTROY:
      PostQuitMessage(0); // Envía el mensaje WM_QUIT a la cola de mensajes
      break;
    default: // Mensajes que no queremos manejar
      return DefWindowProc(hwnd, mensaje, wParam, lParam);
      break;
  }
  return 0;
}