#define LENGHT 1000

typedef int item;
typedef struct queue{
    item Queue[LENGHT];
    int start;
    int end;
    int total;
} Queue;

void Create(Queue*);
void Empty(Queue*);
void In(Queue*, item*, int*);
void Out(Queue*, item*, int*);
int IsEmpty(Queue*);
int IsFull(Queue*);

int GetTotal(Queue*);