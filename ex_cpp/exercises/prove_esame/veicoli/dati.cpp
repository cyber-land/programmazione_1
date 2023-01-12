#include <iostream>
#include <string>
#include "dati.h"
using namespace std;

Trevisione::Trevisione() {
  proprietario[0] = '\n';
  annoImm = 0;
  valutazione = 0;
  tipoVeicolo = TVeicolo::MOTO;
}
void Trevisione::setValutazione(float v) {
  valutazione = v;
}
string Trevisione::get_info () {
  string s = proprietario ;
  s += " (";
  s += ( tipoVeicolo == TVeicolo::MOTO ? "moto" : tipoVeicolo == TVeicolo::AUTO ? "auto" : "bus" );
  s += ") anno=" + to_string(annoImm) + " val=" + to_string(valutazione);
  return s;
}
void Trevisione::stampa() {
  cout << get_info() << endl;
}
Tnodo::Tnodo( Trevisione _revisione ) {
  revisione = _revisione;
  next = NULL;
}
void Tnodo::stampa() {
  Tnodo* iter = this;
  int counter = 0;
  while ( iter != NULL ) {
    cout << "nodo " << counter << endl;
    iter->revisione.stampa();
    iter = iter->next;
    counter++;
  }
}
