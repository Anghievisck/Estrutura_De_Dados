#include "deque.h"
#include <stdlib.h>
#include <string.h>

// Helper function to create a new node
static DequeNode* create_node(Data* data, DataType type) {
    DequeNode* node = malloc(sizeof(DequeNode));
    if (!node) return NULL;
    memcpy(&node->data, data, sizeof(Data));
    node->type = type;
    node->next = node->prev = NULL;
    return node;
}

// Create a new deque
Deque* CreateDeque(size_t initialCapacity) {
    Deque* d = malloc(sizeof(Deque));
    if (!d) return NULL;
    d->head = d->tail = NULL;
    d->size = 0;
    d->capacity = initialCapacity;
    return d;
}

// Destroy the deque and free all resources
void DestroyDeque(Deque* d) {
    if (!d) return;
    DequeNode* current = d->head;
    while (current) {
        DequeNode* next = current->next;
        free(current);
        current = next;
    }
    free(d);
}

// Append an element to the right end of the deque
int Append(Deque* d, Data* data) {
    if (!d || !data) return -1;
    DequeNode* node = create_node(data, INTEGER); // Assume INTEGER type for simplicity
    if (!node) return -1;
    
    if (d->size == 0) {
        d->head = d->tail = node;
    } else {
        d->tail->next = node;
        node->prev = d->tail;
        d->tail = node;
    }
    d->size++;
    return 0;
}

// Append an element to the left end of the deque
int AppendLeft(Deque* d, Data* data) {
    if (!d || !data) return -1;
    DequeNode* node = create_node(data, INTEGER); // Assume INTEGER type for simplicity
    if (!node) return -1;
    
    if (d->size == 0) {
        d->head = d->tail = node;
    } else {
        node->next = d->head;
        d->head->prev = node;
        d->head = node;
    }
    d->size++;
    return 0;
}

// Pop an element from the right end of the deque
int Pop(Deque* d, Data* result) {
    if (!d || !result || d->size == 0) return -1;
    *result = d->tail->data;
    DequeNode* temp = d->tail;
    if (d->size == 1) {
        d->head = d->tail = NULL;
    } else {
        d->tail = d->tail->prev;
        d->tail->next = NULL;
    }
    free(temp);
    d->size--;
    return 0;
}

// Pop an element from the left end of the deque
int PopLeft(Deque* d, Data* result) {
    if (!d || !result || d->size == 0) return -1;
    *result = d->head->data;
    DequeNode* temp = d->head;
    if (d->size == 1) {
        d->head = d->tail = NULL;
    } else {
        d->head = d->head->next;
        d->head->prev = NULL;
    }
    free(temp);
    d->size--;
    return 0;
}

// Get the size of the deque
size_t GetSize(const Deque* d) {
    return d ? d->size : 0;
}

// Get the capacity of the deque
size_t GetCapacity(const Deque* d) {
    return d ? d->capacity : 0;
}