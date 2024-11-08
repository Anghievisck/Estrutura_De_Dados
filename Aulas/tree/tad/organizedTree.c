#include "organizedTree.h"

#include <stdlib.h>
#include <stdio.h>

Node* FindPrevious(Tree*, Data*, enum DATA_TYPE dType);

Tree* Create(){
    Tree *t = (Tree *)malloc(sizeof(Tree));

    if(t != NULL){
        t->sentinel = (Node *)malloc(sizeof(Node));

        if(t->sentinel == NULL){
            free(t);
            return NULL;
        }

        t->sentinel->dataType = -1;
        t->sentinel->nextL = NULL;
        t->sentinel->nextR = NULL;

        return t;
    }

    return NULL;
}

int IsEmpty(Tree *t){
    return (t->sentinel->nextL == NULL && t->sentinel->nextR == NULL) ? 1 : 0;
}

int Insert(Tree *t, Data *d, enum DATA_TYPE dType){
    Node *temp = (Node*)malloc(sizeof(Node));

    if(temp == NULL){
        return 0;
    } else {
        if(Find(t, d, dType) != NULL){
            return -1;
        }

        temp->info = *d;
        temp->dataType = dType;

        temp->nextL = NULL;
        temp->nextR = NULL;

        if(IsEmpty(t)){
            if(dType == INT){
                t->sentinel->nextL = temp;
            } else {
                t->sentinel->nextR = temp;
            }
            return 1;
        } else {
            Node *aux, *sup;
            int direction;

            sup = t->sentinel;

            if(dType == INT){
                direction = 0;
                aux = t->sentinel->nextL;
            } else {
                direction = 1;
                aux = t->sentinel->nextR;
            }

            if(temp->dataType == INT){
                while(aux != NULL){
                    sup = aux;
                    if(aux->info.i > temp->info.i){
                        aux = aux->nextL;
                        direction = 0;
                    } else {
                        aux = aux->nextR;
                        direction = 1;
                    }
                }
            } else {
                while(aux != NULL){
                    sup = aux;
                    if(aux->info.c > temp->info.c){
                        aux = aux->nextL;
                        direction = 0;
                    } else {
                        aux = aux->nextR;
                        direction = 1;
                    }
                }
            }

            if(direction == 0){
                sup->nextL = temp;
            } else {
                sup->nextR = temp;
            }

            return 1;
        }
    }
}

Node* FindMin(Node *n){
    Node* aux = n;
    while(aux->nextL != NULL){
        aux = aux->nextL;
    }

    return aux;
}

int Delete(Tree *t, Data *d, enum DATA_TYPE dType){
    if(IsEmpty(t)){
        return 0;
    } else {
        Node *temp = Find(t, d, dType);

        if(temp == NULL){
            return 0;
        }

        Node *aux = FindPrevious(t, d, dType);
        Node *sup;

        if(aux == NULL){
            free(temp);
            temp = NULL;
        } else {
            if(temp->nextL == NULL && temp->nextR == NULL){
                if(aux->nextL == temp){
                    aux->nextL = NULL;
                } else {
                    aux->nextR = NULL;
                }

                free(temp);
                temp = NULL;
            } else {
                sup = FindMin(temp->nextR);
                aux = FindPrevious(t, &sup->info, sup->dataType);
                temp->info = sup->info;

                if(sup->nextR != NULL){
                    aux->nextL = sup->nextR;
                } else {
                    aux->nextL = NULL;
                }

                free(sup);
                sup = NULL;
            }
        }
    }

    return 1;
}

Node* Search(Node *aux, Data *d, enum DATA_TYPE dType){
    if(aux == NULL){
        return NULL;
    }

    if(dType == INT){
        if(aux->info.i == d->i){
            return aux;
        }

        return (aux->info.i > d->i) ? Search(aux->nextL, d, dType) : Search(aux->nextR, d, dType);
    } else {
        if(aux->info.c == d->c){
            return aux;
        }

        return (aux->info.c > d->c) ? Search(aux->nextL, d, dType) : Search(aux->nextR, d, dType);
    }
}

Node* SearchPrevious(Node *aux, Data *d, enum DATA_TYPE dType){
    if(aux == NULL){
        return NULL;
    }

    if(dType == INT){
        if(aux->nextL != NULL && aux->nextL->info.i == d->i){
            return aux;
        } else if(aux->nextR != NULL && aux->nextR->info.i == d->i){
            return aux;
        }

        return (aux->info.i > d->i) ? SearchPrevious(aux->nextL, d, dType) : SearchPrevious(aux->nextR, d, dType);
    } else {
        if(aux->nextR != NULL && aux->nextR->info.c == d->c){
            return aux;
        } else if(aux->nextL != NULL && aux->nextL->info.c == d->c){
            return aux;
        }

        return (aux->info.c > d->c) ? SearchPrevious(aux->nextL, d, dType) : SearchPrevious(aux->nextR, d, dType);
    }
}

Node* Find(Tree *t, Data *d, enum DATA_TYPE dType){
    if(IsEmpty(t)){
        return NULL;
    } else {
        return (dType == INT) ? Search(t->sentinel->nextL, d, dType) : Search(t->sentinel->nextR, d, dType);
    }
}

Node* FindPrevious(Tree *t, Data *d, enum DATA_TYPE dType){
    if(IsEmpty(t)){
        return NULL;
    } else if(dType == INT && t->sentinel->nextL != NULL){
        if(t->sentinel->nextL->info.i == d->i){
            return NULL;
        } else {
            return SearchPrevious(t->sentinel->nextL, d, dType);
        }
    } else if(dType == CHAR && t->sentinel->nextR != NULL){
        if(t->sentinel->nextR->info.c == d->c){
            return NULL;
        } else {
            return SearchPrevious(t->sentinel->nextR, d, dType);
        }
    } else {
        return NULL;
    }
}

void PrintTreeSup(Tree *t, Node *n, enum DATA_TYPE dType){
    if(n != NULL){
        if(dType == INT){
            PrintTreeSup(t, n->nextL, dType);
            PrintTreeSup(t, n->nextR, dType);

            Node *sup = FindPrevious(t, &n->info, dType);
            if(sup == NULL){
                printf("%d (NULL)\n", n->info.i);
            } else {
                printf("%d (%d)\n", n->info.i, sup->info.i);
            }
        } else {
            PrintTreeSup(t, n->nextL, dType);
            PrintTreeSup(t, n->nextR, dType);

            Node *sup = FindPrevious(t, &n->info, dType);
            printf("%c (%c)\n", n->info.c, sup->info.c);
        }
    }
}

void PrintTree(Tree *t, enum DATA_TYPE dType){
    if(IsEmpty(t)){
        return;
    }

    Node *n = (dType == INT) ? t->sentinel->nextL : t->sentinel->nextR;

    if(n != NULL){
        PrintTreeSup(t, n, dType);
    }
}
