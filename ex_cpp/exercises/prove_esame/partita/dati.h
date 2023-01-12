#include <string>
typedef enum TipoPartita{ SINGOLO, DOPPIO, MISTO } TipoPartita;

typedef struct Tpartita {
  char nomeA[20], nomeB[20];
  int punteggioA, punteggioB;
  TipoPartita tp;
  Tpartita ();
  void stampa(); // e
  std::string info();
} Tpartita;

typedef struct Ttorneo{
  Tpartita partita;
  Ttorneo *next;
  Ttorneo ();
  Ttorneo (Tpartita p, Ttorneo* n);
  void stampa();
} Ttorneo;
