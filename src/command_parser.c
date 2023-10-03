#include "command_parser.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
    testes:
        11/11/2023
        15/2/2024

    quando crasha :

    1    ulimit -c unlimited

    2    gcc -Wall -g

    3    dgb (|-> where)

*/



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
	//const char * espaco = " ";
	int * transf = cmd->args;
	char *token = malloc(sizeof(char)*50);
	if(!token) return;
	token = __strtok_r(line,"\n",&token);
	int i = 0;
	for(;i < cmd->nargs - 1;i++){
		token = __strtok_r(token," ",&token);
		int tmp = atoi(token);
		printf("%d",tmp);
		transf[i] = tmp;
	}
	//i++;
	//token = __strtok_r(token,"\n",&token);
	//int temp = atoi(token);
	//cmd->args[i] = temp;
}

char* getCommand(Cmd * cmd,char * line){
	const char * espaco = " ";
	char *token = malloc(100*sizeof(char));
	memset(token,'\0',100);
	int i = 0;
	for(;(line[i] >= 'A' && line[i] <= 'Z') || line[i] == '_';token[i] = line[i],i++);
	if(line[i] != '\n' && line[i] != ' ');
	token[i] = '\0';
	cmd->command = token;
	
	//strcpy(cmd->command,token);
	return token;
}

Cmd* parseLine(char* line){
	if(!line) return NULL;
	Cmd* comando = malloc(sizeof(struct cmd));
	if(!comando) return NULL;
	char *safe = malloc(sizeof(char) * 100);
	strcpy(safe,line);
	comando->nargs = getNargs(line);
	getCommand(comando,line);
	if(comando->nargs == 0){
		comando->args = NULL;
		return comando;
	}
	printf("%s\n\n",line);
	printf("%s\n\n",safe);
	//getArgs(comando,safe);
	free(safe);
	return comando;
}
