#include "dati.h"
#include <iostream>
#include <string>

using namespace std;

TcartaCliente::TcartaCliente() {
  coloreR = coloreG = coloreB = '0';
  saldo = 0.0;
  tipoCarta = TCarta::CREDITO;
}
string TcartaCliente::get_info() {
  string s = (tipoCarta==TCarta::CREDITO ? "credito" : tipoCarta==TCarta::DEBITO ? "debito" : "prepagata");
  s += " saldoEuro= " + to_string(saldo) + " colore(";
  s += coloreR; s += ", ";
  s += coloreG; s += ", ";
  s += coloreB; s += ")";
  return s;

}
void TcartaCliente::stampa() {
  cout << get_info() << endl;
}
TcodaFIFO::TcodaFIFO() {
  dim = DIM;
  n = head = tail = 0;
  s = new TcartaCliente[DIM];
}
TcodaFIFO::TcodaFIFO( int d ) {
  dim = d;
  n = head = tail = 0;
  s = new TcartaCliente[d];
}
void TcodaFIFO::stampa() {
  if(n==0) {
		cout << "vuota" << endl;
		return;
	}
	int i = tail;
	do {
		s[i].stampa();
		i = (i+1)%dim;
	} while(i!=head);
}
bool TcodaFIFO::isFull () {
  return n == dim;
}
void TcodaFIFO::insert( TcartaCliente ca ) {
  s[head] = ca;
	head = (head+1)%dim;
	n++;
}
