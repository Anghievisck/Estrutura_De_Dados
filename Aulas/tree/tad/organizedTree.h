typedef enum DATA_TYPE{
    INT,
    CHAR
};

typedef union data{
    int i;
    char c;
}Data;

typedef struct node{
    Data info;
    enum DATA_TYPE dataType;

    struct node *nextL, *nextR;
}Node;

typedef struct{
    Node *sentinel;
}Tree;

Tree* Create();
int IsEmpty(Tree*);

// Returns 0 if something went wrong, 1 if it works and -1 if it was already in the Tree
int Insert(Tree*, Data*, enum DATA_TYPE);
int Delete(Tree*, Data*, enum DATA_TYPE);

Node* Find(Tree*, Data*, enum DATA_TYPE);
void PrintTree(Tree*, enum DATA_TYPE);
