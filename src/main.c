#include "aula2/command_parser.h"
#include <stdio.h>


int main(int argc,char **argv){
    FILE* texto = fopen("commands.txt","r");
    if(!texto){
        perror("Erro");
        return 1;
    }    

    char* line = malloc(150*sizeof(char));
    line = fgets(line,150,texto);
    if(!line){
        perror("nulo");
        return 1;
    }
    printf("%s",line);

    fclose(texto);
    line = NULL;
    free(line);
    return 0;
}