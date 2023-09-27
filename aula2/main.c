#include "aula2/command_parser.h"
#include <stdio.h>

int main(int argc,char **argv){
    FILE* texto = fopen("commands.txt","r");
    if(!texto){
        perror("Erro");
        return 1;
    }    

    

    fclose(texto);
    return 0;
}