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
	if(cmd->command == "PUSH"){
		for(int i = 0;i < cmd->nargs;push(deque,&cmd->args[i]),i++);
		return;
	}
	if(cmd->command == "PUSH_FRONT"){
		for(int i = 0;i < cmd->nargs;pushFront(deque,&cmd->args[i]),i++);
		return;
	}
	if(cmd->command == "POP"){
		if(!deque){
			printf("EMPTY");
			return;
		}
		printFunc(pop(deque));
		return;
 	}
 	if(cmd->command == "POP_FRONT"){
 		if(!deque){
 			printf("EMPTY");
 			return;
 		}
 		printFunc(popFront(deque));
 		return;
 	}
 	if(cmd->command == "SIZE"){
 		printf("%d",size(deque));
 		return;
 	}
 	if(cmd->command == "REVERSE"){
 		reverse(deque);
 		return;
 	}
 	if(cmd->command == "PRINT"){
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
	//line ja so tem numeros
	const char * enter = "\n";
	const char * espaco = " ";
	char * numero;
	for(int i = 0;i < cmd->nargs;i++){
		if(i == cmd->nargs - 1){
			numero = __strtok_r(line,enter,&numero);
			cmd->args[i] = atoi(numero);
			break;
		}
		numero = __strtok_r(line,espaco,&numero);
		cmd->args[i] = atoi(numero);
	}
}

void getCommand(Cmd * cmd,char * line){
	const char * espaco = " ";
	char token[50];
	int i = 0;
	for(;line[i] >= 'A' && line[i] <= 'Z';token[i] = line[i],i++);
	if(line[i] != '\n' && line[i] != ' ');
	token[i] = '\0';
	for(int j = 0;j < i;j++){
		cmd->command[j] = token[j];
	}
	return;
}

Cmd* parseLine(char* line){
	if(!line) return NULL;
	Cmd* comando = malloc(sizeof(struct cmd));
	if(!comando) return NULL;
	comando->nargs = getNargs(line);
	getCommand(comando,line);
	if(comando->nargs == 0){
		comando->args = NULL;
		return comando;
	}
	getArgs(comando,line);
	return comando;
}
