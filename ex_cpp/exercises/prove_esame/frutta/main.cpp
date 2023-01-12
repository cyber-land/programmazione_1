#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "dati.h"
using namespace std;

void newProduzione ( Tproduzione * p ) {
  cout << "piantagione: ";    cin >> p->piantagione;
  cout << "numero_piante: ";  cin >> p->numeroPiante;
  p->quantita = 10; // random [100.00 , 2000.00]
  p->tipoFrutto = (Tfrutto) (rand() % 3); // random
}
void addProduzione ( TipoCodaFIFO* produzioni[], int dim, Tproduzione p ) {
  int pos = rand() % dim;
  if ( produzioni[pos]->codaIsFull() ) {
      fstream af ( "noProd.txt", fstream::app );
      for (int i=0; i< produzioni[pos]->n; i++) {
        af << produzioni[pos]->s[i].get_info() << endl;
      }
      af.close();
  } else {
    // inserimento in una FIFO casuale
    produzioni[pos]->s[ produzioni[pos]->n ] = p;
    produzioni[pos]->n++;
  }
}
void stampaProduzioni (  TipoCodaFIFO* produzioni[], int dim ) {
  for (int i=0; i<dim; i++) {
    cout << "piantagione numero : " << i << endl;
    produzioni[i]->stampa();
  }
}
int estraiProduzioni (  TipoCodaFIFO* produzioni[], int dim, Tfrutto tf ) {
  int occurs = 0;
  for (int i=0; i<dim; i++) {
    for (int j=0; j<produzioni[i]->n; j++) {
      if (produzioni[i]->s[j].tipoFrutto == tf) occurs++;
    }
    delete [] produzioni[i]->s;
    produzioni[i]->n = 0;
  }
  return occurs;
}

int main() {
  srand(time(0));
  TipoCodaFIFO* pf[DIM]; // array di FIFO nello stack
  Tproduzione p;
  /*da implementare init array code FIFO pf dimensione 3 elementi*/
  for (int i=0; i<DIM; i++) pf[i] = new TipoCodaFIFO(DIM);

  for(int i=0; i<6; i++) {
    newProduzione(&p);
    addProduzione(pf, DIM, p);
  }
  stampaProduzioni(pf, DIM);
  cout << estraiProduzioni(pf, DIM, MELA) << endl;
  return 0;
}
