#include <string>
#include <iostream>
#include <cassert>
#include "stack.h"
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

Node::Node ( Data _data, Node * _next ) { 
  data = _data, next = _next;
}
string Node::print () {
  string result = "";
  Node* node = this;
  if (node == NULL) return result;
  while (node != NULL) {
    result += node->data.print()+"\n"; 
    node = node->next;
  }
  result.pop_back();
  return result;
}
Node* push (Node* node, Data data) {
  return new Node(data, node);
}
Node* pop (Node* node) {
	if ( node == NULL) return node;
	Node* temp = node;
	node = node->next;
	delete temp;
	return node;
}
Data pop (Node &node) {
  assert(&node != NULL);
  cout << node.data.print() << endl;
  Data res = node.data;
  Node *temp = node.next;
  cout << "T: " << temp->data.print() << endl;
  node = *(node.next);
  delete temp;
  return res;
}
Data read (Node* node) {
	assert(node != NULL);
	return node->data;
}
