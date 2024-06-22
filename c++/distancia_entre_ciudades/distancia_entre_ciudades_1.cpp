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
/* Para compilar este archivo abre tu consola y ejecuta el siguiente comando:
g++ -mconsole -mwindows -municode distancia_entre_ciudades.cpp -o output.exe
*/
// Los datos fueron extraídos de: https://proyectos.inei.gob.pe/web/BiblioINEIPub/BancoPub/Est/Lib0351/7114/711426.HTMl
// Ejemplo: http://gis.proviasnac.gob.pe/servicios/distancias/index_cms.htm
// Definición de los departamentos del Perú y sus distancias
unordered_map<wstring, unordered_map<wstring, int>> distancias = {
  { L"Arequipa", {
    { L"Abancay", 1026 },
    { L"Ayacucho", 1094 },
    { L"Cajamarca", 1870 },
    { L"Cerro de pasco", 1311 },
    { L"Cusco", 513 },
    { L"Chachapoyas", 2228 },
    { L"Chiclayo", 1779 },
    { L"Chimbote", 1440 },
    { L"Huancavelica", 1046 },
    { L"Huancayo", 1307 },
    { L"Huanuco", 1419 },
    { L"Huaraz", 1415 },
    { L"Ica", 706 },
    { L"La oroya", 1183 },
    { L"Lima", 1009 },
    { L"Moquegua", 220 },
    { L"Moyobamba", 2378 },
    { L"Piura", 1990 },
    { L"Pucallpa", 1794 },
    { L"Puerto maldonado", 946 },
    { L"Puno", 326 },
    { L"Tacna", 368 },
    { L"Trujillo", 1570 },
    { L"Tumbes", 2268 },
  }},
  { L"Ayacucho", {
    { L"Abancay", 399 },
    { L"Arequipa", 1094 },
    { L"Cajamarca", 1404 },
    { L"Cerro de pasco", 510 },
    { L"Cusco", 597 },
    { L"Chachapoyas", 1762 },
    { L"Chiclayo", 1313 },
    { L"Chimbote", 974 },
    { L"Huancavelica", 245 },
    { L"Huancayo", 318 },
    { L"Huanuco", 678 },
    { L"Huaraz", 949 },
    { L"Ica", 388 },
    { L"La oroya", 442 },
    { L"Lima", 543 },
    { L"Moquegua", 1230 },
    { L"Moyobamba", 1906 },
    { L"Piura", 1524 },
    { L"Pucallpa", 1328 },
    { L"Puerto maldonado", 1130 },
    { L"Puno", 1420 },
    { L"Tacna", 1378 },
    { L"Trujillo", 1104 },
    { L"Tumbes", 1802 },
  }},
  { L"Cajamarca", {
    { L"Abancay", 1768 },
    { L"Arequipa", 1870 },
    { L"Ayacucho", 1404 },
    { L"Cerro de pasco", 1163 },
    { L"Cusco", 1966 },
    { L"Chachapoyas", 335 },
    { L"Chiclayo", 265 },
    { L"Chimbote", 430 },
    { L"Huancavelica", 1356 },
    { L"Huancayo", 1159 },
    { L"Huanuco", 1271 },
    { L"Huaraz", 640 },
    { L"Ica", 1164 },
    { L"La oroya", 1035 },
    { L"Lima", 861 },
    { L"Moquegua", 2006 },
    { L"Moyobamba", 571 },
    { L"Piura", 476 },
    { L"Pucallpa", 1646 },
    { L"Puerto maldonado", 2499 },
    { L"Puno", 2196 },
    { L"Tacna", 2154 },
    { L"Trujillo", 300 },
    { L"Tumbes", 754 },
  }},
  { L"Cerro de pasco", {
    { L"Abancay", 1209 },
    { L"Arequipa", 1311 },
    { L"Ayacucho", 510 },
    { L"Cajamarca", 1163 },
    { L"Cusco", 1407 },
    { L"Chachapoyas", 1521 },
    { L"Chiclayo", 1072 },
    { L"Chimbote", 733 },
    { L"Huancavelica", 402 },
    { L"Huancayo", 252 },
    { L"Huanuco", 108 },
    { L"Huaraz", 457 },
    { L"Ica", 605 },
    { L"La oroya", 128 },
    { L"Lima", 302 },
    { L"Moquegua", 1447 },
    { L"Moyobamba", 819 },
    { L"Piura", 1283 },
    { L"Pucallpa", 483 },
    { L"Puerto maldonado", 1940 },
    { L"Puno", 1635 },
    { L"Tacna", 1595 },
    { L"Trujillo", 863 },
    { L"Tumbes", 1561 },
  }},
  { L"Cusco", {
    { L"Abancay", 198 },
    { L"Arequipa", 513 },
    { L"Ayacucho", 597 },
    { L"Cajamarca", 1966 },
    { L"Cerro de pasco", 1407 },
    { L"Chachapoyas", 2324 },
    { L"Chiclayo", 1875 },
    { L"Chimbote", 1536 },
    { L"Huancavelica", 842 },
    { L"Huancayo", 915 },
    { L"Huanuco", 1515 },
    { L"Huaraz", 1511 },
    { L"Ica", 802 },
    { L"La oroya", 1279 },
    { L"Lima", 1105 },
    { L"Moquegua", 646 },
    { L"Moyobamba", 2468 },
    { L"Piura", 2086 },
    { L"Pucallpa", 1890 },
    { L"Puerto maldonado", 533 },
    { L"Puno", 389 },
    { L"Tacna", 804 },
    { L"Trujillo", 1666 },
    { L"Tumbes", 2364 },
  }},
  { L"Chachapoyas", {
    { L"Abancay", 2126 },
    { L"Arequipa", 2228 },
    { L"Ayacucho", 1762 },
    { L"Cajamarca", 335 },
    { L"Cerro de pasco", 1521 },
    { L"Cusco", 2324 },
    { L"Chiclayo", 449 },
    { L"Chimbote", 788 },
    { L"Huancavelica", 1714 },
    { L"Huancayo", 1517 },
    { L"Huanuco", 1629 },
    { L"Huaraz", 998 },
    { L"Ica", 1522 },
    { L"La oroya", 1393 },
    { L"Lima", 1219 },
    { L"Moquegua", 2364 },
    { L"Moyobamba", 250 },
    { L"Piura", 520 },
    { L"Pucallpa", 2004 },
    { L"Puerto maldonado", 2857 },
    { L"Puno", 2554 },
    { L"Tacna", 2512 },
    { L"Trujillo", 658 },
    { L"Tumbes", 798 },
  }},
  { L"Chiclayo", {
    { L"Abancay", 1677 },
    { L"Arequipa", 1779 },
    { L"Ayacucho", 1313 },
    { L"Cajamarca", 265 },
    { L"Cerro de pasco", 1072 },
    { L"Cusco", 1875 },
    { L"Chachapoyas", 449 },
    { L"Chimbote", 339 },
    { L"Huancavelica", 1265 },
    { L"Huancayo", 1068 },
    { L"Huanuco", 1180 },
    { L"Huaraz", 549 },
    { L"Ica", 1073 },
    { L"La oroya", 944 },
    { L"Lima", 770 },
    { L"Moquegua", 1915 },
    { L"Moyobamba", 593 },
    { L"Piura", 211 },
    { L"Pucallpa", 1555 },
    { L"Puerto maldonado", 2408 },
    { L"Puno", 2105 },
    { L"Tacna", 2063 },
    { L"Trujillo", 209 },
    { L"Tumbes", 488 },
  }},
  { L"Chimbote", {
    { L"Abancay", 1341 },
    { L"Arequipa", 1440 },
    { L"Ayacucho", 974 },
    { L"Cajamarca", 430 },
    { L"Cerro de pasco", 733 },
    { L"Cusco", 1536 },
    { L"Chachapoyas", 788 },
    { L"Chiclayo", 339 },
    { L"Huancavelica", 1171 },
    { L"Huancayo", 973 },
    { L"Huanuco", 1085 },
    { L"Huaraz", 454 },
    { L"Ica", 893 },
    { L"La oroya", 764 },
    { L"Lima", 590 },
    { L"Moquegua", 1735 },
    { L"Moyobamba", 1113 },
    { L"Piura", 493 },
    { L"Pucallpa", 1434 },
    { L"Puerto maldonado", 2287 },
    { L"Puno", 1984 },
    { L"Tacna", 1942 },
    { L"Trujillo", 413 },
    { L"Tumbes", 692 },
  }},
  { L"Huancavelica", {
    { L"Abancay", 994 },
    { L"Arequipa", 1046 },
    { L"Ayacucho", 245 },
    { L"Cajamarca", 1356 },
    { L"Cerro de pasco", 402 },
    { L"Cusco", 842 },
    { L"Chachapoyas", 1714 },
    { L"Chiclayo", 1265 },
    { L"Chimbote", 1171 },
    { L"Huancayo", 239 },
    { L"Huanuco", 559 },
    { L"Huaraz", 830 },
    { L"Ica", 491 },
    { L"La oroya", 272 },
    { L"Lima", 556 },
    { L"Moquegua", 1313 },
    { L"Moyobamba", 1650 },
    { L"Piura", 1414 },
    { L"Pucallpa", 1228 },
    { L"Puerto maldonado", 1157 },
    { L"Puno", 1447 },
    { L"Tacna", 1405 },
    { L"Trujillo", 1078 },
    { L"Tumbes", 1776 },
  }},
  { L"Huancayo", {
    { L"Abancay", 809 },
    { L"Arequipa", 1307 },
    { L"Ayacucho", 318 },
    { L"Cajamarca", 1159 },
    { L"Cerro de pasco", 252 },
    { L"Cusco", 915 },
    { L"Chachapoyas", 1517 },
    { L"Chiclayo", 1068 },
    { L"Chimbote", 973 },
    { L"Huancavelica", 239 },
    { L"Huanuco", 320 },
    { L"Huaraz", 507 },
    { L"Ica", 749 },
    { L"La oroya", 380 },
    { L"Lima", 271 },
    { L"Moquegua", 1526 },
    { L"Moyobamba", 1648 },
    { L"Piura", 1424 },
    { L"Pucallpa", 1020 },
    { L"Puerto maldonado", 1373 },
    { L"Puno", 1071 },
    { L"Tacna", 1029 },
    { L"Trujillo", 771 },
    { L"Tumbes", 1060 },
  }},
  { L"Huanuco", {
    { L"Abancay", 963 },
    { L"Arequipa", 1419 },
    { L"Ayacucho", 678 },
    { L"Cajamarca", 1271 },
    { L"Cerro de pasco", 108 },
    { L"Cusco", 1515 },
    { L"Chachapoyas", 1629 },
    { L"Chiclayo", 1180 },
    { L"Chimbote", 1085 },
    { L"Huancavelica", 559 },
    { L"Huancayo", 320 },
    { L"Huaraz", 369 },
    { L"Ica", 771 },
    { L"La oroya", 240 },
    { L"Lima", 422 },
    { L"Moquegua", 1731 },
    { L"Moyobamba", 1401 },
    { L"Piura", 1548 },
    { L"Pucallpa", 904 },
    { L"Puerto maldonado", 1806 },
    { L"Puno", 1501 },
    { L"Tacna", 1459 },
    { L"Trujillo", 971 },
    { L"Tumbes", 1481 },
  }},
  { L"Huaraz", {
    { L"Abancay", 1120 },
    { L"Arequipa", 1415 },
    { L"Ayacucho", 949 },
    { L"Cajamarca", 640 },
    { L"Cerro de pasco", 457 },
    { L"Cusco", 1511 },
    { L"Chachapoyas", 998 },
    { L"Chiclayo", 549 },
    { L"Chimbote", 454 },
    { L"Huancavelica", 830 },
    { L"Huancayo", 507 },
    { L"Huanuco", 369 },
    { L"Ica", 1068 },
    { L"La oroya", 537 },
    { L"Lima", 418 },
    { L"Moquegua", 1663 },
    { L"Moyobamba", 1205 },
    { L"Piura", 1079 },
    { L"Pucallpa", 1131 },
    { L"Puerto maldonado", 2084 },
    { L"Puno", 1779 },
    { L"Tacna", 1737 },
    { L"Trujillo", 579 },
    { L"Tumbes", 877 },
  }},
  { L"Ica", {
    { L"Abancay", 684 },
    { L"Arequipa", 706 },
    { L"Ayacucho", 388 },
    { L"Cajamarca", 1164 },
    { L"Cerro de pasco", 605 },
    { L"Cusco", 802 },
    { L"Chachapoyas", 1522 },
    { L"Chiclayo", 1073 },
    { L"Chimbote", 893 },
    { L"Huancavelica", 491 },
    { L"Huancayo", 749 },
    { L"Huanuco", 771 },
    { L"Huaraz", 1068 },
    { L"La oroya", 837 },
    { L"Lima", 300 },
    { L"Moquegua", 832 },
    { L"Moyobamba", 1688 },
    { L"Piura", 982 },
    { L"Pucallpa", 1386 },
    { L"Puerto maldonado", 2240 },
    { L"Puno", 1937 },
    { L"Tacna", 1895 },
    { L"Trujillo", 547 },
    { L"Tumbes", 848 },
  }},
  { L"La oroya", {
    { L"Abancay", 1107 },
    { L"Arequipa", 1183 },
    { L"Ayacucho", 442 },
    { L"Cajamarca", 1035 },
    { L"Cerro de pasco", 128 },
    { L"Cusco", 1279 },
    { L"Chachapoyas", 1393 },
    { L"Chiclayo", 944 },
    { L"Chimbote", 764 },
    { L"Huancavelica", 272 },
    { L"Huancayo", 380 },
    { L"Huanuco", 240 },
    { L"Huaraz", 537 },
    { L"Ica", 837 },
    { L"Lima", 639 },
    { L"Moquegua", 1315 },
    { L"Moyobamba", 1432 },
    { L"Piura", 1406 },
    { L"Pucallpa", 1193 },
    { L"Puerto maldonado", 1122 },
    { L"Puno", 1417 },
    { L"Tacna", 1375 },
    { L"Trujillo", 783 },
    { L"Tumbes", 1556 },
  }},
  { L"Lima", {
    { L"Abancay", 1003 },
    { L"Arequipa", 1009 },
    { L"Ayacucho", 543 },
    { L"Cajamarca", 861 },
    { L"Cerro de pasco", 302 },
    { L"Cusco", 1105 },
    { L"Chachapoyas", 1215 },
    { L"Chiclayo", 770 },
    { L"Chimbote", 590 },
    { L"Huancavelica", 556 },
    { L"Huancayo", 271 },
    { L"Huanuco", 422 },
    { L"Huaraz", 418 },
    { L"Ica", 300 },
    { L"La oroya", 639 },
    { L"Moquegua", 1318 },
    { L"Moyobamba", 1451 },
    { L"Piura", 1130 },
    { L"Pucallpa", 1020 },
    { L"Puerto maldonado", 1262 },
    { L"Puno", 1576 },
    { L"Tacna", 1434 },
    { L"Trujillo", 557 },
    { L"Tumbes", 1158 },
  }},
  { L"Moquegua", {
    { L"Abancay", 770 },
    { L"Arequipa", 308 },
    { L"Ayacucho", 992 },
    { L"Cajamarca", 1407 },
    { L"Cerro de pasco", 1342 },
    { L"Cusco", 764 },
    { L"Chachapoyas", 1250 },
    { L"Chiclayo", 801 },
    { L"Chimbote", 1735 },
    { L"Huancavelica", 1313 },
    { L"Huancayo", 1526 },
    { L"Huanuco", 1731 },
    { L"Huaraz", 1663 },
    { L"Ica", 832 },
    { L"La oroya", 1315 },
    { L"Lima", 1318 },
    { L"Moyobamba", 1413 },
    { L"Piura", 905 },
    { L"Pucallpa", 947 },
    { L"Puerto maldonado", 2300 },
    { L"Puno", 537 },
    { L"Tacna", 215 },
    { L"Trujillo", 1177 },
    { L"Tumbes", 1410 },
  }},
  { L"Moyobamba", {
    { L"Abancay", 1087 },
    { L"Arequipa", 1442 },
    { L"Ayacucho", 639 },
    { L"Cajamarca", 1383 },
    { L"Cerro de pasco", 1494 },
    { L"Cusco", 1137 },
    { L"Chachapoyas", 437 },
    { L"Chiclayo", 786 },
    { L"Chimbote", 1113 },
    { L"Huancavelica", 1650 },
    { L"Huancayo", 1648 },
    { L"Huanuco", 1401 },
    { L"Huaraz", 1205 },
    { L"Ica", 1688 },
    { L"La oroya", 1432 },
    { L"Lima", 1451 },
    { L"Moquegua", 1413 },
    { L"Piura", 1074 },
    { L"Pucallpa", 679 },
    { L"Puerto maldonado", 2028 },
    { L"Puno", 1742 },
    { L"Tacna", 1723 },
    { L"Trujillo", 660 },
    { L"Tumbes", 951 },
  }},
  { L"Piura", {
    { L"Abancay", 539 },
    { L"Arequipa", 1226 },
    { L"Ayacucho", 1201 },
    { L"Cajamarca", 1023 },
    { L"Cerro de pasco", 1283 },
    { L"Cusco", 1300 },
    { L"Chachapoyas", 752 },
    { L"Chiclayo", 211 },
    { L"Chimbote", 493 },
    { L"Huancavelica", 1414 },
    { L"Huancayo", 1424 },
    { L"Huanuco", 1548 },
    { L"Huaraz", 1079 },
    { L"Ica", 982 },
    { L"La oroya", 1406 },
    { L"Lima", 1130 },
    { L"Moquegua", 905 },
    { L"Moyobamba", 1074 },
    { L"Pucallpa", 1395 },
    { L"Puerto maldonado", 2321 },
    { L"Puno", 1888 },
    { L"Tacna", 1846 },
    { L"Trujillo", 542 },
    { L"Tumbes", 165 },
  }},
  { L"Pucallpa", {
    { L"Abancay", 984 },
    { L"Arequipa", 1532 },
    { L"Ayacucho", 960 },
    { L"Cajamarca", 1383 },
    { L"Cerro de pasco", 1356 },
    { L"Cusco", 1678 },
    { L"Chachapoyas", 1382 },
    { L"Chiclayo", 1165 },
    { L"Chimbote", 1434 },
    { L"Huancavelica", 1228 },
    { L"Huancayo", 1020 },
    { L"Huanuco", 904 },
    { L"Huaraz", 1131 },
    { L"Ica", 1386 },
    { L"La oroya", 1193 },
    { L"Lima", 1020 },
    { L"Moquegua", 947 },
    { L"Moyobamba", 679 },
    { L"Piura", 1395 },
    { L"Puerto maldonado", 2023 },
    { L"Puno", 1721 },
    { L"Tacna", 2016 },
    { L"Trujillo", 877 },
    { L"Tumbes", 1225 },
  }},
  { L"Puerto maldonado", {
    { L"Abancay", 1640 },
    { L"Arequipa", 2188 },
    { L"Ayacucho", 1654 },
    { L"Cajamarca", 2107 },
    { L"Cerro de pasco", 1444 },
    { L"Cusco", 1568 },
    { L"Chachapoyas", 856 },
    { L"Chiclayo", 1617 },
    { L"Chimbote", 2164 },
    { L"Huancavelica", 1157 },
    { L"Huancayo", 1373 },
    { L"Huanuco", 1806 },
    { L"Huaraz", 2084 },
    { L"Ica", 2240 },
    { L"La oroya", 1122 },
    { L"Lima", 1262 },
    { L"Moquegua", 2300 },
    { L"Moyobamba", 2028 },
    { L"Piura", 2321 },
    { L"Pucallpa", 2023 },
    { L"Puno", 2481 },
    { L"Tacna", 2465 },
    { L"Trujillo", 1688 },
    { L"Tumbes", 2143 },
  }},
  { L"Puno", {
    { L"Abancay", 499 },
    { L"Arequipa", 441 },
    { L"Ayacucho", 975 },
    { L"Cajamarca", 1176 },
    { L"Cerro de pasco", 1580 },
    { L"Cusco", 389 },
    { L"Chachapoyas", 1441 },
    { L"Chiclayo", 1346 },
    { L"Chimbote", 1984 },
    { L"Huancavelica", 1447 },
    { L"Huancayo", 1071 },
    { L"Huanuco", 1501 },
    { L"Huaraz", 1779 },
    { L"Ica", 1937 },
    { L"La oroya", 1417 },
    { L"Lima", 1576 },
    { L"Moquegua", 537 },
    { L"Moyobamba", 1742 },
    { L"Piura", 1888 },
    { L"Pucallpa", 1721 },
    { L"Puerto maldonado", 2481 },
    { L"Tacna", 422 },
    { L"Trujillo", 1260 },
    { L"Tumbes", 1707 },
  }},
  { L"Tacna", {
    { L"Abancay", 1456 },
    { L"Arequipa", 285 },
    { L"Ayacucho", 1051 },
    { L"Cajamarca", 1555 },
    { L"Cerro de pasco", 1815 },
    { L"Cusco", 887 },
    { L"Chachapoyas", 1528 },
    { L"Chiclayo", 1379 },
    { L"Chimbote", 1942 },
    { L"Huancavelica", 1405 },
    { L"Huancayo", 1029 },
    { L"Huanuco", 1459 },
    { L"Huaraz", 1737 },
    { L"Ica", 1895 },
    { L"La oroya", 1375 },
    { L"Lima", 1434 },
    { L"Moquegua", 215 },
    { L"Moyobamba", 1723 },
    { L"Piura", 1846 },
    { L"Pucallpa", 2016 },
    { L"Puerto maldonado", 2465 },
    { L"Puno", 422 },
    { L"Trujillo", 1551 },
    { L"Tumbes", 1605 },
  }},
  { L"Trujillo", {
    { L"Abancay", 894 },
    { L"Arequipa", 629 },
    { L"Ayacucho", 739 },
    { L"Cajamarca", 255 },
    { L"Cerro de pasco", 889 },
    { L"Cusco", 1086 },
    { L"Chachapoyas", 585 },
    { L"Chiclayo", 202 },
    { L"Chimbote", 413 },
    { L"Huancavelica", 1078 },
    { L"Huancayo", 771 },
    { L"Huanuco", 971 },
    { L"Huaraz", 579 },
    { L"Ica", 547 },
    { L"La oroya", 783 },
    { L"Lima", 557 },
    { L"Moquegua", 1177 },
    { L"Moyobamba", 660 },
    { L"Piura", 542 },
    { L"Pucallpa", 877 },
    { L"Puerto maldonado", 1688 },
    { L"Puno", 1260 },
    { L"Tacna", 1551 },
    { L"Tumbes", 771 },
  }},
  { L"Tumbes", {
    { L"Abancay", 1363 },
    { L"Arequipa", 1125 },
    { L"Ayacucho", 1100 },
    { L"Cajamarca", 1088 },
    { L"Cerro de pasco", 1193 },
    { L"Cusco", 1463 },
    { L"Chachapoyas", 631 },
    { L"Chiclayo", 198 },
    { L"Chimbote", 692 },
    { L"Huancavelica", 1776 },
    { L"Huancayo", 1060 },
    { L"Huanuco", 1481 },
    { L"Huaraz", 877 },
    { L"Ica", 848 },
    { L"La oroya", 1556 },
    { L"Lima", 1158 },
    { L"Moquegua", 1410 },
    { L"Moyobamba", 951 },
    { L"Piura", 165 },
    { L"Pucallpa", 1225 },
    { L"Puerto maldonado", 2143 },
    { L"Puno", 1707 },
    { L"Tacna", 1605 },
    { L"Trujillo", 771 },
  }},
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
        rutaCortaStr = rutaCortaStr.substr(0, rutaCortaStr.size() - 4); // Eliminar el último " -> "
        wcout << rutaCortaStr << endl << endl;
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
      MoveWindow(GetDlgItem(hwnd, 5), 10, 110, 600, 20, TRUE);
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