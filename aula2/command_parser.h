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

void processCommand(Deque* deque, Cmd* cmd);

Cmd* parseLine(char* line);

#endif
