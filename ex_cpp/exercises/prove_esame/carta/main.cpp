#include "dati.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

void initCarte ( TcartaCliente * ca ) {
  string chars = "0123456789abcdef";
  ca->coloreR = chars.at(rand()%16);
  ca->coloreG = chars.at(rand()%16);
  ca->coloreB = chars.at(rand()%16);
  cout << "saldo: "; cin >> ca->saldo;
  while (ca->saldo < 100 || ca->saldo > 2000) {
    cout << "ERROR, valid range between 100 and 2000" << endl;
    cout << "saldo: "; cin >> ca->saldo;
  }
  ca->tipoCarta = (TCarta)(rand()%3);
}
void addCarte (  TcodaFIFO *carteBanca, TcartaCliente ca ) {
  if( !carteBanca->isFull() )
    carteBanca->insert( ca );
}
void stampaCarteBanca (  TcodaFIFO * carteBanca ) {
  carteBanca->stampa();
}
float esportaCarte (  TcodaFIFO *carteBanca, TCarta tc ) {
  if( carteBanca->n == 0 ) return 0;
  fstream af ( "carte.txt", fstream::app );
  float somma_saldi = 0;
  int i = carteBanca->tail;
	do {
    if ( carteBanca->s[i].tipoCarta == tc ) {
      af << carteBanca->s[i].get_info() << endl;
      somma_saldi += carteBanca->s[i].saldo;
    }
		i = ( i + 1 ) % carteBanca->dim;
	} while( i != carteBanca->head );
  return somma_saldi;
}

int main() {
  srand(time(0));
  TcodaFIFO* carteBanca = new TcodaFIFO(10);
  TcartaCliente carta;
  for(int i=0; i<5; i++) { initCarte(&carta); addCarte(carteBanca, carta); }
  stampaCarteBanca (carteBanca);
  printf("saldoTot=%f\n", esportaCarte (carteBanca, DEBITO));
  return 0;
}
