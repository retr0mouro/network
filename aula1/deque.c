#include "deque.h"
#include <stdlib.h>
#include <stdio.h>

//ok
Deque* create(){
    Deque * deque = malloc(sizeof(struct deque));
    deque->bottom = NULL;
    deque->top = NULL;
    return deque;
}
//ok
void push(Deque* deque, void* data){
    Node * novo = nodeCreate(data);
    if(!deque){
        novo = deque->top;
        novo = deque->bottom;
        novo->next = deque->bottom;
        novo->prev = NULL;
    }
    novo->prev = deque->bottom;
    if(deque->bottom != NULL){
        deque->bottom->next = novo;
    }
    deque->bottom = novo;
}
//ok
void pushFront(Deque* deque, void* data){
    Node * novo = malloc(sizeof(struct node));
    novo->data = data;
    novo->next = deque->top;
    novo->prev = NULL;
    deque->top = novo;
}
//ok
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

//OK
void* popFront(Deque* deque){
    if(deque == NULL || deque->top == NULL || deque->bottom == NULL) return NULL;
    void * erased = deque->top->data;
    Node * temp = deque->top;
    deque->top = deque->top->next;
    nodeFree(temp);
    return erased;
}


//ok
int size(Deque *deque){
    if(deque == NULL || deque->top == NULL) return 0;
    Node * temp = deque->top;
    int size = 1;
    for(;temp != deque->bottom;size++,temp = temp->next);
    return size;
}


//ok
bool isEmpty(Deque* deque){
    if(deque == NULL || deque->top == NULL || deque->bottom == NULL) return false;
    return true;
}

//Corrigir - ultimo elemento apagado por alguma razao
void reverse(Deque* deque) {
    if (deque == NULL || deque->top == NULL || deque->bottom == NULL) return;
    Node * current = deque->top;

    while(current){
        if(current->next == NULL){
            Node * n = current->prev;
            current->next = n;
            current->prev = NULL;

            break;

            //current = current->next;

        }
        if(current->prev == NULL){
            Node * p = current->next;
            current->prev = p;
            current->next = NULL;

            current = current->prev;
        }
        Node * p = current->next;
        Node * n = current->prev;
        current->prev = p;
        current->next = n;

        current = current->prev;
    }

    current = deque->top;

    deque->top = deque->bottom;
    deque->bottom = current;

    current = deque->bottom->prev;

    current->next = deque->bottom;
    /*printFunc(deque->top->data);
    printFunc(deque->top->next->data);
    putchar('\n');
    printFunc(deque->bottom->prev->data);
    printFunc(deque->bottom->data);*/
}

//ok
void printFunc(void * data){
    if(data == NULL) return;
    int * value = (int *) data;
    printf("%d\n",*value);
}

//ok
void printDeque(Deque* deque, void(*printFunc)(void*)){
    Node * current = deque->top;
    while(current){
        printFunc(current->data);
        current = current->next;
    }
}

//ok
void destroy(Deque* deque){
    Node * current = deque->top;
    Node * temp = NULL;
    while(current){
        temp = current->next;
        nodeFree(current);
        current = temp;
    }
    free(deque);
}
