#include "command_parser.h"

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

Cmd* parseLine(char* line){
    if(!line) return NULL;
    Cmd* comando = malloc(sizeof(struct cmd));
    char* safe = strcpy(safe,line);
    char* cmd = strsep(&line," ");

}
