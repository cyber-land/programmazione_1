#include <iostream>
#include <cassert>
#include <string>

using namespace std;

typedef struct Data {
  int value;
  string str;
  void print () {
    cout << value << " " << str << endl;
  };

} Data;

typedef struct Queue {

  int n;    // numero elementi attuali
  int dim;  // numero elementi massimi
  int head;
  int tail;
  Data * s; // array

  Queue ( int d ) {
    n = head = tail = 0;
    dim = d;
    s = new Data[d];
  }

  ~Queue() { delete[] s; }

  bool is_empty () { return n == 0; }
  bool is_full () { return n == dim; }

  void print() { // tail to head
    if ( n == 0 ) return;
		int i = tail;
		do {
			s[ i ].print();
			i = ( i + 1 ) % dim;
		} while ( i != head );
  }

} Queue;

void put(Queue * q, Data d) {
  if ( q->is_full() ) return;
	q->s[ q->head ] = d;
	q->n++;
	q->head = ( q->head + 1 ) % q->dim;
}

Data get( Queue * q ) {
  assert ( !q->is_empty() );
	Data d = q->s[ q->tail ];
	q->tail = ( q->tail + 1 ) % q->dim;
  (q->n)--;
	return d;
}

int main() {
  Queue * queue = new Queue(4);

  // put

  Data d = Data { 50, "hello" };
  put ( queue , d );
  assert ( queue->n == 1 );

  for (int i=0; i<3; i++) {
    put ( queue , Data { i, "abc" } );
  }
  assert ( queue->n == 4 );

  put ( queue , d );
  assert ( queue->n == 4 );

  // print

  queue->print();

  // get

  while ( !queue->is_empty() ) {
    d = get ( queue );
    d.print ();
  }

  return 0;
}
