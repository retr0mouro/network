#include "deque.h"
//#include <stdio.h>

int main(){
	/*Node * uabo = nodeCreate((int*) 2);
	nodeFree(uabo);
	printf("Ao menos nao crashou\n");*/

	/*
	How printFunc() works
	int a = 2;
	void * data = &a;
	printFunc(data);
	*/
	

	int a = 1,b = 2,c = 3,d = 4;
	

	Deque * novo = create();
	
	novo->top = nodeCreate(&a);
	
	novo->bottom = nodeCreate(&b);
	
	novo->top->next = novo->bottom;
	
	
	//printDeque(novo,printFunc);
	
	push(novo,&c);

	push(novo,&d);

	push(novo,&d);

	//pop(novo);

	printDeque(novo,printFunc);
	

	printf("\n\n\n%d\n\n\n",size(novo));
	
	reverse(novo);

	//Node * temp = novo->top;
	
	/*printFunc(novo->bottom->prev->data);
	printFunc(novo->top->data);
	printFunc(novo->top->next->data);
	printFunc(novo->top->next->next->data);*/
	//printFunc(novo->top->next->next->next->data);
	
	printDeque(novo,printFunc);
	

	destroy(novo);
    return 0;
}