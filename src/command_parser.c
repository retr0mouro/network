#include "command_parser.h"
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

void init(Cmd *cmd){
	cmd->command = NULL;
	cmd->args = NULL;
	cmd->nargs = 0;
}

void processCommand(Deque* deque, Cmd* cmd){
	if(!strcmp(cmd->command,"PUSH")){
		for(int i = 0;i < cmd->nargs;push(deque,&cmd->args[i]),i++);
		return;
	}
	if(!strcmp(cmd->command,"PUSH_FRONT")){
		for(int i = 0;i < cmd->nargs;pushFront(deque,&cmd->args[i]),i++);
		return;
	}
	if(!strcmp(cmd->command,"POP")){
		if(!deque){
			printf("EMPTY");
			return;
		}
		printFunc(pop(deque));
		return;
 	}
 	if(!strcmp(cmd->command,"POP_FRONT")){
 		if(!deque){
 			printf("EMPTY");
 			return;
 		}
 		printFunc(popFront(deque));
 		return;
 	}
 	if(!strcmp(cmd->command,"SIZE")){
 		printf("%d",size(deque));
 		return;
 	}
 	if(!strcmp(cmd->command,"REVERSE")){
 		reverse(deque);
 		return;
 	}
 	if(!strcmp(cmd->command,"PRINT")){
 		printDeque(deque,printFunc);
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
	char * safe = malloc(sizeof(char) * strlen(line));
	strcpy(safe,line);
	char * token = NULL;
	char * saveptr;
	token = __strtok_r(safe,espaco,&saveptr);
	//if(cmd->nargs != 0) printf("+++++++++++++\n%s\n+++++++++++",token);
	int i = 0;
	if(cmd->nargs == 0) return;
	cmd->args = malloc(sizeof(int) * cmd->nargs);
	if(!cmd->args) return;
	for(;i < cmd->nargs;i++){
		token = __strtok_r(NULL,espaco,&saveptr);
		//printf("%s\n",token);
		int n = atoi(token);
		cmd->args[i] = n;
	}
	printf("\n\n\n");
}

char* getCommand(Cmd * cmd,char * line){
	const char * espaco = " ";
	char *safe = malloc(sizeof(char) * BUFFERSIZE);
	strcpy(safe,line);
	char* saveptr;
	char* token = __strtok_r(safe,espaco,&saveptr);
	//printf("\n\n%s\n\n",token);
	return token;
}

Cmd* parseLine(char* line){
	//if(!line) return NULL;
	Cmd * cmd = malloc(sizeof(struct cmd));
	init(cmd);
	char *transf = malloc(sizeof(char) * BUFFERSIZE);
	//memset(transf,'\0',BUFFERSIZE);
	transf = getCommand(cmd,line);
	cmd->command = transf;
	//printf("%s\n",cmd->command);
	cmd->nargs = getNargs(line);
	getArgs(cmd,line);
	free(transf);
	return cmd;
}
