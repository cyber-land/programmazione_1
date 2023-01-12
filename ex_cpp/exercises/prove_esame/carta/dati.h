#include <string>
#define DIM 2
typedef enum TCarta { CREDITO, DEBITO, PREPAGATA } TCarta;
typedef struct TcartaCliente {
  char coloreR, coloreG, coloreB;
  float saldo;
  TCarta tipoCarta;
  TcartaCliente ();
  void stampa();
  std::string get_info();
} TcartaCliente;
typedef struct TcodaFIFO {
  int n, dim, head, tail;
  TcartaCliente *s;
  TcodaFIFO ();
  TcodaFIFO (int x);
  void stampa();
  bool isFull();
  void insert( TcartaCliente c );
} TcodaFIFO;
