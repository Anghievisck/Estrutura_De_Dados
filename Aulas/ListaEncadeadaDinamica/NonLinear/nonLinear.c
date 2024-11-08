#include <stdio.h>
#include <string.h>

#include "nonLinear.h"

List* Create(){
    List *l;

    l->start = NULL;
    l->end = NULL;

    return l;
}

void InstanciarAmigos(List *l, int *qualPai, int *qualFilho, int *nA, int *e){
    Pai *p = l->start;

    for(int i = 0; i < *qualPai; i++){
        if(p->prox == NULL){
            if(i < *qualPai - 1){
                *e = 1;
                return;
            }
            break;
        }

        p = p->prox;
    }

    Filho *f = p->primogenito;

    if(*qualFilho > p->totalDeFilhos){
        *e = 1;
        return;
    }

    for(int i = 0; i < *qualFilho; i++){
        f = f->prox;
    }

    f->amigos = (Filho**)malloc(sizeof(Filho*) * *nA);
}