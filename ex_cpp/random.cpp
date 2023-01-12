#include <iostream>
#include <stdlib.h>
using namespace std;
// generate random integers in a range [ Min , Max )
int random_int(int min, int max) {
  if ( min >  max ) return random_int(max, min);
  if ( min == max ) return min;
  return min + (rand() % (max - min));
}
float random_float() {
  return (float)(rand()) / (float)(rand());
  // generate the fraction part only
  // return (float)(rand()) / (float)(RAND_MAX);
}
int main() {
  srand(time(0));
  for(int i = 1; i <= 5; i++) {
    int number = rand() % 100; // [ 0, 100 )
    cout << number  << " " << random_float() << " " << random_int(10, 20) << endl;
  }
  return 0;
}
