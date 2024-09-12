#include "pilha.h"

typedef int type;

void Create(stack *s){
    s -> index = -1;
}

void Empty(stack *s){
    s -> index = -1;
}

int IsEmpty(stack *s){
    return (s -> index == -1) ? 1 : 0;
}

int IsFull(stack *s){
    return (s -> index == (LENGHT-1)) ? 1 : 0;
}

void Push(stack *s, type *n, int *erro){
    if((*erro = IsFull(s))){
    } else {
        s -> index++;
        s -> stack[s -> index] = *n;
    }
}

void Pop(stack *s, type *n, int *erro){
    if((*erro = IsEmpty(s))){
    } else {
        *n = s -> stack[s -> index];
        s -> index--;
    }
}

type Top(stack *s, int *erro){
    if((*erro = IsEmpty(s))){
    } else {
        return s -> stack[s -> index];
    }
}