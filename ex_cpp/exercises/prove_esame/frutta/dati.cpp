#include <iostream>
#include <string>
#include "dati.h"
using namespace std;
string Tproduzione::get_info() {
  string s = piantagione;
  s += " (";
  s+= ( tipoFrutto == Tfrutto::MELA ? "mela" : tipoFrutto == Tfrutto::PESCA ? "pesca" : "pera" );
  s+= ") "; s+= to_string(quantita); s+= " "; s+= to_string(numeroPiante);
  return s;
}
void Tproduzione::stampa() {
  cout << get_info() << endl;
}
void TipoCodaFIFO::stampa() {
  for (int i=0; i<n; i++) {
    cout << "pos: " << i << endl;
    s[i].stampa();
  }
}
bool TipoCodaFIFO::codaIsEmpty() {
  return n == 0;
}
bool TipoCodaFIFO::codaIsFull() {
  return n == dim;
}
