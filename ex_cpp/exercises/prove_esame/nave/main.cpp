#include "dati.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
void newNave( Tnave * nave ) {
  nave->tipoBattello = (Tbattello)(rand()%3);
  cout << "anno: "; cin >> nave->annoVaro;
  while ( nave->annoVaro < 1995 || nave->annoVaro > 2022 ) {
    cout << "ERROR: range available 1995-2022" << endl;
    cout << "anno: "; cin >> nave->annoVaro;
  }
  nave->stazza = 15000 + rand()%35000; // random 15000.00 - 50000.00
  cout << "nome: "; cin >> nave->nomeNave;
}
void addNave ( Tnodo * por[] , int dim , Tnave nave ) {
  int index = rand()%dim;
  Tnodo * iter = por[index];
  if (iter == NULL) {
    por[index] = new Tnodo (NULL, NULL, nave);
    return;
  }
  while (iter->next != NULL) iter = iter->next;
  Tnodo * node = new Tnodo (NULL, iter, nave);
  iter->next = node;

}
void stampaPorti ( Tnodo* por[], int dim ) {
  for (int i=0; i<dim; i++) {
    cout << "porto " << i << endl;
    por[i]->stampa();
  }
}
int rimuoviEContaNavi ( Tnodo * por[], int dim ) {
  fstream af("navi.txt" , fstream::app );
  int global_size = 0;
  for (int i=0; i<dim; i++) {
    Tnodo * iter = por[i];
    int size = 0;
    while (iter != NULL) {
      size++;
      Tnodo * p = iter->prev;
      iter = iter->next;
      delete p;
    }
    af << "CODA FIFO POS= " << i << "NUMNAVI= " << size << endl;
    global_size += size;
  }
  af.close();
  return global_size;
}

int main() {
  srand(time(0));
  freopen("input.txt", "r", stdin);
  Tnodo* porti[DIM]; // array of nodes
  Tnave nave;
  for (int i=0; i<DIM; i++) porti[i] = NULL; /* inizializzare la variabile porti in modo opportuno*/
  for (int i=0; i<5; i++) {
    newNave(&nave);
    addNave(porti, DIM, nave);
  } cout << endl;
  stampaPorti(porti, DIM);
  cout << "navi " << rimuoviEContaNavi (porti, DIM) << endl;
  return 0;
}
