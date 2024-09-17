#include <stdio.h>
#include "bookshelf.h"

void NewBook(book *b, char name[256]){
    b -> name = name;
    b -> avaiable = 1;

    CreateQ(&(b -> waitingList)); 
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

void ShowQueue(book *b){
    PrintQueue(b -> waitingList);
}