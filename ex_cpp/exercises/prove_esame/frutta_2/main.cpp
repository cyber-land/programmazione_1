#include "dati.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
void newProduzione ( Tproduzione * p ) {
  cout << "piantagione: "; cin >> p->piantagione;
  cout << "numero piante: "; cin >> p->numeroPiante;
  while ( p->numeroPiante < 1000 || p->numeroPiante > 10000 ) {
    cout << "Error: valid range 1000-9999 " << endl;
    cout << "numero piante: "; cin >> p->numeroPiante;
  }
  p->quantita = 100 + (rand()%1900);
  p->tipoFrutto = (Tfrutto)(rand()%3);
}
void addProduzione ( TipoCodaFIFO* produzioni[] , int dim , Tproduzione p ) {
  int index = rand()%dim;
  if ( produzioni[index]->codaIsFull() ) {
    fstream af ("noProd.txt", fstream::app );
    af << p.piantagione << " (" <<
      ( p.tipoFrutto == Tfrutto::MELA ? "mela" : p.tipoFrutto == Tfrutto::PERA ? "pera " : "pesca" )
      << ") " << p.quantita << " " << p.numeroPiante << endl;
    af.close();
  } else {
    produzioni[index]->s[produzioni[index]->head] = p;
    if (produzioni[index]->head == dim-1) produzioni[index]->head = 0;
    else produzioni[index]->head++;
    produzioni[index]->n++;
  }
}
void stampaProduzioni ( TipoCodaFIFO* produzioni[] , int dim ) {
  for (int i=0; i<dim; i++) {
    cout << "produzione " << i << endl;
    produzioni[i]->stampa();
  }
}
int estraiProduzioni ( TipoCodaFIFO* produzioni[] , int dim, Tfrutto tf ) {
  int counter = 0;
  for (int i=0; i<dim; i++) {
    if ( produzioni[i]->tail >= produzioni[i]->head ) {
      for (int j=produzioni[i]->head; j<produzioni[i]->tail; j++)
        if ( produzioni[i]->s[j].tipoFrutto == tf ) counter++;
    } else {
      for (int j=produzioni[i]->head; j<dim; j++) if ( produzioni[i]->s[j].tipoFrutto == tf ) counter++;
      for (int j=0; i<produzioni[j]->tail; j++)   if ( produzioni[i]->s[j].tipoFrutto == tf ) counter++;
    }
  }
  for (int i=0; i<dim; i++) {
    produzioni[i]->n = 0;
    produzioni[i]->head = 0;
    produzioni[i]->tail = 0;
  }
  return counter;
}
int main() {
  srand(time(0));
  freopen("input.txt", "r", stdin);
  TipoCodaFIFO* pf[DIM];
  Tproduzione p;
  for (int i=0; i<DIM; i++) pf[i] = new TipoCodaFIFO(3);
  for(int i=0; i<6; i++) {
    newProduzione(&p);
    addProduzione(pf, DIM, p);
  }
  stampaProduzioni(pf, DIM);
  cout << estraiProduzioni(pf, DIM, MELA);
  return 0;
}
