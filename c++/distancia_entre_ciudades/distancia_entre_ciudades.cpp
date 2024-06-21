#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#include <windows.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
// Los datos fueron extraídos de: https://proyectos.inei.gob.pe/web/BiblioINEIPub/BancoPub/Est/Lib0351/7114/711426.HTMl
// Ejemplo: http://gis.proviasnac.gob.pe/servicios/distancias/index_cms.htm
// Definición de los departamentos del Perú y sus distancias
unordered_map<wstring, unordered_map<wstring, int>> distancias = {
  {
    L"Arequipa", {
      {L"Abancay", 1026},
    }
  },
  {
    L"Ayacucho", {
      {L"Abancay", 399},
      {L"Arequipa", 1094},
    }
  },
  {
    L"Cajamarca", {
      {L"Abancay", 1768},
      {L"Arequipa", 1870},
      {L"Ayacucho", 1404},
    }
  },
  {
    L"Cerro de pasco", {
      {L"Abancay", 1209},
      {L"Arequipa", 1311},
      {L"Ayacucho", 510},
      {L"Cajamarca", 1163},
    }
  },
  {
    L"Cusco", {
      {L"Abancay", 198},
      {L"Arequipa", 513},
      {L"Ayacucho", 597},
      {L"Cajamarca", 1966},
      {L"Cerro de pasco", 1407},
    }
  },
  {
    L"Chachapoyas", {
      {L"Abancay", 2126},
      {L"Arequipa", 2228},
      {L"Ayacucho", 1762},
      {L"Cajamarca", 335},
      {L"Cerro de pasco", 1521},
      {L"Cusco", 2324},
    }
  },
  {
    L"Chiclayo", {
      {L"Abancay", 1677},
      {L"Arequipa", 1779},
      {L"Ayacucho", 1313},
      {L"Cajamarca", 265},
      {L"Cerro de pasco", 1072},
      {L"Cusco", 1875},
      {L"Chachapoyas", 449},
    }
  },
  {
    L"Chimbote", {
      {L"Abancay", 1329},
      {L"Arequipa", 1440},
      {L"Ayacucho", 974},
      {L"Cajamarca", 430},
      {L"Cerro de pasco", 733},
      {L"Cusco", 1536},
      {L"Chachapoyas", 788},
      {L"Chiclayo", 339},
    }
  },
  {
    L"Huancavelica", {
      {L"Abancay", 644},
      {L"Arequipa", 1046},
      {L"Ayacucho", 245},
      {L"Cajamarca", 1356},
      {L"Cerro de pasco", 402},
      {L"Cusco", 842},
      {L"Chachapoyas", 1714},
      {L"Chiclayo", 1265},
      {L"Chimbote", 926},
    }
  },
  {
    L"Huancayo", {
      {L"Abancay", 717},
      {L"Arequipa", 1307},
      {L"Ayacucho", 318},
      {L"Cajamarca", 1159},
      {L"Cerro de pasco", 252},
      {L"Cusco", 915},
      {L"Chachapoyas", 1517},
      {L"Chiclayo", 1068},
      {L"Chimbote", 729},
      {L"Huancavelica", 147},
    }
  },
  {
    L"Huanuco", {
      {L"Abancay", 1317},
      {L"Arequipa", 1419},
      {L"Ayacucho", 678},
      {L"Cajamarca", 1271},
      {L"Cerro de pasco", 108},
      {L"Cusco", 1515},
      {L"Chachapoyas", 1629},
      {L"Chiclayo", 1180},
      {L"Chimbote", 841},
      {L"Huancavelica", 507},
      {L"Huancayo", 360},
    }
  },
  {
    L"Huaraz", {
      {L"Abancay", 1313},
      {L"Arequipa", 1415},
      {L"Ayacucho", 949},
      {L"Cajamarca", 640},
      {L"Cerro de pasco", 457},
      {L"Cusco", 1511},
      {L"Chachapoyas", 998},
      {L"Chiclayo", 549},
      {L"Chimbote", 210},
      {L"Huancavelica", 901},
      {L"Huancayo", 704},
      {L"Huanuco", 349},
    }
  },
  {
    L"Ica", {
      {L"Abancay", 604},
      {L"Arequipa", 706},
      {L"Ayacucho", 388},
      {L"Cajamarca", 1164},
      {L"Cerro de pasco", 605},
      {L"Cusco", 802},
      {L"Chachapoyas", 1522},
      {L"Chiclayo", 1073},
      {L"Chimbote", 734},
      {L"Huancavelica", 340},
      {L"Huancayo", 601},
      {L"Huanuco", 713},
      {L"Huaraz", 709},
    }
  },
  {
    L"La oroya", {
      {L"Abancay", 841},
      {L"Arequipa", 1183},
      {L"Ayacucho", 442},
      {L"Cajamarca", 1035},
      {L"Cerro de pasco", 128},
      {L"Cusco", 1279},
      {L"Chachapoyas", 1393},
      {L"Chiclayo", 944},
      {L"Chimbote", 605},
      {L"Huancavelica", 271},
      {L"Huancayo", 124},
      {L"Huanuco", 236},
      {L"Huaraz", 580},
      {L"Ica", 477},
    }
  },
  {
    L"Lima", {
      {L"Abancay", 907},
      {L"Arequipa", 1009},
      {L"Ayacucho", 543},
      {L"Cajamarca", 861},
      {L"Cerro de pasco", 302},
      {L"Cusco", 1105},
      {L"Chachapoyas", 1219},
      {L"Chiclayo", 770},
      {L"Chimbote", 431},
      {L"Huancavelica", 495},
      {L"Huancayo", 298},
      {L"Huanuco", 410},
      {L"Huaraz", 406},
      {L"Ica", 33},
      {L"La oroya", 174},
    }
  },
  {
    L"Moquegua", {
      {L"Abancay", 1162},
      {L"Arequipa", 220},
      {L"Ayacucho", 1230},
      {L"Cajamarca", 2006},
      {L"Cerro de pasco", 1447},
      {L"Cusco", 646},
      {L"Chachapoyas", 2364},
      {L"Chiclayo", 1915},
      {L"Chimbote", 1576},
      {L"Huancavelica", 1182},
      {L"Huancayo", 1443},
      {L"Huanuco", 1555},
      {L"Huaraz", 1551},
      {L"Ica", 842},
      {L"La oroya", 1319},
      {L"Lima", 1145},
    }
  },
  {
    L"Moyobamba", {
      {L"Abancay", 2270},
      {L"Arequipa", 2378},
      {L"Ayacucho", 1906},
      {L"Cajamarca", 571},
      {L"Cerro de pasco", 819},
      {L"Cusco", 2468},
      {L"Chachapoyas", 250},
      {L"Chiclayo", 593},
      {L"Chimbote", 932},
      {L"Huancavelica", 1858},
      {L"Huancayo", 171},
      {L"Huanuco", 711},
      {L"Huaraz", 1142},
      {L"Ica", 1666},
      {L"La oroya", 1537},
      {L"Lima", 1363},
      {L"Moquegua", 2508},
    }
  },
  {
    L"Piura", {
      {L"Abancay", 1888},
      {L"Arequipa", 1990},
      {L"Ayacucho", 1524},
      {L"Cajamarca", 476},
      {L"Cerro de pasco", 1283},
      {L"Cusco", 2086},
      {L"Chachapoyas", 520},
      {L"Chiclayo", 211},
      {L"Chimbote", 550},
      {L"Huancavelica", 1476},
      {L"Huancayo", 1279},
      {L"Huanuco", 1391},
      {L"Huaraz", 760},
      {L"Ica", 1284},
      {L"La oroya", 1155},
      {L"Lima", 981},
      {L"Moquegua", 2126},
      {L"Moyobamba", 664},
    }
  },
  {
    L"Pucallpa", {
      {L"Abancay", 1692},
      {L"Arequipa", 1794},
      {L"Ayacucho", 1328},
      {L"Cajamarca", 1646},
      {L"Cerro de pasco", 483},
      {L"Cusco", 1890},
      {L"Chachapoyas", 2004},
      {L"Chiclayo", 1555},
      {L"Chimbote", 1216},
      {L"Huancavelica", 1280},
      {L"Huancayo", 735},
      {L"Huanuco", 375},
      {L"Huaraz", 724},
      {L"Ica", 1088},
      {L"La oroya", 611},
      {L"Lima", 785},
      {L"Moquegua", 1930},
      {L"Moyobamba", 817},
      {L"Piura", 1766},
    }
  },
  {
    L"Puerto maldonado", {
      {L"Abancay", 731},
      {L"Arequipa", 946},
      {L"Ayacucho", 1130},
      {L"Cajamarca", 2499},
      {L"Cerro de pasco", 1940},
      {L"Cusco", 533},
      {L"Chachapoyas", 2857},
      {L"Chiclayo", 2408},
      {L"Chimbote", 2069},
      {L"Huancavelica", 1375},
      {L"Huancayo", 1448},
      {L"Huanuco", 248},
      {L"Huaraz", 2044},
      {L"Ica", 1335},
      {L"La oroya", 1812},
      {L"Lima", 1638},
      {L"Moquegua", 1079},
      {L"Moyobamba", 3001},
      {L"Piura", 2619},
      {L"Pucallpa", 2423},
    }
  },
  {
    L"Puno", {
      {L"Abancay", 587},
      {L"Arequipa", 326},
      {L"Ayacucho", 1420},
      {L"Cajamarca", 2196},
      {L"Cerro de pasco", 1635},
      {L"Cusco", 389},
      {L"Chachapoyas", 2554},
      {L"Chiclayo", 2105},
      {L"Chimbote", 1766},
      {L"Huancavelica", 1372},
      {L"Huancayo", 1633},
      {L"Huanuco", 1745},
      {L"Huaraz", 1741},
      {L"Ica", 1032},
      {L"La oroya", 1509},
      {L"Lima", 1335},
      {L"Moquegua", 257},
      {L"Moyobamba", 2698},
      {L"Piura", 2316},
      {L"Pucallpa", 2120},
      {L"Puerto maldonado", 823},
    }
  },
  {
    L"Tacna", {
      {L"Abancay", 1310},
      {L"Arequipa", 368},
      {L"Ayacucho", 1378},
      {L"Cajamarca", 2154},
      {L"Cerro de pasco", 1595},
      {L"Cusco", 804},
      {L"Chachapoyas", 2512},
      {L"Chiclayo", 2063},
      {L"Chimbote", 1724},
      {L"Huancavelica", 1335},
      {L"Huancayo", 1591},
      {L"Huanuco", 1703},
      {L"Huaraz", 1699},
      {L"Ica", 990},
      {L"La oroya", 1467},
      {L"Lima", 1293},
      {L"Moquegua", 158},
      {L"Moyobamba", 2656},
      {L"Piura", 2274},
      {L"Pucallpa", 2078},
      {L"Puerto maldonado", 1427},
      {L"Puno", 377},
    }
  },
  {
    L"Trujillo", {
      {L"Abancay", 1468},
      {L"Arequipa", 1570},
      {L"Ayacucho", 1104},
      {L"Cajamarca", 300},
      {L"Cerro de pasco", 863},
      {L"Cusco", 1666},
      {L"Chachapoyas", 658},
      {L"Chiclayo", 209},
      {L"Chimbote", 130},
      {L"Huancavelica", 1056},
      {L"Huancayo", 859},
      {L"Huanuco", 971},
      {L"Huaraz", 340},
      {L"Ica", 864},
      {L"La oroya", 735},
      {L"Lima", 561},
      {L"Moquegua", 1706},
      {L"Moyobamba", 802},
      {L"Piura", 420},
      {L"Pucallpa", 1346},
      {L"Puerto maldonado", 2199},
      {L"Puno", 1896},
      {L"Tacna", 1854},
    }
  },
  {
    L"Tumbes", {
      {L"Abancay", 2166},
      {L"Arequipa", 2268},
      {L"Ayacucho", 1802},
      {L"Cajamarca", 754},
      {L"Cerro de pasco", 1561},
      {L"Cusco", 2364},
      {L"Chachapoyas", 798},
      {L"Chiclayo", 488},
      {L"Chimbote", 828},
      {L"Huancavelica", 1754},
      {L"Huancayo", 1557},
      {L"Huanuco", 1669},
      {L"Huaraz", 1038},
      {L"Ica", 1562},
      {L"La oroya", 1433},
      {L"Lima", 1259},
      {L"Moquegua", 2404},
      {L"Moyobamba", 942},
      {L"Piura", 278},
      {L"Pucallpa", 2044},
      {L"Puerto maldonado", 2897},
      {L"Puno", 2594},
      {L"Tacna", 2552},
      {L"Trujillo", 694},
    }
  }
};
// Estructura para almacenar la ruta y la distancia total
struct Ruta {
  vector<wstring> ruta;
  int distancia_total;
};
// Función para encontrar la ruta más corta usando el algoritmo de Dijkstra
Ruta encontrarRutaMasCorta(const wstring& origen, const wstring& destino) {
  // Inicialización
  unordered_map<wstring, int> distancia;
  unordered_map<wstring, wstring> ruta_previa;
  priority_queue<pair<int, wstring>, vector<pair<int, wstring>>, greater<pair<int, wstring>>> pq;
  for (auto& p : distancias) {
    distancia[p.first] = INT_MAX;
    ruta_previa[p.first] = L"";
  }
  distancia[origen] = 0;
  pq.push({0, origen});
  // Algoritmo de Dijkstra
  while (!pq.empty()) {
    wstring actual = pq.top().second;
    int distancia_actual = pq.top().first;
    pq.pop();
    if (distancia_actual > distancia[actual]) continue;
    for (auto& vecino : distancias[actual]) {
      int nueva_distancia = distancia_actual + vecino.second;
      if (nueva_distancia < distancia[vecino.first]) {
        distancia[vecino.first] = nueva_distancia;
        ruta_previa[vecino.first] = actual;
        pq.push({nueva_distancia, vecino.first});
      }
    }
  }
  // Reconstruir la ruta desde el destino hacia atrás
  vector<wstring> ruta;
  for (wstring v = destino; v != L""; v = ruta_previa[v]) {
    ruta.push_back(v);
  }
  reverse(ruta.begin(), ruta.end());
  // Retornar la ruta y la distancia total
  return {ruta, distancia[destino]};
}
// Función para llenar los comboboxes con nombres de departamentos
void llenarCombobox(HWND hwnd, int idCombobox) {
  HWND combobox = GetDlgItem(hwnd, idCombobox);
  SendMessage(combobox, CB_RESETCONTENT, 0, 0);
  for (auto& depto : distancias) {
    SendMessage(combobox, CB_ADDSTRING, 0, (LPARAM)depto.first.c_str());
  }
  SendMessage(combobox, CB_SETCURSEL, 0, 0);
}
// Función principal de WinAPI para la interfaz gráfica
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  switch (uMsg) {
    case WM_CREATE: {
      // Crear controles: ComboBox, Botón, y cajas de texto para salida
      CreateWindow(L"COMBOBOX", L"", CBS_DROPDOWNLIST | WS_VISIBLE | WS_CHILD | WS_VSCROLL,
            10, 10, 150, 200, hwnd, (HMENU)1, nullptr, nullptr);
      CreateWindow(L"COMBOBOX", L"", CBS_DROPDOWNLIST | WS_VISIBLE | WS_CHILD | WS_VSCROLL,
            10, 40, 150, 200, hwnd, (HMENU)2, nullptr, nullptr);
      CreateWindow(L"BUTTON", L"Calcular", WS_VISIBLE | WS_CHILD,
            170, 10, 80, 30, hwnd, (HMENU)3, nullptr, nullptr);
      CreateWindow(L"STATIC", L"Distancia: ", WS_VISIBLE | WS_CHILD,
            10, 80, 150, 20, hwnd, (HMENU)4, nullptr, nullptr);
      CreateWindow(L"STATIC", L"Ruta más corta: ", WS_VISIBLE | WS_CHILD,
            10, 100, 150, 20, hwnd, (HMENU)5, nullptr, nullptr);
      CreateWindow(L"STATIC", L"Rutas alternas: ", WS_VISIBLE | WS_CHILD,
            10, 120, 150, 20, hwnd, (HMENU)6, nullptr, nullptr);
      // Llenar los comboboxes con nombres de departamentos
      llenarCombobox(hwnd, 1); // Origen
      llenarCombobox(hwnd, 2); // Destino
      break;
    }
    case WM_MOUSEWHEEL: {
      HWND hwndComboBox = GetDlgItem(hwnd, 1); // Obtener el handle del combobox
      if (hwndComboBox != NULL && IsWindowVisible(hwndComboBox)) {
        SendMessage(hwndComboBox, uMsg, wParam, lParam);
      }
      break;
    }
    case WM_COMMAND: {
      if (LOWORD(wParam) == 3) { // Botón "Calcular" presionado
        // Obtener origen y destino seleccionados
        wchar_t origen[256], destino[256];
        SendMessage(GetDlgItem(hwnd, 1), CB_GETLBTEXT, SendMessage(GetDlgItem(hwnd, 1), CB_GETCURSEL, 0, 0), (LPARAM)origen);
        SendMessage(GetDlgItem(hwnd, 2), CB_GETLBTEXT, SendMessage(GetDlgItem(hwnd, 2), CB_GETCURSEL, 0, 0), (LPARAM)destino);
        // Calcular la ruta más corta
        Ruta rutaMasCorta = encontrarRutaMasCorta(origen, destino);
        wcout << "Distancia: " << rutaMasCorta.distancia_total << " Km" << endl;
        // Mostrar resultados en las cajas de texto
        SetWindowText(GetDlgItem(hwnd, 4), (L"Distancia: " + to_wstring(rutaMasCorta.distancia_total) + L" Km").c_str());
        wstring rutaCortaStr = L"Ruta más corta: ";
        for (const auto& ciudad : rutaMasCorta.ruta) {
          rutaCortaStr += ciudad + L" -> ";
        }
        // wcout.imbue(locale(""));
        wcout << rutaCortaStr << endl << endl;
        rutaCortaStr = rutaCortaStr.substr(0, rutaCortaStr.size() - 4); // Eliminar el último " -> "
        SetWindowText(GetDlgItem(hwnd, 5), rutaCortaStr.c_str());
        // Aquí puedes calcular y mostrar rutas alternas si lo deseas
      }
      break;
    }
    case WM_SIZE: {
      // Redimensionar los controles si es necesario
      MoveWindow(GetDlgItem(hwnd, 1), 10, 10, 150, 200, TRUE);
      MoveWindow(GetDlgItem(hwnd, 2), 10, 40, 150, 200, TRUE);
      MoveWindow(GetDlgItem(hwnd, 3), 170, 10, 80, 30, TRUE);
      MoveWindow(GetDlgItem(hwnd, 4), 10, 80, 150, 20, TRUE);
      MoveWindow(GetDlgItem(hwnd, 5), 10, 110, 500, 20, TRUE);
      MoveWindow(GetDlgItem(hwnd, 6), 10, 140, 150, 20, TRUE);
      break;
    }
    case WM_CLOSE: {
      DestroyWindow(hwnd);
      break;
    }
    case WM_DESTROY: {
      PostQuitMessage(0);
      break;
    }
    default:
      return DefWindowProc(hwnd, uMsg, wParam, lParam);
  }
  return 0;
}
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
  // Crear ventana principal
  WNDCLASS wc = {};
  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = L"PeruDepartamentosApp";
  RegisterClass(&wc);
  HWND hwnd = CreateWindowEx(
    0,                              // Optional window styles
    L"PeruDepartamentosApp",        // Window class
    L"Rutas entre Departamentos del Perú", // Window title
    WS_OVERLAPPEDWINDOW,            // Window style
    // Size and position
    CW_USEDEFAULT, CW_USEDEFAULT, 800, 400, // Ajusta estos valores según tu necesidad
    NULL,       // Parent window
    NULL,       // Menu
    hInstance,  // Instance handle
    NULL        // Additional application data
  );
  if (hwnd == NULL) {
    return 0;
  }
  ShowWindow(hwnd, nCmdShow);
  MSG msg = {};
  while (GetMessage(&msg, nullptr, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return (int)msg.wParam;
}