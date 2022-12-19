#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include "queue.h"
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
  Node<Data> *n1, *n2;
  n1 = new Node(data, NULL, NULL);
  n2 = new Node(data2, n1, NULL);
  assert (equals (n1->data, data));
  assert ( n1->next == NULL );
  assert ( n1->prev == NULL );
  assert ( n2->next == n1 );

  // Queue
  Queue* queue = new Queue<Data> ();
  
  // Queue::put
  queue->put(data);
  assert(equals(queue->head->data, data));
  assert( queue->head == queue->tail );
  queue->put(data2);
  assert(equals(queue->tail->data, data2));
  assert( queue->head->prev == queue->tail );
  assert( queue->head == queue->tail->next );
  assert( queue->head != queue->tail );
  
  // Queue::get
  Data data_res = queue->get();
  assert( equals(data_res, data) );
  assert( queue->head == queue->tail );
  assert( equals(queue->head->data, data2) );
  data_res = queue->get();
  assert( queue->tail == NULL );
  assert( queue->tail == queue->head );
  data_res = queue->get();

  queue->put(data);
  queue->put(data2);

  //print_head
  string str_res = "pos: 1 { "+data.print()+"}\npos: 2 { "+data2.print()+"}\n";
  assert( queue->print_head() == str_res );
  
  // Queue::search
  assert( queue->search(data2) );
  assert( queue->search(d4) );
  assert( !queue->search(data3) );

  return 0;
}

