#include <string>
#define DIM 3

typedef struct Tfattura {
  char richiedente[20];
  float importo;
  int numero;
  Tfattura();
  void stampa();
  std::string get_info();
} Tfattura;
typedef struct Tstack {
  Tfattura* is;
  int dim; int n;
  Tstack();
  Tstack( int d );
  Tfattura pop();
  void push( Tfattura t );
  bool isFull();
  bool isEmpty();
  void stampa();
} Tstack;
