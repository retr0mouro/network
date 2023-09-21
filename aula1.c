#include "deque.h"
#include <stdio.h>

int main(){
	/*Node * uabo = nodeCreate((int*) 2);
	nodeFree(uabo);
	printf("Ao menos nao crashou\n");*/
	Deque * novo = create();
	novo->top = nodeCreate((int*) 1);
	novo->bottom = nodeCreate((int*) 2);
	novo->top->next = novo->bottom;
	push(novo,(int*) 4);
	printf("%d\n",size(novo));
	destroy(novo);
    return 0;
}