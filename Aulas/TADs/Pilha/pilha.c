#include "pilha.h"

typedef int type;

void Create(Stack *s){
    s -> index = -1;
}

void Empty(Stack *s){
    s -> index = -1;
}

int IsEmpty(Stack *s){
    return (s -> index == -1) ? 1 : 0;
}

int IsFull(Stack *s){
    return (s -> index == (LENGHT-1)) ? 1 : 0;
}

void Push(Stack *s, type *n, int *erro){
    if((*erro = IsFull(s))){
    } else {
        s -> index++;
        s -> stack[s -> index] = *n;
    }
}

void Pop(Stack *s, type *n, int *erro){
    if((*erro = IsEmpty(s))){
    } else {
        *n = s -> stack[s -> index];
        s -> index--;
    }
}

type Top(Stack *s, int *erro){
    if((*erro = IsEmpty(s))){
    } else {
        return s -> stack[s -> index];
    }
}