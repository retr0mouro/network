#ifndef STACK_H
#define STACK_H

#include "node.h"

typedef struct stack {
    int size;
    Node* top;
    void (*elemPrint)(void *); 
} Stack;

#endif