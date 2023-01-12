#include "dati.h"
#include <iostream>
using namespace std;

Tproduzione::Tproduzione() {
  piantagione[0] = '\n';
  numeroPiante = 0;
  quantita = 0.0;
  tipoFrutto = Tfrutto::MELA;
}
void Tproduzione::stampa() {
  cout << piantagione << " (" <<
  ( tipoFrutto == Tfrutto::MELA ? "mela" : tipoFrutto == Tfrutto::PERA ? "pera " : "pesca" )
   << ") " << quantita << " " << numeroPiante << endl;
}
TipoCodaFIFO::TipoCodaFIFO() {
  int n = head = tail = 0;
  int dim = DIM;
  s = new Tproduzione[DIM];
}
TipoCodaFIFO::TipoCodaFIFO( int d ) {
  n = head = tail = 0;
  dim = d;
  s = new Tproduzione[d];
}
bool TipoCodaFIFO::codaIsEmpty() {
  return n == 0;
}
bool TipoCodaFIFO::codaIsFull() {
  return n == dim;
}
void TipoCodaFIFO::stampa() {
  if (n == 0) return;
  if (  head > tail ) {
    for (int i=tail; i<head; i++) s[i].stampa();
  } else {
    for (int i=tail; i<dim; i++)  s[i].stampa();
    for (int i=0; i<head; i++)    s[i].stampa();
  }
}
