#include "deque.h"

Deque* create(){
    Deque * deque = malloc(sizeof(struct deque));
    deque->bottom = NULL;
    deque->top = NULL;
    return deque;
}

void push(Deque* deque, void* data){
    Node * novo = nodeCreate(data);
    novo->prev = deque->bottom;
    if(deque->bottom != NULL){
        deque->bottom->next = novo;
    }
    deque->bottom = novo;
}

void pushFront(Deque* deque, void* data){
    Node * novo = malloc(sizeof(struct node));
    novo->data = data;
    novo->next = deque->top;
    novo->prev = NULL;
    deque->top = novo;
}

void* pop(Deque* deque) {
    if (deque->bottom == NULL || deque->top == NULL) return NULL; // Return an appropriate error value or handle it as needed

    void* abort = deque->bottom->data;
    Node* temp = deque->bottom;

    if (deque->bottom == deque->top) {
        // If there's only one node in the deque, reset both top and bottom to NULL
        deque->bottom = deque->top = NULL;
    } else {
        deque->bottom = deque->bottom->prev;
        deque->bottom->next = NULL;
    }

    free(temp);
    return abort;
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

void reverse(Deque* deque) {
    if (deque == NULL || deque->top == NULL) return;
    Node* current = deque->top;

    deque->top = deque->bottom;
    deque->bottom = current;

    while(current){
        Node * p = current->next;
        Node * n = current->prev;
        current->next = n;
        current->prev = p;
        current = n;
    }

}


void printFunc(void * data){
    int * value = (int *) data;
    printf("%d\n",*value);
}

void printDeque(Deque* deque, void(*printFunc)(void*)){
    Node * current = deque->top;
    while(current){
        printFunc(current->data);
        current = current->next;
    }
}

void destroy(Deque* deque){
    Node * current = deque->top;
    Node * temp = NULL;
    while(current){
        temp = current->next;
        nodeFree(current);
        current = temp;
    }
}
