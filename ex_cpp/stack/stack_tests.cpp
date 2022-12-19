#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include "stack.h"
using namespace std;

int main() {
  // Data
  Data data = Data("a", "b", 10), data2 = Data( "b", "c", 5), data3 = Data("c", "d", 6);
  Data d4 = Data("a", "b", 10);
  assert(equals (Data(), Data()));
  assert(equals (data2, data2));
  assert(!equals (data2, data3));
  assert(equals (data, d4));
  assert(data.print() == "name: a surname: b age: 10");

  // Node
  Node *n1 = new Node(data, NULL), *n2 = new Node(data2, n1);
  assert (equals (n1->data, data));
  assert ( n1->next == NULL );
  assert ( n2->next == n1 );
  // push
  cout << n2->print() << endl;
  n2 = push(n2, data);
  cout << n2->print() << endl;

  Node* n3 = push(n2, data);
  assert ( equals(n3->data, data) );
  assert ( equals(n3->next->data, data) );
  assert ( equals(n3->next->next->data, data2) );
	assert ( equals(n3->next->next->next->data, data) );
	assert ( n3->next->next->next->next == NULL );
  //TODO: riutilizzo dei nodi stile grafo!?

  // print
  cout << n3->print() << endl;

	// pop
	n3 = pop(n3);
	cout << n3->print() << endl;
	Data d5 = read(n3);
	d5.name = "michele";
	cout << "d5: " << d5.print() << endl;
	//n3 = pop(n3);
	cout << n3->print() << endl;

  return 0;
}

