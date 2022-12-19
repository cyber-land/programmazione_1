#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#define MAXCHAR 20
using namespace std;

typedef struct Tdato {
  char nome[MAXCHAR];
  char cognome[MAXCHAR];
  unsigned int eta;
  Tdato () {
    nome[0]='\0'; cognome[0]='\0'; eta=0;
  }
  Tdato (char _nome[MAXCHAR], char _cognome[MAXCHAR], int _eta){
    strcpy(nome,_nome); strcpy(cognome,_cognome); eta=_eta;
  }
  void stampa() const{
    cout << "nome:"<<nome<<" cognome:"<<cognome<<" eta:"<<eta << endl;
  }
  bool compara(Tdato d){
    if ( (strcmp(nome,d.nome)==0) && (strcmp(cognome,d.cognome)==0) && (eta==d.eta) ) {
      return true;
    } else {
      return false;
    }
  }
} Tdato;
typedef struct Tnodo {
  Tdato dato;
  Tnodo * next;
  Tnodo () {
    next = NULL;
  }
  Tnodo (Tdato x, Tnodo * n) {
  dato = x; next = n;
  }
} Tnodo;
Tnodo* push (Tnodo* s, Tdato d) {
  Tnodo * n = new Tnodo();
  n->dato = d;
  n->next = s;
  return n;
}
Tnodo* pop (Tnodo * s) {
  if (s==NULL){
    return s;
  }
  Tnodo* n = s;
  s = s->next;
  delete n;
  return s;
}
Tdato read (Tnodo * s){
  Tdato d; //costruttore default;
  if (s==NULL) //lista vuota
  { return d; }
  return s->dato;
}
void stampa (Tnodo * s){
  Tnodo* p = s;
  while(p!=NULL){
    p->dato.stampa();
    p=p->next;
  }
}
int main(){
  Tnodo* mioStack=NULL;
  //Tdato d; //costruttore 0 param
  char name[MAXCHAR] = "michele", surname[MAXCHAR] = "gregorelli";
  Tdato d = Tdato(name, surname, 19);
  mioStack =push(mioStack, d);
  stampa(mioStack);
  if (mioStack!=NULL) {
    //leggo l’elemento
    d = read(mioStack);
    cout<<d.eta<<endl;
    //tolgo l’elemento
    mioStack = pop(mioStack);
  }
  stampa(mioStack);
  return 0;
}