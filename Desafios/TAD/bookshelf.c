#include <stdio.h>
#include "bookshelf.h"

void NewBook(book *b, char name[256]){
    b -> name = name;
    b -> avaiable = 1;

    CreateQ(&(b -> waitingList)); 
}

void DeleteBook(book *b){
    for(int i = 0; i < 128; i++){
        b -> name[i] = '';
    }

    b -> avaiable = 0;
    EmptyQ(&(b -> waitingList));
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