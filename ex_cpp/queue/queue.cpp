#include <string>
#include <cassert>
#include "queue.h"
using namespace std;

Data::Data () { name[0]='\0'; surname[0]='\0'; age=0; }
Data::Data ( std::string _name, std::string _surname, int _age ) {
  name = _name; surname = _surname; age = _age;
}
string Data::print () {
  return "name: "+name+" surname: "+surname+" age: "+to_string(age);
}
bool equals ( Data a, Data b ) {
  return ( a.name == b.name && a.surname == b.surname && a.age == b.age );
}

Node::Node (Data _data, Node * _next, Node * _prev) { 
  data = _data, next = _next; prev = _prev;
}
string Node::print () { return data.print(); }

//Queue::Queue () { head = NULL; tail = NULL; }
void Queue::put ( Data data ) {
  if (tail == NULL) {
    Node * n = new Node(data, NULL, NULL);
    tail = head = n;
  } else {
    Node * n = new Node(data, tail, NULL);
    tail = tail->prev = n;
  }
}
Data Queue::get () {
  assert (head != NULL); // panic if queue is empty
  Data data = head->data;
  Node* backup = head;
  if (head == tail) { // in caso la coda contenga solo un elemento
    tail = head = NULL;
  } else {
    head = head->prev;
    head->next = NULL;
  }
  delete backup;
  return data;
}
string Queue::print_head () {
  string result = "";
  Node* s = head;
  int i = 1;
  while ( s != NULL ) {
    result += "pos: "+to_string(i++)+" { "+s->print()+"}\n";
    s = s->prev;
  }
  return result;
}
bool Queue::search ( Data data ) {
  Node * n = head;
  while (n != NULL) {
    if ( equals( n->data, data ) ) return true;
    n = n->prev;
  }
  return false;
}
