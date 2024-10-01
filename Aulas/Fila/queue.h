#define LENGHT 1000

typedef int item;
typedef struct queue{
    item Queue[LENGHT];
    int start;
    int end;
    int total;
} Queue;

void CreateQ(Queue*);
void EmptyQ(Queue*);
void In(Queue*, item*, int*);
void Out(Queue*, item*, int*);
int IsEmptyQ(Queue*);
int IsFullQ(Queue*);

int GetLength(Queue*);