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
    Node temp = *(deque->top);
    Node answer;
    answer.data = deque->bottom->data;
    for(;temp.next != deque->bottom;temp = *(temp.next)); 
    free(temp.next);
    return answer.data;
}

void* popFront(Deque* deque){
    if(deque == NULL) return NULL;
    Node temp = *(deque->top);
    deque->top = deque->top->next;
    temp.next = NULL;
    return temp.data;
}

int size(Deque *deque){
    if(deque == NULL || deque->top == NULL) return 0;
    Node temp = *(deque->top);
    int size = 1;
    for(;temp.next != deque->bottom;size++,temp = *(temp.next));
    return size + 1;
}

bool isEmpty(Deque* deque){
    if(deque == NULL || deque->top == NULL) return false;
    return true;
}

void reverse(Deque* deque){
    if(deque == NULL || deque->top == NULL) return;
    Node * current = deque->top;
    Node temp = NULL;
    
    while(current){

        temp = current->next;
        current->next = current->previous;
        current->previous = temp;

        current = temp;
    }
    temp = deque->bottom;
    deque->top = deque->bottom;
    deque->bottom = deque->top;
}

void printDeque(Deque* deque, void(*printFunc)(void*)){
    
}

void destroy(Deque* deque){
    
}
