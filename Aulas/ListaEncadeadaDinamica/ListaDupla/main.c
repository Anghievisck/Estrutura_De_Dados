#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubleLinkedList.h"

int main(){
    List *l = Create();

    char c[50] = "teste";
    int e;

    for(int i = 0; i < 10; i++){
        Insert(l, &c, &i, &e);
    }

    int pos = 1;
    char b[50] = "Surpresa, eu voltei";
    Insert(l, &b, &pos, &e);

    Node *aux = l->start;
    for(int i = 0; i < 11; i++){
        printf("%s ", aux->name);
        aux = aux->next;
    }
}