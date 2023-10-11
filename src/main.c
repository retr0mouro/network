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

    char* line = NULL;
    char *saveptr = conteudoTexto;


    fread(conteudoTexto,textoSize,1,texto);
    conteudoTexto[textoSize] = '\0';

    //printf("%s",conteudoTexto);

    //Deque deques;

    Deque *deque = create();

    line = __strtok_r(conteudoTexto,enter,&saveptr);
        
    Cmd *cmd = NULL;

    int i = 0;

    while(line){
        //***   token is a string   *** 
        Cmd * cmds = NULL;

        cmds = parseLine(line);

        //if(cmd->nargs == 0) printf("%s\n", cmd->command);
        //else for(int i = 0;i < cmd->nargs;printf("%s : %d\n",cmd->command,cmd->args[i]),i++);

        saveCmd(&cmd[i],cmds);

        processCommand(deque,&cmd[i]);  
        
        i++;

        //printDeque(deque,printInt);
        line = __strtok_r(NULL,enter,&saveptr);

        free(cmds->command);
        free(cmds->args);
        free(cmd);
    }



    memset(conteudoTexto,'A',textoSize);
    conteudoTexto[textoSize] = '\0';
    
    
    for(;i > 0;i++){
        free((cmd[i]).command);
        free(cmd[i].args);
        free(cmd);
    }
    
    destroy(deque);
    
    free(conteudoTexto);
    fclose(texto);
    return 0;
}
    

    