#ifndef STACK_H
#define STACK_H


typedef struct node {
    void * data;
    struct node * next;
} Node;


typedef struct stack {
    Node * top;
    int size;
    void (*printFunc)(void *);
} Stack;

Stack * stackCreate(void (*printFunc)(void *));

void stackPush(Stack * stack, void * data);

void * stackPop(Stack * stack);

void stackPrint(Stack * stack);

#endif