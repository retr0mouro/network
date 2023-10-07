#ifndef DEQUE_H
#define DEQUE_H
#include "node.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct deque{
    Node * top;
    Node * bottom;
    size_t size;
} Deque;

Deque* create();

void push(Deque* deque, void* data);

void pushFront(Deque* deque, void* data);

void* pop(Deque* deque);

void* popFront(Deque* deque);

int size(Deque* deque);

bool isEmpty(Deque* deque);

void reverse(Deque* deque);

void printInt(void * data);

void printDeque(Deque* deque, void(*printFunc)(void*));

void destroy(Deque* deque);

#endif