#include "dati.h"
#include <iostream>
#include <fstream>
using namespace std;

Tmailbox* push(Tmailbox * stack, Tmessaggio m) {
  Tmailbox * f = new Tmailbox( m , stack );
  return f;
}

void newMsg ( Tmessaggio * m, int id ) {
  m->id = id;
  m->tipo = (Tmail)(rand()%2);
  m->data.aa = 2022;
  m->data.mm = 1+ (rand()%12);
  m->data.gg = 1+ (rand()%31);
  cout << "msg: "; cin >> m->messaggio;
}
void addMsg ( Tmailbox* mb[], Tmessaggio m ) {
  if (m.tipo == Tmail::PEC) {
    mb[0] = push( mb[0], m );
  } else {
    mb[1] = push( mb[1], m );
  }
}
void stampaMailbox ( Tmailbox* mba[] , int dim ) {
  for (int i=0; i<dim; i++) {
    Tmailbox * iter = mba[i];
    cout << "mailbox " << i << endl;
    while (iter != NULL ) {
      iter->msg.stampa();
      iter = iter->next;
    }
  }
}
void saveMailbox ( Tmailbox* mba[], int dim ) {
  fstream af ("OLDMail.txt", fstream::app);
  for (int i=0; i<dim; i++) {
    Tmailbox * iter = mba[i];
    while (iter != NULL ) {
      if ( iter->msg.data.aa < 2022 || iter->msg.data.mm < 6 ) {
        af << "IDMAIL=" << iter->msg.id << " msg=" << iter->msg.messaggio << endl;
      }
      iter = iter->next;
    }
  }
  af.close();
}

int main() {
  srand(time(0));
  freopen("input.txt", "r", stdin);
  Tmailbox* box[2]; // array of two stacks
  for (int i=0; i<2; i++) box[i] = NULL;
  for (int i=0; i<10; i++) {
    Tmessaggio m;
    newMsg( &m , i*100 );
    addMsg( box, m );
  }
  stampaMailbox(box,2);
  saveMailbox(box, 2);
  return 0;
}
