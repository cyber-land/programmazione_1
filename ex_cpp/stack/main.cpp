#include <iostream>
#include <cassert>
#include <string>
#include "stack.h"
using namespace std;

int main() {
  Data data = Data("a", "b", 10), d2 = Data( "b", "c", 5), d3 = Data("c", "d", 6);
  Node* n1 = new Node(data, NULL);
  n1 = push(n1, d2);
  n1 = push(n1, d3);
  cout << n1->print() << endl;
  assert( equals(n1->data, d3) );
  Data d = pop(*n1);
  assert( equals(n1->data, d2) );
  cout << "d: " << d.print() << endl;
  cout << n1->print() << endl;
  cout << "---" << endl;
  Node* n = n1;
  d = pop(*n);
  assert( equals( n->data, data ) );
  cout << d.print() << endl;
  cout << "---" << endl;
  d = pop(*n);
  //assert( n == NULL );
  //cout << d.print() << endl;

  return 0;
}

