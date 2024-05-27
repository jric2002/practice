#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>
#include <csignal>
#include <atomic>
using namespace std;
const int num_filosofos = 5;
mutex mtx;
vector<mutex> tenedores(num_filosofos);
vector<condition_variable> cv(num_filosofos);
vector<atomic<int>> contadores_comidas(num_filosofos);
// Función para manejar la señal de interrupción (Ctrl + C)
void signal_handler(int signum) {
  cout << "\nNúmero total de comidas por filósofo:" << endl;
  for (int i = 0; i < num_filosofos; i++) {
    cout << "Filósofo " << i << ": " << contadores_comidas[i] << endl;
  }
  exit(signum);
}
// Generar un aleatorio entre un número mínimo y máximo
int generarNumeroAleatorio(int min, int max) {
  return (rand() % (max - min + 1) + min);
}
void filosofo(int id) {
  int izquierda = id;
  int derecha = (id + 1) % num_filosofos;
  while (true) {
    // Pensar (duración aleatoria)
    int tiempo_pensar = generarNumeroAleatorio(1000, 1500);
    this_thread::sleep_for(chrono::milliseconds(tiempo_pensar));
    // Intentar tomar tenedores
    unique_lock<mutex> lck_izq(tenedores[izquierda]);
    unique_lock<mutex> lck_der(tenedores[derecha]);
    // Comer (duración aleatoria)
    cout << "[+] Filósofo " << id << " está comiendo." << endl;
    int tiempo_comer = generarNumeroAleatorio(1500, 2000);
    this_thread::sleep_for(chrono::milliseconds(tiempo_comer));
    // Incrementar el contador de comidas para este filósofo
    contadores_comidas[id]++;
    // Soltar tenedores
    cout << "[-] Filósofo " << id << " ha terminado de comer." << endl;
    // Notificar a los filósofos vecinos que los tenedores están disponibles
    cv[izquierda].notify_one();
    cv[derecha].notify_one();
  }
}
int main(int argc, char *argv[]) {
  // Registrar el manejador de señales para Ctrl + C
  signal(SIGINT, signal_handler);
  thread filosofos[num_filosofos];
  srand(time(NULL));
  // Crear hilos para los filósofos
  for (int i = 0; i < num_filosofos; i++) {
    filosofos[i] = thread(filosofo, i);
  }
  // Unirse a los hilos
  for (int i = 0; i < num_filosofos; i++) {
    filosofos[i].join();
  }
  return 0;
}