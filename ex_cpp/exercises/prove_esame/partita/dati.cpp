#include "dati.h"
#include <iostream>
#include <string>
using namespace std;

Tpartita::Tpartita () {
  nomeA[0] = '\n'; nomeB[0] = '\n';
  punteggioA = 0; punteggioB = 0;
  tp = TipoPartita::SINGOLO;
}
string Tpartita::info() {
  string s = nomeA;
  s += " "; s+= nomeB;
  s += " (";
  s += ( tp == TipoPartita::SINGOLO ? "singolo" : TipoPartita::DOPPIO ? "doppio" : "misto" );
  string b = ") PUNTEGGIO ( " + to_string(punteggioA) + ", " + to_string(punteggioB) + ")";
  return s+b;
}
void Tpartita::stampa () {
  cout << info() << endl;
}
Ttorneo::Ttorneo () {
  partita = Tpartita ();
  next = NULL;
}
Ttorneo::Ttorneo (Tpartita p, Ttorneo* n) {
  partita = p; next = n;
}
void Ttorneo::stampa () {
  Ttorneo * iter = this;
  while (iter != NULL) {
    iter->partita.stampa();
    iter = iter->next;
  }
}
