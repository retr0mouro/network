#ifndef NODE_H
#define NODE_H


typedef struct node{
    void* data;
    struct node * next;
    struct node * previous;
} Node;

Node * nodeCreate(void* data);

void nodeFree(Node * node);

#endif
