#include "command_parser.h"
#include "deque.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFERSIZE 100

/*
    testes:
        11/11/2023
        15/2/2024

    quando crasha :

    1    ulimit -c unlimited

    2    gcc -Wall -g

    3    dgb (|-> where)

*/

void printInt(void* i) {
    int* i_ = NULL;
	i_ = i;
   	if(i_) printf("%d\n", *i_);
	else printf("\tNULO\n\n");
}


Cmd* init(){
	Cmd * cmd = malloc(sizeof(struct cmd));
	return cmd;
}

void processCommand(Deque* deque, Cmd* cmd){
	if(!cmd) return;
	if(!deque){
		deque = create();
	}
	//printf("%s : %ld\n",cmd->command,strlen(cmd->command));
	if(!strcmp(cmd->command,"PUSH")){
		for(int i = 0;i < cmd->nargs;push(deque,&(cmd->args[i])),i++);
		return;
	}
	else if(!strcmp(cmd->command,"PUSH_FRONT")){
		for(int i = 0;i < cmd->nargs;pushFront(deque,&(cmd->args[i])),i++);
		return;
	}
	else if(!strcmp(cmd->command,"POP")){
		if(deque->last){
			printf("EMPTY\n");
			return;
		}
		printInt(pop(deque));
		return;
 	}
 	else if(!strcmp(cmd->command,"POP_FRONT")){
 		if(deque->first){
 			printf("EMPTY\n");
 			return;
 		}
 		printInt(popFront(deque));
 		return;
 	}
 	else if(!strcmp(cmd->command,"SIZE")){
 		printf("%d",size(deque));
 		return;
 	}
 	else if(!strcmp(cmd->command,"REVERSE")){
 		reverse(deque);
 		return;
 	}
 	else if(strcmp(cmd->command,"PRINT") == 0){
 		printDeque(deque,&printInt);
 		return;
 	}
	
}




int getNargs(char* line){
	int spaces = 0;
	for(int i = 0;line[i] != '\0' && line[i] != '\n';i++){
		if(line[i] == ' ') spaces++;
	}
	return spaces;
}




void getArgs(Cmd * cmd,char* line){
	// ** cmd already has nargs ** 
	const char * espaco = " ";
	char * safe = malloc(sizeof(char) * BUFFERSIZE);
	if(!safe) return;
	strcpy(safe,line);
	char * token = NULL;
	char * saveptr;
	token = __strtok_r(safe,espaco,&saveptr);
	int i = 0;
	if(cmd->nargs == 0){
		free(safe);
		return;
	}
	cmd->args = malloc(sizeof(int) * cmd->nargs);
	if(!cmd->args){
		free(safe);
		return;
	}
	for(;i < cmd->nargs;i++){
		token = __strtok_r(NULL,espaco,&saveptr);
		int n = atoi(token);
		cmd->args[i] = n;
	}
	free(safe);
}

void getCommand(Cmd * cmd,char * line){
	const char * espaco = " ";
	char *safe = malloc(sizeof(char) * BUFFERSIZE);
	if(!safe) return;
	strcpy(safe,line);
	char* saveptr;
	char* token = __strtok_r(safe,espaco,&saveptr);
	if(cmd->command) strcpy(cmd->command,token);
	else {
		cmd->command = malloc(sizeof(char) * strlen(token) + 1);
		strcpy(cmd->command,token);
	}
	free(safe);
}

Cmd * parseLine(char* line){
	Cmd * cmd = init();
	getCommand(cmd,line);
	cmd->nargs = getNargs(line);
	getArgs(cmd,line);
	return cmd;
}

void saveCmd(Cmd * dest,Cmd * src){
	if(!src) return;
	if(!dest) dest = init();
	dest->nargs = src->nargs;
	dest->command = malloc(sizeof(char) * strlen(src->command));
	strcpy(dest->command,src->command);
	if(dest->nargs != 0){
		dest->args = malloc(sizeof(int) * src->nargs);
		for(int i = 0; i < dest->nargs;i++){
			dest->args[i] = src->args[i];
		}
	}
}