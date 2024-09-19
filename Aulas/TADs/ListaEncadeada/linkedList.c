#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    type data;
    Node *next;
} node;

typedef struct list{
    Node *start, *end;
} list;

List* Create(){
    List *l = (List *)malloc(sizeof(List));

    l->start = NULL;
    l->end = NULL;

    return l;
}

void DelList(List *l){
    Node *temp;
    while(l->start != NULL){
        temp = l->start->next;
        free(l->start);
        l->start = temp;
    }
}

void Insert(List *l, type *data, int *e){
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

node* SelectItem(List *l, type *data){
    node *temp = l->start;

    while(temp != NULL && temp->data != *data){
        temp = temp->next;
    }

    return temp;
}

void DelItem(List *l, type *data, int *e){
    node *temp = l->start;
    node *previous = temp;

    while(temp != NULL && temp->data != *data){
        previous = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        *e = 1; // NotFound
    } else {
        *e = 0;
        previous->next = temp->next;
        free(temp);
    }

    return;
}

int Length(List *l){
    int counter = 0;
    node *aux = l->start;

    while(aux->next != NULL){
        aux = aux->next;
        counter++; 
    }

    return counter;
}

void Invert(List *l){
    node *aux, *sup, *temp;

    aux = l->start;
    sup = aux->next;
    temp = sup->next;

    while (sup != NULL){
        sup->next = aux;
        aux = sup;
        sup = temp;
        temp = temp->next;
    }

    l->end = l->start;
    l->start = aux;
}

void PrintList(List *l){
    node *aux = l->start;
    while (aux != NULL){
        printf("%d", aux->data);
        aux = aux->next;
    }
}