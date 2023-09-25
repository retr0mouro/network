#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H
#include "aula1/deque.h"
#include <string.h>


//strsep(&string,char delimitador);

typedef struct cmd {
    char* command;
    int* args; //NULL se ñ houver argumentos
    int nargs; //número de argumentos
} Cmd;

void processCommand(Deque* deque, Cmd* cmd){
	if(cmd->command == "PUSH"){
		for(int i = 0;i < cmd->nargs;push(deque,args[i]),i++);
		return;
	}
	if(cmd->command == "PUSH_FRONT"){
		for(int i = 0;i < cmd->nargs;pushFront(deque,args[i]),i++);
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
 	if(cmd->command = "POP_FRONT"){
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

Cmd* parseLine(char* line);

#endif