#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../TADs/Pilha/pilha.h"

void PrintStack(Stack *s, int *e){
    type x;
    Stack temp;

    Create(&temp);

    while(!IsEmptyS(s)){
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

    while(!IsEmptyS(&temp)){
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

int isEqual(Stack s, Stack p){
    type x, y;
    int e1, e2;

    while(!IsEmptyS(&s) || !IsEmptyS(&p)){
        Pop(&s, &x, &e1);
        Pop(&p, &y, &e2);

        if(x != y || e1 != e2){
            return 0;
        }
    }

    return 1;
}

Stack invertStack(Stack s, int *e){
    Stack temp;
    type x;

    Create(&temp);

    while(!IsEmptyS(&s)){
        Pop(&s, &x, e);
        if(!*e){
            Push(&temp, &x, e);
            if(*e){
                printf("There was an error.");
                break;
            }
        } else {
            printf("There was an error.");
            break;
        }
    }

    return temp;
}

int main(){
    Stack s, p;
    int e = 0;

    Create(&s);
    Create(&p);

    for(int i = 1; i < 21; i ++){
        Push(&s, &i, &e);
        Push(&p, &i, &e);
    }

    PrintStack(&s, &e);
    printf("\nIs equal?(1 == y, 0 == n)\n%d", isEqual(s, p));

    p = invertStack(p, &e);
    printf("\n\nInvernting...\np:\n");

    PrintStack(&p, &e);

    return 0;
}