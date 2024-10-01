#include "pilha.h"

typedef int type;

void CreateS(Stack *s){
    s -> index = -1;
}

void EmptyS(Stack *s){
    s -> index = -1;
}

int IsEmptyS(Stack *s){
    return (s -> index == -1) ? 1 : 0;
}

int IsFullS(Stack *s){
    return (s -> index == (LENGHT-1)) ? 1 : 0;
}

void Push(Stack *s, type *n, int *erro){
    if((*erro = IsFullS(s))){
    } else {
        s -> index++;
        s -> stack[s -> index] = *n;
    }
}

void Pop(Stack *s, type *n, int *erro){
    if((*erro = IsEmptyS(s))){
    } else {
        *n = s -> stack[s -> index];
        s -> index--;
    }
}

type Top(Stack *s, int *erro){
    if((*erro = IsEmptyS(s))){
    } else {
        return s -> stack[s -> index];
    }
}