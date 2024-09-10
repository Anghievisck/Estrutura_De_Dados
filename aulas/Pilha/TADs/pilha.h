#define LENGHT 1000

typedef int type;

typedef struct{
    type stack[LENGHT];
    int index;
} stack;

void Create(stack*);
void Empty(stack*);
void Pop(stack*, type*, int*);
void Push(stack*, type*, int*);
int IsEmpty(stack*);
int IsFull(stack*);
type Top(stack*, int*);