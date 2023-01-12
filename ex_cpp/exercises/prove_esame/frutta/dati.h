#include <string>
#include <cstring>
#define DIM 3
typedef enum Tfrutto { MELA, PESCA, PERA } Tfrutto;
typedef struct Tproduzione {
  char piantagione[20];
  unsigned int numeroPiante;
  float quantita;
  Tfrutto tipoFrutto;
  Tproduzione () {
    piantagione[0] = '\n';
    numeroPiante = 0;
    quantita = 0;
    tipoFrutto = Tfrutto::MELA;
  }
  Tproduzione ( char * p, int np, float q, Tfrutto tf ) {
    strcpy(piantagione, p);
    numeroPiante = np;
    quantita = q;
    tipoFrutto = tf;
   }
   std::string get_info();
   void stampa();
} Tproduzione;
typedef struct TipoCodaFIFO {
  int head;       // inserimento
  int tail;       // prelevamento
  int dim;        // numero massimo elementi
  int n;          // numero elementi presenti
  Tproduzione* s; // array dinamico circolare
  TipoCodaFIFO( int d ) {
    head = 0;
    tail = 0;
    dim = d;
    n = 0;
    s = new Tproduzione[d];
  }
  TipoCodaFIFO() {
    dim = 3;
    head = tail = n = 0;
    s = new Tproduzione[3];
  }
  //~TipoCodaFIFO() { }
  void stampa();
  bool codaIsEmpty();
  bool codaIsFull();
} TipoCodaFIFO;
// costruttore specifico, costruttore a zero parametri e distruttore
// metodi: stampa, codaIsEmpty, codaIsFull, get, put
