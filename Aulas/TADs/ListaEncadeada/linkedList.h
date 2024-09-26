typedef int elem;
typedef struct node{
    elem data;
    struct node *next;
}Node;

typedef struct list{
    Node *start, *end;
}List;

typedef struct stack{
    Node *top;
}Stack;

// List:
List* L_Create();

Node* SelectNode(List*, elem*);
elem FindElementByID(List*, int, int*);
int IsInList(List*, elem*);

void L_Insert(List*, elem*, int*);

void DelItem(List*, elem*, int*);
void DelItemByID(List*, int, int*);

int L_Length(List*);
int LengthR(List*);

void L_Invert(List*);

void PrintList(List*);

void L_Delete(List*);

// Stack:
Stack* S_Create();

int S_IsEmpty(Stack*);

void S_Push(Stack*, elem*, int*);
void S_Pop(Stack*, elem*, int*);

void S_Delete(Stack*);

// Queue:
List* Q_Create();

void Q_Insert(List*, elem*, int*);
void Q_Pop(List*, elem*, int*);