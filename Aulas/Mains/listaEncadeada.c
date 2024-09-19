#include <stdio.h>
#include "../TADs/ListaEncadeada/linkedList.h"

int main(){
    List *lista;
    lista = Create();

    int e;

    for(int i = 1; i < 4; i++){
        Insert(lista, &i, &e);

        printf("e: %d\n", e);
    }

    Invert(lista);

    printf("n: %d", lista->start->data);
}