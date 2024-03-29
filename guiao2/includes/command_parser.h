#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H
#include "deque.h"


//strsep(&string,char delimitador);

typedef struct cmd {
    char* command;
    int* args; //NULL se ñ houver argumentos
    int nargs; //número de argumentos
} Cmd;

void printInt(void *i);

Cmd * init();

void processCommand(Deque* deque, Cmd* cmd);

int getNargs(char* line);

void getArgs(Cmd * cmd,char* line);

void getCommand(Cmd * cmd,char * line);

Cmd parseLine(char* line);

void saveCmd(Cmd * dest,Cmd * src);

#endif
