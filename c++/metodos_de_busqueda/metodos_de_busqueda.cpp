#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;
// Función de búsqueda binaria recursiva con visualización
int binarySearch(vector<int>& arr, int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    // Visualización del proceso
    cout << "left = " << left << ", right = " << right << ", mid = " << mid << endl;
    this_thread::sleep_for(chrono::milliseconds(1000)); // Espera de 1 segundo para visualización
    if (arr[mid] == target) {
      return mid; // Elemento encontrado en la posición 'mid'
    }
    else if (arr[mid] < target) {
      left = mid + 1; // Buscar en la mitad derecha
    }
    else {
      right = mid - 1; // Buscar en la mitad izquierda
    }
  }
  return -1; // Elemento no encontrado
}
// Función de búsqueda ternaria recursiva con visualización
int ternarySearch(vector<int>& arr, int left, int right, int target) {
  while (left <= right) {
    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;
    // Visualización del proceso
    cout << "left = " << left << ", right = " << right << ", mid1 = " << mid1 << ", mid2 = " << mid2 << endl;
    this_thread::sleep_for(chrono::milliseconds(1000)); // Espera de 1 segundo para visualización
    if (arr[mid1] == target) {
      return mid1; // Elemento encontrado en la posición 'mid1'
    }
    else if (arr[mid2] == target) {
      return mid2; // Elemento encontrado en la posición 'mid2'
    }
    else if (arr[mid1] > target) {
      right = mid1 - 1; // Buscar en la primera parte
    }
    else if (arr[mid2] < target) {
      left = mid2 + 1; // Buscar en la tercera parte
    }
    else {
      left = mid1 + 1;
      right = mid2 - 1; // Buscar en la segunda parte
    }
  }
  return -1; // Elemento no encontrado
}
// Función de búsqueda exponencial
int exponentialSearch(vector<int>& arr, int target) {
  int bound = 1;
  while (bound < arr.size() && arr[bound] < target) {
    bound *= 2; // Aumentar el límite exponencialmente
  }
  // Definir límites para la búsqueda binaria
  int left = bound / 2;
  int right = min(bound, static_cast<int>(arr.size() - 1));
  // Realizar búsqueda binaria en el rango encontrado
  while (left <= right) {
    int mid = left + (right - left) / 2;
    // Visualización del proceso
    cout << "left = " << left << ", right = " << right << ", mid = " << mid << endl;
    if (arr[mid] == target) {
      return mid; // Elemento encontrado en la posición 'mid'
    }
    else if (arr[mid] < target) {
      left = mid + 1; // Buscar en la mitad derecha
    }
    else {
      right = mid - 1; // Buscar en la mitad izquierda
    }
  }
  return -1; // Elemento no encontrado
}
int main() {
  vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};
  int target = 5;
  // Realizar búsqueda binaria con visualización
  cout << "Realizando búsqueda binaria del elemento " << target << " en el array:" << endl;
  int index = binarySearch(arr, 0, arr.size() - 1, target);
  // int index = ternarySearch(arr, 0, arr.size() - 1, target);
  // int index = exponentialSearch(arr, target);
  // Mostrar resultado
  if (index != -1) {
    cout << "Elemento " << target << " encontrado en el índice " << index << endl;
  }
  else {
    cout << "Elemento " << target << " no encontrado en el array." << endl;
  }
  return 0;
}