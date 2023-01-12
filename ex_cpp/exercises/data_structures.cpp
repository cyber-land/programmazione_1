#include <iostream>
#include <string>
#include <cassert>

using namespace std;

struct Data {
  int value;
  string str;
  string print() { return str + " " + to_string(value); }
};
bool equals( Data a, Data b ) {
  return a.value == b.value && a.str == b.str;
}
struct Node {
  Data data;
  Node *next;
  Node (Data d, Node *n) { data = d; next = n; }
};
Node* push (Node *node, Data data) {
  return new Node (data, node);
}
string print(Node* node) {
  string s = "";
  int i = 0;
  while (node != NULL) {
    s += to_string(i++) + " { " + node->data.print() + " }\n";
    node = node->next;
  }
  return s;
}
bool is_ordered ( Node *node ) {
  if ( node == NULL ) return true;
  int prec = node->data.value;
  while ( node != NULL ) {
    if (node->data.value > prec ) return false;
    prec = node->data.value;
    node = node->next;
  }
  return true;
}

int main() {
  Data d = { 7, "hello" };
  cout << d.print() << endl;
  Node* n = new Node (d, NULL);
  assert( equals(n->data, d) );
  assert( n->next == NULL );
  n = push (n, Data {8, "foo"});
  n = push (n, Data {10, "_10_"});
  //assert( n->next->next == NULL );
  cout << print(n) << endl;
  cout << "ordered: " << ( is_ordered(n) ? "true" : "false" ) << endl;
  return 0;
}
