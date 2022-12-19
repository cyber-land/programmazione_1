#include <iostream>
using namespace std;
struct frac {
  int num, den;
};
int main() {
  int a = 5, *b = &a;
  cout << "address( " << &a << " ) size( " << sizeof(a) << " bytes ) " << endl;
  cout << a << endl;
  cout << "address( " << &b << " ) size( " << sizeof(b) << " bytes ) " << endl;
  cout << b << " that point to " << *b << endl;

  string s = "hello";
  cout << "address( " << &s << " ) size( " <<  s.size() << " bytes ) " << s << endl;
  // <dataType> * <pointer name> = new <dataType> [<size>];
  int *aa = new int[5], *ab = new int[] {1,2,3,4,5};
  cout << ab << endl;
  for (int i=0; i<5; i++) {
    cout << ab[i] << endl;
    aa[i] = ab[i];
  }
  delete [] ab;
  for (int i=0; i<5; i++) {
    cout << aa[i] << " " << ab[i] << endl;
    // ab stampa numeri sbagliati a causa dell use-after-free
  }
  frac *f;
  f = new frac[3];
  f[0] = {1,2}; f[1] = {3,5}; f[2]={7,8};
  for (int i=0; i<3; i++) cout << f[i].num << "/" << f[i].den << endl;

  cout << "hardlink" << endl;
  frac _f = frac{2,3};
  frac _g = _f;
  cout << &_f << endl;
  cout << &_g << endl;
  cout << _f.num << "/" << _f.den << endl;
  cout << _g.num << "/" << _g.den << endl;

  string ss = "hello";
  string *pss = &ss;
  cout << &ss << endl << pss << endl;
  int size = s.size();
  cout << size << endl;

  int _a = 3, _b = 2, _c = 1;
  int *ap[3];
  //int 
  ap[0] = &_a; ap[1] = &_b, ap[2] = &_c;
  for (int i=0;i<3;i++) cout << *ap[i] << endl;
  //delete [] ap;
  cout << _a << _b << _c << endl;
  int * aap = new int[] {3,4,5};
  cout << *aap << endl; // 3
  cout << *(aap+1) << endl; // 4

  return 0;
}
