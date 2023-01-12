#include <string>
#include <cassert>

typedef struct Data {
  int value;
  float f;
  void print();
  std::string info();
} Data;
typedef struct Node {
  Data data;
  Node * next;
  Node () { data = Data { 0, 0.0 }; next = NULL; };
  Node( Data d, Node * n ) { data = d; next = n; };
  void print();
} Node;
