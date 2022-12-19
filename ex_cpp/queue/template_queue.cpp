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

template <typename T>
Node<T>::Node (T _data, Node<T>* _next, Node<T>* _prev) { 
  data = _data, next = _next; prev = _prev;
}
template <typename T>
string Node<T>::print () { return data.print(); }

template <typename T>
Queue<T>::Queue () { head = NULL; tail = NULL; }
template <typename T>
void Queue<T>::put ( T data ) {
  if (tail == NULL) {
    Node<T>* n = new Node(data, NULL, NULL);
    tail = head = n;
  } else {
    Node<T>* n = new Node(data, tail, NULL);
    tail = tail->prev = n;
  }
}
template <typename T>
T Queue<T>::get () {
  assert (head != NULL); // panic if queue is empty
  T data = head->data;
  Node<T>* backup = head;
  if (head == tail) { // in caso la coda contenga solo un elemento
    tail = head = NULL;
  } else {
    head = head->prev;
    head->next = NULL;
  }
  delete backup;
  return data;
}
template <typename T>
string Queue<T>::print_head () {
  string result = "";
  Node<T>* s = head;
  int i = 1;
  while ( s != NULL ) {
    result += "pos: "+to_string(i++)+" { "+s->print()+"}\n";
    s = s->prev;
  }
  return result;
}
template <typename T>
bool Queue<T>::search ( T data ) {
  Node<T>* n = head;
  while (n != NULL) {
    if ( equals( n->data, data ) ) return true;
    n = n->prev;
  }
  return false;
}
