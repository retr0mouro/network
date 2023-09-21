#include "deque.h"

Deque* create(){
    Deque * deque = malloc(sizeof(struct deque));
    deque->bottom = NULL;
    deque->top = NULL;
    return deque;
}

void push(Deque* deque, void* data){
    Node * novo = malloc(sizeof(struct node));
    novo->data = data;
    novo->prev = deque->bottom;
    novo->next = NULL;
    deque->bottom = novo;
}

void pushFront(Deque* deque, void* data){
    Node * novo = malloc(sizeof(struct node));
    novo->data = data;
    novo->next = deque->top;
    novo->prev = NULL;
    deque->top = novo;
}

void* pop(Deque* deque){
    if(deque == NULL) return;
    Node * temp = deque->top;
    Node answer;
    answer.data = deque->bottom->data;
    for(;temp != deque->bottom;temp = temp->next); 
    nodeFree(temp);
    return answer.data;
}

void* popFront(Deque* deque){
    if(deque == NULL || deque->top == NULL || deque->bottom == NULL) return NULL;
    void * erased = deque->top->data;
    deque->top = deque->top->next;
    nodeFree(deque->top->prev);
    return erased;
}

int size(Deque *deque){
    if(deque == NULL || deque->top == NULL) return 0;
    Node * temp = deque->top;
    int size = 1;
    for(;temp != deque->bottom;size++,temp = temp->next);
    return size;
}

bool isEmpty(Deque* deque){
    if(deque == NULL || deque->top == NULL || deque->bottom == NULL) return false;
    return true;
}

void reverse(Deque* deque){
    if(deque == NULL || deque->top == NULL) return;
    Node * current = deque->top;
    Node * temp = NULL;
    
    while(current){

        temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        current = temp;
    }
    temp = deque->bottom; 
    deque->top = deque->bottom;
    deque->bottom = temp;
}

void printFunc(){
    
}

void printDeque(Deque* deque, void(*printFunc)(void*)){
    
}

void destroy(Deque* deque){
    
}
