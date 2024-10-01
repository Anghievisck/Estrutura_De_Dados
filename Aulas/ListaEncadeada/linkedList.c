#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

List* L_Create(){
    List *l = (List *)malloc(sizeof(List));

    l->start = NULL;
    l->end = NULL;

    return l;
}

void L_Delete(List *l){
    Node *temp;
    while(l->start != NULL){
        temp = l->start->next;
        l->start = NULL;
        free(l->start);
        l->start = temp;
    }

    free(l);
}

Node* SelectNode(List *l, elem *data){
    Node *temp = l->start;

    while(temp != NULL && temp->data != *data){
        temp = temp->next;
    }

    return temp;
}

elem FindElementByID(List *l, int id, int *e){
    Node *aux = l->start;
    *e = 0;

    for(int i = 0; i < id; i ++){
        aux = aux->next;
        if(aux == NULL){
            *e = 1;
            break;
        }
    }

    return (*e == 0) ? aux->data : -1;
}

int IsInList(List *l, elem *data){
    if(SelectNode(l, data) == NULL){
        return 0;
    }

    return 1;
}

void L_Insert(List *l, elem *data, int *e){
    Node *temp = (Node *)malloc(sizeof(Node));
    if(temp == NULL){
        *e = 1;
        return;
    }

    *e = 0;
    temp->data = *data;
    temp->next = NULL;

    if(l->start == NULL){
        l->start = temp;
        l->end = l->start;
    } else {
        l->end->next = temp;
        l->end = temp;
    }
}


void DelItem(List *l, elem *data, int *e){
    Node *temp = l->start;
    Node *previous = temp;

    while(temp != NULL && temp->data != *data){
        previous = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        *e = 1; // NotFound
    } else if(temp == l->start){
        *e = 0;
        l->start = NULL;
        free(l->start);
        l->start = temp->next;
    } else if(temp == l->end){
        *e = 0;
        temp = NULL;
        free(temp);
        l->end = previous;
        l->end->next = NULL;
    } else {
        *e = 0;
        previous->next = temp->next;
        temp = NULL;
        free(temp);
    }

    return;
}

void DelItemByID(List *l, int id, int *e){
    Node *temp = l->start;
    Node *previous = temp;

    *e = 0;

    if(id == 0){
        l->start = NULL;
        free(l->start);
        l->start = temp->next;

        return;
    }

    for(int i = 0; i < id; i++){
        previous = temp;
        temp = temp->next;
        if(temp == NULL){
            *e = 1; // NotFound
            return;
        }
    }

    if(temp == l->end){
        *e = 0;

        l->end = NULL;
        free(l->end);
        l->end = previous;
        l->end->next = NULL;

        return;
    }

    previous->next = temp->next;
    temp = NULL;
    free(temp);

    return;
}

int L_Length(List *l){
    int counter = 1;
    Node *aux = l->start;

    while(aux->next != NULL){
        aux = aux->next;
        counter++; 
    }

    return counter;
}


int Counter(Node* n){
    if(n != NULL){
        return 0;
    } else {
        return 1 + Counter(n->next);
    }
}

int LengthR(List *l){
    return(Counter(l->start));
}

void L_Invert(List *l){
    Node *aux, *sup, *temp;

    aux = l->start;
    sup = aux->next;
    temp = sup->next;

    while (temp != NULL){
        sup->next = aux;
        aux = sup;
        sup = temp;
        temp = temp->next;
    }

    sup->next = aux;

    aux = l->start;
    l->start = l->end;
    l->end = aux;
    l->end->next = NULL;
}

void PrintList(List *l){
    Node *aux = l->start;
    while (aux != NULL){
        printf("%d", aux->data);
        aux = aux->next;
    }
}