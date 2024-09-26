#include "linkedList.h"
#include <stdlib.h>

Stack* S_Create(){
    Stack *p = (Stack *)malloc(sizeof(Stack));
    if(p != NULL){
        p->top = NULL;
    }

    return p;
}

void S_Push(Stack *s, elem *data, int *e){
    Node *temp = (Node *)malloc(sizeof(Node));
    if(temp == NULL){
        *e = 1;
        return;
    }

    temp->data = *data;
    temp->next = s->top;    

    s->top = temp;

    if(s->top->data != *data){
        *e = 1;
    } else {
        *e = 0;
    }
}

void S_Pop(Stack *s, elem *data, int *e){
    Node *temp = s->top;

    if(temp == NULL){
        *e = 1;
        return;
    }

    *e = 0;
    
    *data = temp->data;
    s->top = s->top->next;

    free(temp);

    return;
}

int S_IsEmpty(Stack *s){
    return (s->top == NULL) ? 1 : 0;
}

/*
    Só funciona no país das maravilhas por conta de falsos positivos:
        int S_IsFull(Stack *s){
            Node *temp = (Node *)malloc(sizeof(Node));
            int e = (temp == NULL) ? 1 : 0;

            free(temp);

            return e;
        }
*/

void S_Delete(Stack *s){
    Node *temp;
    while(s->top != NULL){
        temp = s->top;
        s->top = s->top->next;

        free(temp);
    }
}