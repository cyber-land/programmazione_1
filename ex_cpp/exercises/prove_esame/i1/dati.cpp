#include "dati.h"
#include <iostream>
#include <cassert>
using namespace std;

void Data::print() {
  cout << f << " " << value << endl;
}
string Data::info() {
  return to_string(f) + " " + to_string(value);
}

void Node::print() {
  Node * iter = this;
  while (iter != NULL) {
    iter->data.print();
    iter = iter->next;
  }
}
