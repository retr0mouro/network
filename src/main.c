#include "command_parser.h"
#include "deque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 100

int main(int argc,char **argv){

    const char *enter = "\n";

    //Abrir a stream
    FILE* texto = fopen("commands.txt","r");
    if(!texto){
        perror("Erro");
        return 1;
    }    

    //Determinar o tamanho
    /*seek do ultimo caracter 
    referir a distancia do ultimo
    voltar ao inicio do texto*/
    fseek(texto,0,SEEK_END);
    long int textoSize = ftell(texto);
    rewind(texto);

    //alocar string
    char* conteudoTexto = malloc((textoSize + 1) * sizeof(char));
    
    if(!conteudoTexto){
        perror("Alocação de memória falhou");
        fclose(texto);
        return 1;
    }

    char* line = malloc(BUFFERSIZE * sizeof(char));
    char *saveptr = conteudoTexto;


    fread(conteudoTexto,textoSize,1,texto);
    conteudoTexto[textoSize] = '\0';

    //Deque deques;

    //Deque *deque = create();


    line = __strtok_r(conteudoTexto,enter,&saveptr);

    while(line){
        //***   token is a string   *** 
        Cmd *cmd = parseLine(line);
        for(int i = 0;i < cmd->nargs;i++){
            printf("%s:%d\n",cmd->command,cmd->args[i]);
        }
        free(cmd->args);
        free(cmd);
        if(!__strtok_r(NULL,enter,&saveptr)) break;
        line = __strtok_r(NULL,enter,&saveptr);
    }

    //printf("%s",line);
    
    //memset(conteudoTexto,'A',textoSize);
    //conteudoTexto[textoSize] = '\0'; 

    /*
        !!!!!!MEMORY LEAK!!!!!!
        FALTA FAZER FREE DO conteudoTexto!!!!!!!!
    */

    //destroy(deque);
    //free(line); 
    //free(conteudoTexto);
    

    fclose(texto);
    return 0;
}