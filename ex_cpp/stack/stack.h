#ifndef STACK_H
#define STACK_H

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
  Node (Data _data, Node * _next);
  std::string print ();
} Node;
Node* push (Node* node, Data data);
Node* pop (Node* node);
Data read (Node* node);
Data pop (Node &node);

#endif
