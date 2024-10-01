#include <stdio.h>
#include "queue.h"

int IsCrescente(Queue f){
    int e = 0;
    item x, y;

    while(!IsEmptyQ(&f)){
        Out(&f, &x, &e);
        Out(&f, &y, &e);
        
        if(x > y){
            return 0;
        }
    }

    return 1;
}

int main(){
    Queue fila;
    item n;
    int e;

    Create(&fila); 

    for(int i = 0; i < 6; i++){
        In(&fila, &i, &e);
    }

    printf("Eh crescente? %d\n", IsCrescente(fila));

    for(int i = 6; i > 0; i--){
        Out(&fila, &n, &e);
        In(&fila, &i, &e);
    }

    printf("Eh crescente? %d", IsCrescente(fila));
}