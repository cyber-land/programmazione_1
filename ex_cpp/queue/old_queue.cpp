#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib> // rand
#define MAXCHAR 20
using namespace std;

typedef struct Tdato {
  char nome[MAXCHAR];
  char cognome[MAXCHAR];
  int eta;
  Tdato () {
    nome[0]='\0'; cognome[0]='\0'; eta=0;
  }
  Tdato (char _nome[MAXCHAR],char _cognome[MAXCHAR], int _eta){
    strcpy(nome,_nome); strcpy(cognome,_cognome); eta=_eta;
  }
  void stampa() const{
    cout << "nome:"<<nome<<" cognome:"<<cognome<<" eta:"<<eta << endl;
  }
  bool compare(Tdato d){
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
  Tnodo() { next = NULL; }
  Tnodo (Tdato x, Tnodo * n) {
    dato = x; next = n;
  }
  void stampa() const {
    dato.stampa();
  }
} Tnodo;
typedef struct TipoCoda {
  Tnodo * head;
  Tnodo * tail;
  TipoCoda() {
    head = NULL; tail=NULL;
  }
  void put (Tdato d) {
    Tnodo * n = new Tnodo(d, NULL);
    Tnodo * p = head;
    if (p==NULL){
      head = n;
    } else {
      while(p->next!=NULL){
        p=p->next;
      }
      p->next = n;
    }
  }
  Tdato get () {
    Tdato d;
    if(head!=NULL){
      d = head->dato;
      Tnodo* p=head;
      head=head->next;
      delete p;
    }
    return d;
  }
  Tdato read (){
    Tdato d;
    if(head!=NULL){
      d = head->dato;
    }
    return d;
  }
  void stampa () const {
    Tnodo* s = head;
    while (s!=NULL){
      s->stampa();
      s= s->next;
    }
  }
}TipoCoda;
typedef struct TipoCoda Coda;
typedef struct TipoCoda* CodaPtr;
CodaPtr put (CodaPtr s, Tdato d) {
  Tnodo * n = new Tnodo(d, NULL);
  Tnodo * p = s->head;
  CodaPtr x = new TipoCoda();
  if (p==NULL){
    return x;
  } else {
    while(p->next!=NULL){
      p=p->next;
    }
    p->next = n;
    return s;
  }
}
Tdato get (CodaPtr p){
  Tdato d;
  d = p->head->dato;
  //caso 1 solo elemento
  if (p->head->next== NULL) {
    p->head=NULL;
  } else {
    //lista con + elementi
    p->head=p->head->next;
  }
  return d;
}
Tdato read (CodaPtr p){
  Tdato d;
  if(p->head!=NULL){
    d = p->head->dato;
  }
  return d;
}
bool cerca (CodaPtr p, Tdato d) {
  Tnodo * n = p->head;
  while (n != NULL) {
    if (n->dato.compare(d)) return true;
    n = n->next;
  }
  return false;
}
int main () {
  CodaPtr miaCoda=new TipoCoda();
  //TODO: correggere!!!
  char name[MAXCHAR] = "michele", surname[MAXCHAR] = "gregorelli";
  Tdato d = Tdato(name, surname, 19);
  miaCoda->put(d);
  miaCoda->put(d);
  miaCoda->put(d);
  miaCoda->stampa();
  if (miaCoda!=NULL) {
    d=get(miaCoda); // d= miacoda->get();
    d.stampa();
  }
  cout << (cerca (miaCoda, d) ? "true" : "false") << endl;
  int num = 3; CodaPtr array[num];
  for (int i=0; i<num; i++) array[i] = new TipoCoda();
  for (int i=0; i<5; i++) {
    int r_num = rand()%num; cout << "put in r_num: " << r_num << endl;
    array[r_num]->put(d);
    for (int i=0; i<num; i++) {
      cout << i << endl;
      array[i]->stampa();
    }
    r_num = rand()%num; cout << "get from r_num: " << r_num << endl;
    if (array[r_num]!=NULL) { d= array[r_num] ->get(); }
    for (int i=0; i<num; i++) {
      cout << i << endl;
      array[i]->stampa();
    }
  }


  return 0;
}