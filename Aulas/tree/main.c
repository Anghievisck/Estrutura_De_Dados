#include "tad/organizedTree.h"

#include <stdio.h>
#include <stdlib.h>

int HeightSup(Node *n){
    int heightL, heightR;
    if(n != NULL){
        heightL = 1 + HeightSup(n->nextL);
        heightR = 1 + HeightSup(n->nextR);

        return (heightL > heightR) ? heightL : heightR;
    } else {
        return 0;
    }
}

int GetTreeHeight(Node *n){
    return HeightSup(n) - 1;
}

void DelTreeSup(Node *n){
    if(n != NULL){
        DelTreeSup(n->nextL);
        DelTreeSup(n->nextR);

        n->nextL = NULL;
        n->nextR = NULL;

        free(n);
        n = NULL;
    }
}

void DelTree(Tree **t){
    DelTreeSup((*t)->sentinel->nextL);
    DelTreeSup((*t)->sentinel->nextR);

    (*t)->sentinel->nextL = NULL;
    (*t)->sentinel->nextR = NULL;
}

int main(){
    Tree *t = Create();

    Data info;
    int status;

    if(t != NULL){
        status = 1;
    } else {
        status = 0;
    }

    printf("Arvore criada: %d\n\n", status);

    info.i = 5;
    printf("Insert (INT): %d\n", Insert(t, &info, INT));
    printf("Dado inserido: %d\n", t->sentinel->nextL->info.i);

    info.i = 3;
    printf("Insert (INT): %d\n", Insert(t, &info, INT));
    printf("Dado inserido: %d\n", t->sentinel->nextL->nextL->info.i);

    info.i = 2;
    printf("Insert (INT): %d\n", Insert(t, &info, INT));
    printf("Dado inserido: %d\n", t->sentinel->nextL->nextL->nextL->info.i);

    info.i = 7;
    printf("Insert (INT): %d\n", Insert(t, &info, INT));
    printf("Dado inserido: %d\n", t->sentinel->nextL->nextR->info.i);

    info.i = 4;
    printf("Insert (INT): %d\n", Insert(t, &info, INT));
    printf("Dado inserido: %d\n\n", t->sentinel->nextL->nextL->nextR->info.i);

    printf("Imprindo a arvore:\n");
    PrintTree(t, INT);

    printf("\nAltura da arvore: %d\n", GetTreeHeight(t->sentinel));

    info.i = 3;
    printf("\nDeletando um dado (3): %d\n", Delete(t, &info, INT));

    printf("Imprindo a arvore:\n");
    PrintTree(t, INT);

    info.i = 4;
    printf("\nDeletando um dado (4): %d\n", Delete(t, &info, INT));

    printf("Imprindo a arvore:\n");
    PrintTree(t, INT);

    printf("\nDeletando a arvore...\n");
    DelTree(&t);

    printf("Imprindo a arvore:\n");
    PrintTree(t, INT);

    printf("\nInserindo novos dados...\n");
    info.i = 8;
    Insert(t, &info, INT);
    info.i = 10;
    Insert(t, &info, INT);
    info.i = 1;
    Insert(t, &info, INT);
    info.i = 3;
    Insert(t, &info, INT);
    info.i = 4;
    Insert(t, &info, INT);
    info.i = 5;
    Insert(t, &info, INT);

    printf("Imprindo a arvore:\n");
    PrintTree(t, INT);

/* Not Working Yet
    info.c = 'b';
    printf("Insert (CHAR): %d\n", Insert(t, &info, CHAR));
    printf("Dado inserido: %c\n", t->sentinel->nextR->info.c);
*/

    return 0;
}
