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

typedef struct Node {
  Data data;
  Node * next;
  Node * prev;
  Node (Data _data, Node * _next, Node * _prev);
  std::string print ();
} Node;


typedef struct Queue {
  Node* head;
  Node* tail;
  Queue () { head = NULL; tail = NULL; }
  void put ( Data data );
  Data get ();
  std::string print_head ();
  bool search ( Data data );
} Queue;

#endif
