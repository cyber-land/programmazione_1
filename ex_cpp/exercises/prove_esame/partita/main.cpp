#include "dati.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

void creaPartita ( Tpartita * pp ) {
  pp->tp = (TipoPartita)(rand()%3);
  pp->punteggioA = 2+ (rand()%5);
  pp->punteggioB = 2+ (rand()%5);
  cout << "nomeA: "; cin >> pp->nomeA;
  cout << "nomeB: "; cin >> pp->nomeB;
}
Ttorneo* insertPartita ( Ttorneo* pt , Tpartita p ) {
  if (pt == NULL) {
    return new Ttorneo (p, NULL);
  }
  Ttorneo * iter = pt;
  while (iter->next != NULL) iter = iter->next;
  Ttorneo * node = new Ttorneo (p, NULL);
  iter->next = node;
  return pt;
}
void stampaTorneo ( Ttorneo* pt ) {
  pt->stampa();
}
Ttorneo* salvaTorneo ( Ttorneo* pt ) {
  fstream af ( "partite.txt" , fstream::app );
  if ( !af.is_open() ) exit(-1);
  Ttorneo * iter = pt;
  while (iter != NULL) {
    if ( iter->partita.punteggioB == 6 || iter->partita.punteggioA == 6 ) {
      af << iter->partita.info() << endl;
    }
    //Ttorneo * temp = iter;
    cout<< iter->partita.info() << endl;
    iter = iter->next;
    //delete temp;
  }
  af.close();
  return pt;
}

int main() {
  srand(time(0));
  freopen("input.txt", "r", stdin);
  Ttorneo* lstt = NULL;
  Tpartita pa;
  for(int i=0; i<5; i++) { creaPartita(&pa); lstt=insertPartita(lstt, pa);}
  cout << endl;
  stampaTorneo(lstt);
  lstt = salvaTorneo (lstt);
  return 0;
}
