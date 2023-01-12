#include "dati.h"
#include <iostream>
#include <string>
using namespace std;

Tserver::Tserver() {
  hostname[0] = '\n';
  numCPU = ram = 0;
  so = Tsistoper::LINUX;
}
string Tserver::get_info() {
  string s = hostname;
  s += " (";
  s += ( so == Tsistoper::WIN ? "win" : so == Tsistoper::MAC ? "mac" : "linux" );
  s += ") RAM=" + to_string(ram) + " CPU=" + to_string(numCPU);
  return s;
}
void Tserver::stampa() {
  cout << get_info() << endl;
}
Tcloud::Tcloud() {
  next = NULL;
}
Tcloud::Tcloud( Tserver s, Tcloud* n ) {
  server = s; next = n;
}
void Tcloud::stampa() {
  Tcloud * iter = this;
  while (iter != NULL) {
    iter->server.stampa();
    iter = iter->next;
  }
}
