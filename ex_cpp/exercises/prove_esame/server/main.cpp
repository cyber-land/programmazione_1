#include "dati.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

void creaServer ( Tserver * s ) {
  s->so = (Tsistoper)(rand()%3);
  s->numCPU = 4+(rand()%5);
  cout << "ram: "; cin >> s->ram;
  while ( s->ram < 4 || s->ram > 16 || s->ram % 2 != 0 ) {
    cout << "valore compreso tra 4 ed 8 e pari"<< endl;
    cout << "ram: "; cin >> s->ram;
  }
  cout << "hostname: "; cin >> s->hostname;
}
Tcloud* inserisciServer ( Tcloud* pc, Tserver s ) {
  if ( pc == NULL ) return new Tcloud ( s, NULL );
  Tcloud * iter = pc;
  int counter = 0;
  while ( iter->next != NULL ) {
    counter ++;
    iter = iter->next;
  }
  cout << "counter: " << counter << endl;
  Tcloud * node = new Tcloud ( s, NULL );
  iter->next = node;
  return pc;
}
void stampaServer ( Tcloud* pc ) {
  pc->stampa();
}
void salvaServer ( Tcloud* pc ) {
  fstream af ( "server.txt" , fstream::app );
  if ( !af.is_open() ) exit (-1);
  Tcloud * iter = pc;
  while ( iter != NULL ) {
    if ( iter->server.ram > 8 && iter->server.numCPU == 6 ) {
      af << iter->server.get_info() << endl;
    }
    iter = iter->next;
  }
  af.close();
}
Tserver serverEquivalente ( Tcloud * pc, Tsistoper sis ) {
  Tserver r;
  r.so = sis;
  int ram = 0, cpu = 0;
  Tcloud * iter = pc;
  while ( iter != NULL ) {
    ram += ( iter->server.so == sis ? iter->server.ram : 0 );
    cpu += ( iter->server.so == sis ? iter->server.numCPU : 0 );
    iter = iter->next;
  }
  r.ram = ram;
  r.numCPU = cpu;
  return r;
}
int main() {
  srand(time(0));
  freopen("input.txt", "r", stdin);
  Tcloud* lst = NULL;
  Tserver s;
  for(int i=0; i<10; i++) { creaServer(&s); lst=inserisciServer(lst, s); }
  cout << endl;
  stampaServer(lst);
  salvaServer(lst);
  serverEquivalente(lst, MAC).stampa();
  return 0;
}
