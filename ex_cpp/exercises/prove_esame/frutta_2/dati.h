
#define DIM 3
typedef enum Tfrutto { MELA, PESCA, PERA } Tfrutto;

typedef struct Tproduzione {
  char piantagione[20];
  unsigned int numeroPiante;
  float quantita;
  Tfrutto tipoFrutto;
  Tproduzione ();
  void stampa();
} Tproduzione;
typedef struct TipoCodaFIFO {
  int head, tail; //posizione inserimento, posizione prelevamento
  int dim;        //numero elementi array==coda
  int n;          //numero elementi presenti nella coda
  Tproduzione* s; // array dinamico circolare
  TipoCodaFIFO();
  TipoCodaFIFO( int d );
  bool codaIsEmpty();
  bool codaIsFull();
  //get, put
  void stampa();
} TipoCodaFIFO;
