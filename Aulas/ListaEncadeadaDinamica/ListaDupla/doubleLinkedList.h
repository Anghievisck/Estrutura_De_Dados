#include <stdlib.h>

typedef struct node{
    char name[50];
    struct Node *previous, *next;
} Node;

typedef struct{
    Node *start, *end;
} List;

List* Create();
void Insert(List*, char*, int*, int*);