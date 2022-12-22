#include <iostream>
#include <cassert>
using namespace std;
// passaggio per valore
int v (int x) {

}
// passaggio per indirizzo
int i (int *x) {

}
// passaggio per riferimento
// si lavora direttamente sulla variabile passata
int r(int &x) {
  x--;
  return x;
}
int main() {
  int a = 10;
  int &refa = a; // a reference act like an alias to the underlying object
  assert( a == refa );
  assert( &a == &refa );
  cout << r(a) << " " << a << " " << refa << endl;
  return 0;
}
