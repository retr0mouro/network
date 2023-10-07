#include "deque.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

// Allocates memory for the deque and returns it's address
Deque* create(){
    Deque * deque = malloc(sizeof(struct deque));
    deque->bottom = NULL;
    deque->top = NULL;
    deque->size = 0;
    return deque;
}


// Adds a value as the last position in the deque
void push(Deque* deque, void* data){
    Node* new = malloc(sizeof(struct node));
    new->data = data;
    new->prev = deque->bottom;
    new->next = NULL;
    deque->bottom = new;
    /* if it was empty before, also set the first pointer */
    if (deque->size == 0) {
        deque->top = new;
    } 
    /* otherwise update the previous last */
    else {
        new->prev->next = new;
    }
    deque->size++;
}


// Adds a value as the first position in the deque
void pushFront(Deque* deque, void* data){
    Node * new = malloc(sizeof(struct node));
    new->data = data;
    new->next = deque->top;
    new->prev = NULL;
    deque->top = new;
    /* if it was empty before, also set the last pointer */
    if (deque->size == 0) {
        deque->bottom = new;
    } 
    /* otherwise update the previous last */
    else {
        new->next->prev = new;
    }
    deque->size++;
}


// Removes the last element, which will be the return value
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
    deque->size--;
    return abort;
}

// Returns the first element of deque, which will be deleted from deque and freed
void* popFront(Deque* deque){
    if(deque == NULL || deque->top == NULL || deque->bottom == NULL) return NULL;
    void * erased = deque->top->data;
    Node * temp = deque->top;
    deque->top = deque->top->next;
    nodeFree(temp);
    deque->size--;
    return erased;
}


// Counts the size -> IMPROVE NEEDED
int size(Deque *deque){
    return deque->size;
}


// Checks if deque is allocated
bool isEmpty(Deque* deque){
    if(deque == NULL || deque->size == 0) return false;
    return true;
}

// Reverses the deque
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

// Casts data as int* and prints the value
void printInt(void* i) {
    int* i_ = i;
    printf("%d", *i_);
}

// Prints all values in deque, using printFunc() function
void printDeque(Deque* deque, void(*printFunc)(void*)){
    if(!deque){
        printf("[]");
        return;
    }
    Node * current = deque->top;
    putchar('[');
    while(current){
        printFunc(current->data);
        current = current->next;
        if(current != NULL) printf(" -> ");
    }
    printf("]\n\n");
}

// Free's every node of the deque, ultimatly freeing the deque
void destroy(Deque* deque){
    Node * current = deque->top;
    Node * temp = NULL;
    while(current){
        temp = current->next;
        nodeFree(current);
        current = temp;
        deque->size--;
    }
    free(deque);
}
