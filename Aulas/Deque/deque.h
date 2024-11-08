#ifndef DEQUE_H
#define DEQUE_H

typedef enum DataType {
    INTEGER,
    STRING,
    FLOAT,
    DOUBLE
} DataType;

typedef union Data {
    int integer;
    char string;
    float fvalue;
    double dvalue;
    void* ptr;
} Data;

typedef struct DequeNode {
    Data data;
    struct DequeNode *next, *prev;
    DataType type;
} DequeNode;

typedef struct Deque {
    DequeNode *head, *tail;
    size_t size;
    size_t capacity;
} Deque;

// Function declarations
Deque* CreateDeque(size_t initialCapacity);
void DestroyDeque(Deque* d);

int Append(Deque* d, Data* data);
int AppendLeft(Deque* d, Data* data);

int Pop(Deque* d, Data* result);
int PopLeft(Deque* d, Data* result);

size_t GetSize(const Deque* d);
size_t GetCapacity(const Deque* d);

#endif // DEQUE_H