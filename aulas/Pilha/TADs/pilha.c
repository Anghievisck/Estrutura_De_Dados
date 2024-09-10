#include "pilha.h"

typedef int type;

void Create(pilha *s){
    s -> index = -1;
}

void Empty(pilha *s){
    s -> index = -1;
}

int IsEmpty(pilha *s){
    return (s -> index == -1) ? 1 : 0;
}

int IsFull(pilha *s){
    return (s -> index == (LENGHT-1)) ? 1 : 0;
}

void Push(pilha *s, type *n, int *erro){
    if((*erro = IsFull(s))){
    } else {
        s -> index++;
        s -> stack[s -> index] = *n;
    }
}

void Pop(pilha *s, type *n, int *erro){
    if((*erro = IsEmpty(s))){
    } else {
        *n = s -> stack[s -> index];
        s -> index--;
    }
}

type Top(pilha *s, int *erro){
    if((*erro = IsEmpty(s))){
    } else {
        return s -> stack[s -> index];
    }
}