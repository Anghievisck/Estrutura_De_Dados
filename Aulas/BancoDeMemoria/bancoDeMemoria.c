#include <stdlib.h>
#include "bancoDeMemoria.h"

Bank* Create(){
    Bank *b;

    b->first_empty = 0;
    b->start = -1;
    b->end = -1;

    for(int i = 0; i < LENGTH - 1; i++){
        b->bank[i].next = i++;
    }

    b->bank[LENGTH-1].next = -1;

    return b;
}

void GetNode(Bank *b, int *pos){
    if(b->first_empty != -1){
        *pos = b->first_empty;
        b->first_empty = b->bank[b->first_empty].next;
        b->bank[*pos].next = -1;
    } else {
        *pos = -1;
    }
}

void FreeNode(Bank *b, int *pos){
    b->bank[*pos].next = b->first_empty;
    b->first_empty = *pos;
}

void Insert(Bank *b, Data *item, int *e){
    int pos;

    GetNode(b, &pos);

    if(pos == -1 || IsFull(b)){
        *e = 1;
        return;
    }

    *e = 0;

    if(b->start == -1){
        b->start = pos;
    }

    b->bank[b->end].next = pos;
    b->end = pos;

    b->bank[pos].item = *item;
}