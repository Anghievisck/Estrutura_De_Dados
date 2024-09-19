typedef int type;
typedef struct node Node;
typedef struct list List;

List* Create();

Node* SelectItem(List*, type*);

void DelList(List*);
void DelItem(List*, type*, int*);

void Insert(List*, type*, int*);

int Length(List *);

void Invert(List*);

void PrintList(List*);