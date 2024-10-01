#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main(){
    List *lista;
    elem n;

    lista = Create();

    int e;

    for(int i = 0; i < 6; i++){
        Insert(lista, &i, &e);

        if(e == 1){
            printf("Deu erro...\n");
            break;
        }
    }

    printf("Lista = ");
    PrintList(lista);

    printf("\n\nInvertendo lista...\n");
    Invert(lista);

    printf("Lista = ");
    PrintList(lista);

    n = FindElementByID(lista, 2, &e);

    if(e == 0){
        printf("\n\nn = %d\n", n);
    } else {
        printf("\nIndice maior que o tamanho da lista...");
    }

    printf("Apagando 'n'...\n");
    DelItem(lista, &n, &e);
    printf("Lista = ");
    PrintList(lista);

    printf("\n\nApagando o segundo elemento...\n");
    DelItemByID(lista, 1, &e);
    printf("Lista = ");
    PrintList(lista);

    printf("\n\nApagando o ultimo elemento...\n");
    DelItemByID(lista, Length(lista) - 1, &e);
    printf("Lista = ");
    PrintList(lista);

    printf("\n\nApagando o primeiro elemento...\n");
    DelItemByID(lista, 0, &e);
    printf("Lista = ");
    PrintList(lista);

    printf("\n\nDeletando lista...\n");
    DelList(lista);

    printf("Lista = ");
    PrintList(lista);
}