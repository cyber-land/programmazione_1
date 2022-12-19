#include <iostream>
#include <cassert>
using namespace std;

int f(int & x) {
  x--;
  return x;
}
int main() {
  int a = 10;
  int &refa = a; // a reference act like an alias to the underlying object
  assert( a == refa );
  assert( &a == &refa );
  cout << f(a) << " " << a << " " << refa << endl;
  return 0;
}
