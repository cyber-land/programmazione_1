
#include <string>
#define DIM 2

typedef enum Tbattello { ALISCAFO, CROCIERA, TRAGHETTO } Tbattello;

typedef struct Tnave {
  char nomeNave[20];
  unsigned int annoVaro;
  float stazza;
  Tbattello tipoBattello;
  Tnave ();
  void stampa(); // E
  std::string get_info();
} Tnave;

typedef struct Tnodo {
  Tnave nave;
  Tnodo *next, *prev;
  Tnodo (Tnodo *n, Tnodo *p, Tnave _nave);
  Tnodo ();
  void stampa();
} Tnodo;
