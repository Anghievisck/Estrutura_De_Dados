#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TADs/pilha.h"

void PrintStack(stack *s, int *e){
    int x;
    stack temp;

    Create(&temp);

    while(!IsEmpty(s)){
        Pop(s, &x, e);
        if(!*e){
            printf("%d\n", x);
            Push(&temp, &x, e);
            if(*e){
                printf("There was an error.");
                return;
            }
        } else {
            printf("There was an error.");
            return;
        }
    }

    while(!IsEmpty(&temp)){
        Pop(&temp, &x, e);
            if(!*e){
                Push(s, &x, e);
            if(*e){
                printf("There was an error.");
                return;
            }
        } else {
            printf("There was an error.");
            return;
        }
    }

    return;
}

int isEqual(stack *s, stack *p, int *e){
    int temp;
    stack auxS, auxP;

    while(!IsEmpty(s)){
    }
    

    while(1 == 1){
        if(IsEmpty(s) != IsEmpty(p)){
            return 0;
        } else {
        }
    }
}

int main(){
    stack s;
    int e = 0;

    Create(&s);

    for(int i = 1; i < 21; i ++){
        Push(&s, &i, &e);
    }

    PrintStack(&s, &e);

    return 0;
}