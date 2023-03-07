#ifndef PILHA_H
#define PILHA_H

#include "lista.h"

typedef tLista tPilha;

inline tPilha* inicia_pilha(){
    return inicia_lista();
};

inline tPilha * encerra_pilha(tPilha * p){
    return encerra_lista(p);
};

inline void push(tPilha * p, no *ins){
    insere_inicio(p, ins);
};

inline no * pop(tPilha * p){
    return remove_inicio(p);
};

#endif /* PILHA_H */