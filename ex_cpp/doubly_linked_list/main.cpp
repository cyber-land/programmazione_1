#include <iostream>
#include <string>
#include <cassert>
#include <random>
#include <ctime>

using namespace std;
int rand_int(int min, int max) { // [min, max)
  return rand() % (max - min) + min;
}
float rand_f(float min, float max) {
  float r = (float)rand() / (float)RAND_MAX;
  return min + r * (max - min);
}
typedef struct Data {
  int index;
  float value;
  //~Data();
  Data() {index = 0; value = 0;};
  Data ( int i, float v ) { index = i; value = v; }
  string print () { return "index: "+to_string(index)+" value: "+to_string(value); }
  bool equals(Data * d) { return d->index == index && d->value == value; }
  bool gt(Data d) { return index > d.index; }
} Data;
/*  Costruttore 0 parametri
    Costruttore specifico
    Distruttore
    Metodo di stampa */
Data rand_d() {
  return Data(rand_int(1, 10), rand_f(1, 10));
}
typedef struct Node {
	Data data;
	Node * next;
	Node * prev;
  //~Node();
  Node () { prev = NULL; next = NULL; }
  Node (Data x, Node * p, Node * n) { data = x; prev = p; next = n; }
} Node;

typedef struct List {
  Node * head;
  Node * tail;
} List;

// insert first - last - order
// read first
// remove first

string print (Node* node) {
  string result = "";
  Node* s = node;
  int i = 1;
  while ( s != NULL ) {
    result += "pos: "+to_string(i++)+" { "+s->data.print()+"}\n";
    s = s->next;
  }
  return result;
}

Node* insert_first (Node* s, Data d) {
  Node* q = new Node(d, NULL, s);
  if(s != NULL) {
    s->prev = q;
  }
  return q;
}
Node* insert_last (Node* s, Data d) {
  if (s == NULL) {
    return insert_first(s, d);
  }
  Node * p = s;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = new Node(d, p, NULL);
  return s;
}
Node* insert_order (Node* s, Data d) {
  Node *q = new Node(d, NULL, NULL);
  if (s==NULL) { return q; }  //caso1: lista vuota
  if (! d.gt(s->data) ) {     //caso2: insertfirst
    q->next = s;
    s->prev = q;
    return q;
  }
  Node* p = s;
  while( p != NULL ) {
    if ( ! d.gt(p->data)) { break; }
    p=p->next;
  }
  if (p==NULL) { return insert_last(s,d); } //caso3: insertlast
  q->next = p;
  //caso4: insert all'interno
  q->prev = p->prev; p->prev->next = q; p->prev = q;
  return s;
}
Node* remove_first (Node* s) {
  // causa un use-after-free siccome non aggiorna il puntatore nel main
  Node* n = s;
  if (s!=NULL) {
    s = s->next;
    if ( s != NULL ) s->prev=NULL;
    delete n;
  }
  return s;
}
int main() {
  std::srand(std::time(nullptr));
  Node *p = NULL, *o = NULL;
  
  for (int i=0; i<10; i++)
    p = insert_first(p, rand_d());
  Node * n = p;
  while (n != NULL) {
    cout << n->data.print() << endl;
    n = n->next;
  }
  n = p;
  cout << "_ " << n << endl;
  while (n != NULL) {
    Data t = n->data;
    n = remove_first(n);
    o = insert_order(o, t);
    // cout << print(o) << endl;
  }
  n = o;
  while (n != NULL) {
    cout << ": " << n->data.print() << endl;
    n = n->next;
  }
  
  /*Data* d = new Data(5, 5.5), *d1 = new Data(5, 5.5);
  p = insert_first(p, d);
  assert(p->next == NULL && p->prev == NULL);
  assert(d->equals(p->data));
  p = insert_last(p, d1);
  assert(d1->equals(p->next->data));
  assert(p->next->next == NULL && p->next->prev == p);*/
  return 0;
}