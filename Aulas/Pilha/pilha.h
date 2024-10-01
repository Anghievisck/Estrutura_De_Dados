#define LENGHT 1000

typedef int type;

typedef struct {
    type stack[LENGHT];
    int index;
} Stack;

void CreateS(Stack*);
void EmptyS(Stack*);
void Pop(Stack*, type*, int*);
void Push(Stack*, type*, int*);
int IsEmptyS(Stack*);
int IsFullS(Stack*);
type Top(Stack*, int*);