#define LENGHT 1000

typedef int type;

typedef struct {
    type stack[LENGHT];
    int index;
} Stack;

void Create(Stack*);
void Empty(Stack*);
void Pop(Stack*, type*, int*);
void Push(Stack*, type*, int*);
int IsEmpty(Stack*);
int IsFull(Stack*);
type Top(Stack*, int*);