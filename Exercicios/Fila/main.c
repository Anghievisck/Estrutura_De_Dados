#include "../../Aulas/TADs/Fila/queue.h"
#include "../../Aulas/TADs/Pilha/pilha.h"
#include <stdio.h>

void Invert(Queue *q){
    Stack s;
    item x;
    int e1, e2, e3;

    CreateS(&s);

    while(!IsEmptyQ(q)){
        Out(q, &x, &e1);
        if(!e1){
            Push(&s, &x, &e2);
        }
    }

    while(!IsEmptyS(&s)){
        Pop(&s, &x, &e2);
        if(!e2){
            In(q, &x, &e3);
        }
    }
}

void PrintQueue(Queue f){
    item n;
    int e, length;
    
    length = GetLength(&f);

    for(int i = 0; i < length; i++){
        Out(&f, &n, &e);
        printf("Num: %d\n", n);
    }
}

void Union(Queue f1, Queue f2, Queue *q){

    printf("Under development...\n");
}

int main(){
    Queue fila1, fila2, fila3;
    item n;
    int e;

    CreateQ(&fila1);
    CreateQ(&fila2);
    CreateQ(&fila3);

    for(int i = 1; i <= 10; i++){
        In(&fila1, &i, &e);
    }

    PrintQueue(fila1);
    Invert(&fila1);
    printf("Invertendo fila...\n");
    PrintQueue(fila1);

    for(int i = 20; i > 9; i--){
        In(&fila2, &i, &e);
    }

    Union(fila1, fila2, &fila3);
    PrintQueue(fila3);
}