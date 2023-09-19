#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Node * nodeCreate(void* data){
    Node * novo = malloc(sizeof(struct node));
    novo->data = data;
    novo->next = NULL;
    novo->previous = NULL;
    return novo;
}

void nodeFree(Node * node){
    node->data = NULL;
    node->next = NULL;
    node->previous = NULL;
    free(node);
}
