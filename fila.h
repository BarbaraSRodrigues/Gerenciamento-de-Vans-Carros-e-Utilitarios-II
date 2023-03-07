#ifndef FILA_H
#define FILA_H

typedef tLista tFila;

inline tFila* inicia_fila(){
    return inicia_lista();
};

inline tFila * encerra_fila(tFila * p){
    return encerra_lista(p);
};

inline void queue(tFila * p, no *ins){
    insere_fim(p, ins);
};

inline no * unqueue(tFila * p){
    return remove_inicio(p);
};

#endif /* FILA_H */