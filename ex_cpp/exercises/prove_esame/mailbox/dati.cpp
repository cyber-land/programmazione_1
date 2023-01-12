#include "dati.h"
#include <iostream>
#include <string>

using namespace std;

Tmessaggio::Tmessaggio() {
  id = 0;
  tipo = Tmail::PEC;
  data = Tdata { 1, 30, 2000 };
  messaggio[0] = '\n';
}
void Tmessaggio::stampa() {
  cout << "IDMAIL=" << id << " tipo=" << ( tipo == Tmail::PEC ? "PEC" : "STD")
   << " data="<<data.gg<<"/"<<data.mm<<"/"<<data.aa<<endl;
}
Tmailbox::Tmailbox() {
  msg = Tmessaggio();
  next = NULL;
}
void Tmailbox::stampa() {
  Tmailbox * iter = this;
  while (iter != NULL ) {
    iter->msg.stampa();
    iter = iter->next;
  }
}
