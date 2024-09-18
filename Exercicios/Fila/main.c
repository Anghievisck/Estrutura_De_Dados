#include "../../Aulas/TADs/Fila/queue.h"
#include "../../Aulas/TADs/Pilha/pilha.h"
#include <stdio.h>

int IsCrescente(Queue f){
    int e = 0;
    item x, y, temp;

    Out(&f, &x, &e);
    Out(&f, &y, &e);

    temp = y;

    if(temp > y || x > y){
        return 0;
    }

    while(!IsEmptyQ(&f)){
        Out(&f, &x, &e);
        Out(&f, &y, &e);

        if(temp > y || x > y){
            return 0;
        }

        temp = y;
    }

    return 1;
}

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

int Union(Queue f1, Queue f2, Queue *q){
    item x, y, highest = 0;
    int e1, e2, e3, maxLenght, l1, l2, aux;

    l1 = GetLength(&f1);
    l2 = GetLength(&f2);

    maxLenght = (l1 > l2) ? l1 : l2;

    int total = l1 + l2;
    item v[total];

    int j = 0;
    for(int i = 0; i < maxLenght; i++){
        Out(&f1, &x, &e1);
        Out(&f2, &y, &e2);

        if(!e1){
            v[j] = x;
            j++;
        }

        if(!e2){
            v[j] = y;
            j++;
        }
    }


    for(int i = 0; i < (total - 1); i ++){
        if(v[i] > v[i + 1]){
            aux = v[i + 1];
            v[i + 1] = v[i];
            v[i] = aux;
        }
    }

    for(int i = 0; i < total; i++){
        In(q, &v[i], &e3);
    }

    return IsCrescente(*q);
}

int main(){
    Queue fila1, fila2, fila3;
    item n;
    int e;

    CreateQ(&fila1);
    CreateQ(&fila2);
    CreateQ(&fila3);

    for(int i = 1; i <= 20; i++){
        if(i % 2 == 0){
            In(&fila1, &i, &e);
        }
    }

    printf("Crescente? %d\n", IsCrescente(fila1));
    PrintQueue(fila1);
    Invert(&fila1);
    printf("Invertendo fila...\n");
    PrintQueue(fila1);

    for(int i = 1; i <= 20; i++){
        if(i % 2 == 1){
            In(&fila2, &i, &e);
        }
    }

    Invert(&fila1);
    printf("Uniao: %d\n", Union(fila1, fila2, &fila3));
    PrintQueue(fila3);
}