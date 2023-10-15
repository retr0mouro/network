#include "stack.h"
#include "balcao.h"
#include <stdio.h>
#include <stdlib.h>

void printc(void * data){
    Cliente * info = NULL;
    info = (Cliente *) data;
    if(info) printf("%s , %d, %s\n",info->nome,info->cc,info->morada);
    else printf("\tNULO\n");
}

Stack * stackCreate(void (*printFunc)(void *)){
    Stack * stack = malloc(sizeof(struct stack));
    stack->top = NULL;
    stack->size = 0;
    stack->printFunc = *printc;
    return stack;
}

void stackPush(Stack * stack, void * data){
    Node * novo = malloc(sizeof(struct node));
    novo->data = data;
    novo->next = stack->top;
    stack->top = novo;
}

void * stackPop(Stack * stack){
    if(!stack) return NULL;
    void * answer = stack->top->data;
    Node * oldTop = stack->top;
    stack->top = stack->top->next;
    free(oldTop);
    stack->size--;
    return answer;
}

void stackPrint(Stack * stack){
    if(!stack) return;
    Node * topo = stack->top;
    putchar('[');
    while(stack->top){
        stack->printFunc(stack->top->data);
        printf(" -> ");
        stack->top = stack->top->next;
    }
    putchar(']');
    stack->top = topo;
}

void stackDestroy(Stack * stack){
    while(stack->size != 0){
        stackPop(stack);
    }
    free(stack);
}
