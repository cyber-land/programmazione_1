#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "dati.h"
using namespace std;

int random_int(int min, int max) {
  if ( min >  max ) return random_int(max, min);
  if ( min == max ) return min;
  return min + (rand() % (max - min));
}
float random_float() {
  float f = (float)random_int(1,10);
  f += (float)(rand()) / (float)(RAND_MAX);
  return f;
}

void newRevisione ( Trevisione * rev ) {
  assert (rev != NULL);
  rev->tipoVeicolo = (TVeicolo)random_int(0,3);
  cout << "anno immatricolazione: "; cin >> rev->annoImm;
  rev->valutazione = 0.0;
  cout << "proprietario: "; cin >> rev->proprietario;
}
void stampaRevisioni ( Tnodo * cpr ) {
  cout << "revisioni : " << endl;
  cpr->stampa();
}
Tnodo* addRevisione ( Tnodo * cpr, Trevisione r ) {
  Tnodo * new_node = new Tnodo(r);
  new_node->next = cpr;
  return new_node;
}
Trevisione readRevisione ( Tnodo * cpr ) {
  Trevisione readFirst = cpr->revisione;
  return readFirst;
}
Tnodo* remRevisione ( Tnodo * cpr ) {
  if (cpr == NULL) return cpr;
  Tnodo* next = cpr->next;
  delete cpr;
  return next;
}
void saveRevisione ( Trevisione r ) {
  fstream of("revisioniOK.txt", fstream::app);
  of << r.get_info() << endl;
}
int main() {
  srand(time(0));
  Tnodo* cpr = NULL; //Centro Provinciale Revisioni
  Trevisione revisione;
  for (int i=0; i<5; i++) {
    newRevisione(&revisione);
    cpr = addRevisione(cpr, revisione);
  }
  while (cpr!=NULL) {
    revisione = readRevisione(cpr);
    cpr = remRevisione(cpr);
    revisione.setValutazione(random_float());

    if (revisione.valutazione < 5) {
      cpr = addRevisione(cpr, revisione); // re-inserire la revisione in cpr
    } else {
      saveRevisione(revisione); // inserire la revisione in file
    }
    stampaRevisioni(cpr);
  }
  return 0;
}
