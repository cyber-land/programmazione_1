#include <iostream>
using namespace std;
int rsum (int v[], int pos) {
  if (pos == 0) return v[pos];
  return v[pos]+rsum(v, pos-1);
}

int main() {
  int *aa = new int[3], *ab[3];
  int a = 10, b = 20, c = 30;
  ab[0] = &a; ab[1] = &b; ab[2] = &c;
  for (int i=0; i<3; i++) {
    cout << *ab[i] << endl;
  }
  int vet[] = { 3, 0, -5, 7, 8 };
  cout << rsum (vet, 4) << endl;
  return 0;
}
