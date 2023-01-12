#include <iostream>
#include <stdlib.h>
using namespace std;
int casuale(int min, int max){
	return rand()%(max-min+1)+min;
}
int main() {
  srand(time(0));
  int x=5;
  int y;
  int* ptr1=&y;
  *ptr1 = 7;
  int* const ptr2=&y;
  const int* const ptr3=&y;
  //ptr3 = &x;

  cout << &y << " " << y << endl;
  cout << &ptr1 << " " << ptr1 << endl;
  cout << &ptr2 << " " << ptr2 << endl;
  cout << &ptr3 << " " << ptr3 << endl;

  cout << casuale( 1000, 5000) /100.0 << endl;
  return 0;
}
