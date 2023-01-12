#include <iostream>
#include <string>
#include <cassert>
#include "dati.h"
using namespace std;

Tfattura::Tfattura() {
  richiedente[0] = '\n';
  importo = 0.0;
  numero = 0;
}
string Tfattura::get_info() {
  string s = "numFattura="+to_string(numero)+" ";
  s+= richiedente;
  s+= " importo="+to_string(importo);
  return s;
}
void Tfattura::stampa() {
  cout << get_info() << endl;
}
Tstack::Tstack() {
  dim = DIM; n = 0; is = new Tfattura[DIM];
}
Tstack::Tstack( int d ) {
  dim = d; n = 0; is = new Tfattura[d];
}
bool Tstack::isFull()  { return n == dim; }
bool Tstack::isEmpty() { return n == 0;   }
Tfattura Tstack::pop() {
  assert ( !isEmpty() );
  return is[--n];
}
void Tstack::push( Tfattura f ) {
  if ( isFull() ) return;
  is[n++] = f;
}
void Tstack::stampa() {
  for (int i=0; i<n; i++) {
    is[i].stampa();
  }
}
