#ifndef QUEUE_H
#define QUEUE_H

struct Data {
  std::string name;
  std::string surname;
  unsigned int age;
  Data ();
  Data (std::string _name, std::string _surname, int _age);
  std::string print ();
  bool equals (Data b);
};
bool equals (Data a, Data b);

template <typename T>
struct Node {
  T data;
  Node<T> * next;
  Node<T> * prev;
  Node (T _data, Node* _next, Node* _prev);
  std::string print ();
};

template <typename T>
struct Queue {
  Node<T>* head;
  Node<T>* tail;
  Queue ();
  void put ( T data );
  T get ();
  std::string print_head ();
  bool search ( T data );
};

#endif
