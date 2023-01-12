#include "dati.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cassert>
using namespace std;


Node* push( Node * n, Data d ) {
  return new Node (d, n);
}
Data pop( Node * n ) {
  assert(n!=NULL);
  Data d = n->data;
  Node * temp = n;
  n = n->next;
  delete temp;
  return d;
}


void new_data( Data * d ) {
  d->value = rand() % 1000;
  d->f = rand() % 1000;
}

void add ( Node * arr[] , int size, Data d ) {
  for (int i=0; i<size; i++) {
    arr[i] = push ( arr[i], d );
  }
}

void print ( Node * arr[] , int size ) {
  for (int i=0; i<size; i++) {
    cout << "node " << i << endl;
    arr[i]->print();
  }
}

void save ( Node * arr[], int size ) {
  fstream fa ( "file.txt" , fstream::app );
  for (int i=0; i<size; i++) {
    Node * iter = arr[i];
    fa << "list number " << i << endl;
    while (iter != NULL ) {
      fa << "\t" << iter->data.info() << endl;
      iter = iter->next;
    }
  }
  fa.close();
}

int main() {
  srand(time(0));
  Node * arr[5];
  for (int i=0; i<5; i++) arr[i] = NULL;
  for (int i=0; i<6; i++) {
    Data d;
    new_data( &d );
    add ( arr, 5, d );
  }
  print ( arr , 5 );
  save  ( arr , 5 );
  return 0;
}
