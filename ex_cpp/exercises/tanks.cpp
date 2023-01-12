#include <iostream>
using namespace std;

void victory(int att_force, int def_force) {
  float att = att_force;
  float def = def_force;
  int n_round = 0;
  while (true) {
    cout << n_round << " " << att << " " << def << endl;
    def -= att/3;
    if ( def <= 1 ) {
      cout << "victory after " << n_round << " rounds" << endl;
      cout << att_force-att << " army lost" << endl;
      break;
    }
    att -= def/3;
    if ( att <= 0 ) {
      cout << "lose after " << n_round << " rounds" << endl;
      cout << def_force-def << " def army lost" << endl;
      break;
    }
    n_round++;
  }
}

int main() {
  victory ( 17 , 16 );
  return 0;
}
