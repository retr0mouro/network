#include "deque.h"

Deque* create(){
    Deque * new = malloc(sizeof(struct deque));
    new->top = new;
    new->top->next = NULL;
    new->bottom = NULL;
    new->bottom->next = NULL;
    return new;
}

void push(Deque* deque, void* data){
    Node * new = nodeCreate(data);
    new->next = NULL;
    deque->bottom = new;
}

void pushFront(Deque* deque, void* data){
    Node * new = nodeCreate(data);
    new->next = deque->top;
    deque->top = new->next;
}

void* pop(Deque* deque){
    if(deque == NULL) return;
    Node * temp = deque->top;
    Node answer;
    answer.data = deque->bottom->data;
    for(;temp->next != deque->bottom;temp = temp->next); 
    free(temp->next);
    return answer.data;
}

void* popFront(Deque* deque){
    
}
