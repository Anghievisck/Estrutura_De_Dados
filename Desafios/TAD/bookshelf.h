#include "../../Aulas/TADs/Fila/queue.h"

#define LENGHT 1000

typedef struct book{
    char name[126];
    int avaiable;
    queue waitingList;
} book;

void NewBook(book*, char[256]);
void DeleteBook(book*);
void RequestBook(book*);
void ChangeAvailability(book*);
void ShowQueue(book*);

int IsAvaiable(book*);