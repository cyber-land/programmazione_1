#include <string>

#ifndef STACK_H
#define STACK_H

typedef enum TVeicolo { AUTO, MOTO, BUS } TVeicolo;

typedef struct Trevisione{
  char proprietario[20];
  unsigned int annoImm;
  float valutazione;
  TVeicolo tipoVeicolo;

  Trevisione();
  void setValutazione(float v);
  std::string get_info();
  void stampa();
} Trevisione;

typedef struct Tnodo {
  Trevisione revisione;
  Tnodo *next;

  Tnodo (Trevisione _revisione);
  void stampa();
} Tnodo;

#endif
