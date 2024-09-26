#include "linkedList.h"
#include <stdlib.h>

List* Q_Create(){
    return L_Create();
}

void Q_Insert(List *q, elem *data, int *e){
    Node *temp = (Node *)malloc(sizeof(Node));
    if(temp == NULL){
        *e = 1;
    } else {
        temp->data = *data;
        temp->next = NULL;
        if(q->start == NULL){
            q->start = temp;
        } else {
            q->end->next = temp;
            q->end = temp;

            *e = 0;
        }
    }
}

void Q_Pop(List *q, elem *data, int *e){
    if(q->start = NULL){
        *e = 1;
    } else {
        *data = q->start->data;

        Node *temp = q->start;
        q->start = q->start->next;

        if(q->start == NULL){
            q->end = NULL;
        }

        free(temp);
        *e = 0;
    }
}