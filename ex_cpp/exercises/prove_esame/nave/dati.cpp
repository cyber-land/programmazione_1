#include "dati.h"
#include <iostream>
#include <string>
using namespace std;

Tnave::Tnave() {
  nomeNave[0] = '\n';
  annoVaro = 0;
  stazza = 0.0;
  tipoBattello = Tbattello::ALISCAFO;
}
string Tnave::get_info() {
  string s = nomeNave;
  s += " (";
  s += (tipoBattello == Tbattello::ALISCAFO ? "aliscafo" :
    tipoBattello == Tbattello::CROCIERA ? "crociera" : "traghetto");
  s += ") " + to_string(stazza) +" anno varo=" + to_string(annoVaro);
  return s;
}
void Tnave::stampa() {
  cout << get_info() << endl;
}

Tnodo::Tnodo() {
  next = prev = NULL;
  nave = Tnave();
}
Tnodo::Tnodo(Tnodo *n, Tnodo *p, Tnave _nave) {
  next = n; prev = p; nave = _nave;
}
void Tnodo::stampa() {
  Tnodo * iter = this;
  while (iter != NULL ) {
    iter->nave.stampa();
    iter = iter->next;
  }
}
