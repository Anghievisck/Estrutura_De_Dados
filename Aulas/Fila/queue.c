#include "queue.h"

void CreateQ(Queue *q){
    q -> start = 0;
    q -> end = 0; 
    q -> total = 0;
}

void EmptyQ(Queue *q){
    q -> start = 0;
    q -> end = 0; 
    q -> total = 0;
}

void In(Queue *q, item *x, int *e){
    if(IsFullQ(q)){
        *e = 1;
    } else {
        q -> Queue[(q -> end)%LENGHT] = *x;
        q -> end++;
        q -> total++;
        
        *e = 0;
    }
}

void Out(Queue *q, item *x, int *e){
    if(IsEmptyQ(q)){
        *e = 1;
    } else {
        *x = q -> Queue[(q -> start)%LENGHT];
        q -> start++;
        q -> total--;

        *e = 0;
    }
}

int IsEmptyQ(Queue *q){
    return (q -> total == 0) ? 1 : 0;
}

int IsFullQ(Queue *q){
    return (q -> total == LENGHT) ? 1 : 0;
}

int GetLength(Queue *q){
    return q -> total;
}