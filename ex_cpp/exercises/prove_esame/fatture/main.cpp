#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "dati.h"
using namespace std;

void newFattura( Tfattura * f, int numeroFattura ) {
  f->importo = 1+(rand()%1000);
  f->numero = numeroFattura; // progressivo ed univoco
  cout << "richiedente: "; cin >> f->richiedente;
}
void stampaStack (  Tstack * sf ) {
  for ( int i=0; i<DIM; i++ ) {
    cout << "position " << i << endl;
    sf[i].stampa();
  }
}
void salvaFattura ( Tfattura f ) {
  fstream fs("fattureKO.txt", fstream::app);
  fs << f.get_info() << endl;
  fs.close();
}
int main () {
  srand(time(0));
  //freopen("input.txt", "r", stdin);
  Tstack* sFatt = new Tstack[DIM]; // array di 3 stack ( nello heap )
  for (int i=0; i<DIM; i++) sFatt[i] = Tstack(5);
  for (int i=0; i<10; i++) {
    Tfattura f;
    newFattura(&f, i*100);
    if (f.importo < 10 )        salvaFattura(f);
    else if (f.importo < 100 )  sFatt[0].push(f);
    else if (f.importo > 500 )  sFatt[2].push(f);
    else                        sFatt[1].push(f);
  }
  stampaStack(sFatt);
  delete [] sFatt; // deallocare tutti gli elementi creati nella memoria Heap
  return 0;
}
