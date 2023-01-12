#include <string>

typedef enum Tsistoper { WIN, MAC, LINUX } Tsistoper;
typedef struct Tserver {
  char hostname[20];
  int numCPU, ram;
  Tsistoper so;
  Tserver ();
  void stampa();
  std::string get_info();
}Tserver;
typedef struct Tcloud {
  Tserver server;
  Tcloud *next;
  Tcloud ();
  Tcloud (Tserver s, Tcloud* n);
  void stampa();
} Tcloud;
