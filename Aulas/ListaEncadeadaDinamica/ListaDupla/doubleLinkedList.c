#include "doubleLinkedList.h"
#include <stdlib.h>
#include <string.h>

List* Create(){
    List *l;

    l->end = NULL;
    l->start = NULL;

    return l;
}

void Insert(List *l, char *x, int *pos, int *e){
    Node *temp = (Node *)malloc(sizeof(Node));
    Node *aux;

    strcpy(temp->name, x);
    temp->next = NULL;
    temp->previous = NULL;

    if(l->start == NULL){
        l->start = temp; 
        l->end = temp;
    } else if(*pos == 1){
        temp->next = l->start;

        l->start->previous = temp;
        l->start = temp;
    } else {
        aux = l->start;
        for(int i = 0; i < *pos; i++){
            if(aux->next == NULL){
                if(i < *pos - 1){
                    aux->next = temp;

                    temp->previous = aux;                

                    l->end = temp;
                    return;
                }
                break;                
            } else {
                aux = aux->next;
            }
        }

        Node *sup = aux->previous;
        sup->next = temp;
        temp->next = aux;
        temp->previous = aux->previous;
        aux->previous = temp;
    }
}