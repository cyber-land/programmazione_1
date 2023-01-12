#include <string>
#include <cassert>

typedef enum Tmail {PEC, STD} Tmail;
typedef struct Tdata{ int gg, mm, aa; } Tdata;
typedef struct Tmessaggio {
  int id;
  Tmail tipo;
  Tdata data;
  char messaggio[100];
  Tmessaggio ();
  void stampa(); // d
} Tmessaggio;
typedef struct Tmailbox {
  Tmessaggio msg;
  Tmailbox* next;
  Tmailbox ();
  Tmailbox ( Tmessaggio m, Tmailbox * n ) { msg = m; next = n; }
  void stampa();
} Tmailbox; // stack
