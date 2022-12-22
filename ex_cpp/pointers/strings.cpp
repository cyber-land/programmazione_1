#include <iostream>
using namespace std;

int main() {
  char str[] = "abcdef"; // chars array (mutable)
  char *ptl = str; // pointer to the same address
  printf("str: size (%li byte) value (%s) address (%p) that point to (%c) \n",
  sizeof(str), str, &str, *str );
  printf("ptl: size (%li byte) value (%s) address (%p) that point to (%c) of address (%p) \n\n",
  sizeof(ptl), ptl, &ptl, *ptl, ptl );

  char const *lit = "fedcba"; // string literal (read only)
  printf("lit: size (%li byte) value (%s) address (%p) that point to (%c) of address (%p) \n",
  sizeof(lit), lit, &lit, *lit, lit );

  /* pointer arithmetic
	quando si somma e sottrae interi ad un puntatore si moltiplica il valore per
	il numero di byte che occupa il tipo del puntatore */
  printf("pointer arithmetic: address (%p) point to (%c) distance (%ld byte) \n\n",
  (lit+2), *(lit+2), (lit+2)-(lit) );
  // aggiungendo 2 al puntatore di chars si aggiunge (2 * 1 byte)
}
