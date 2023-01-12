#include <iostream>
#include <cassert>
using namespace std;

typedef struct Data {
  int x, y, z;
  Data() { x=y=z=0; };
  Data ( int _x, int _y, int _z ) {
    x = _x; y = _y; z = _z;
  }
  void print() const {
    cout << "x: " << x << " y: " << y << " z: " << z;
  }
} Data;
typedef struct Stack {
  int n; // numero elementi presenti
  int dim; // dimensione massima array
  Data* s; // array
  Stack ( int d ) {
    n = 0; dim = d; s = new Data[d];
  }
  bool is_empty() { return n==0; }
  bool is_full() { return n==dim; }
  void print() const {
    assert ( n >= 0 );
    cout << "stack [ ( "; s[0].print(); cout << " ) ";
    for (int i=1; i<n; i++) {
      cout << " ( "; s[i].print(); cout << " ) ";
    }
    cout << " ]" << endl;
  }
} Stack;
void push ( Stack *s, Data d ) {
  if ( s->is_full() ) return;
  s->s[s->n] = d;
  (s->n)++;
}
Data pop ( Stack s ) {
  assert ( !s.is_empty() );
  (s.n)--;
  return s.s[s.n];
}

int main( int argc, char *argv[] ) {
  Stack* mios = new Stack(3);
  Data d(9,8,7);
  mios->print();
  push(mios, Data());
  push(mios, Data(4,3,2));
  push(mios, d);
  mios->print();
  if ( !mios->is_empty() ) {
    d = pop( (*mios) );
    d.print(); cout << endl;
  }
  delete mios;
}
