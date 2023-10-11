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
        perror("Alocação de memória falhou\n");
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
        
    Cmd *cmd = malloc(sizeof(struct cmd) * BUFFERSIZE);
    if(!cmd){
        perror("Alocação comando falhou\n");
        destroy(deque);
        free(conteudoTexto);
        fclose(texto);
        return 1;
    }

    int i = 0;

    while(line){
        //if(!&cmd[i]) cmd = realloc(cmd,) 
        cmd[i] = parseLine(line);
        if(cmd[i].nargs != 0) for(int j = 0; j < cmd[i].nargs;printf("\n%s : %d\n", cmd[i].command, cmd[i].args[j]),j++);
        else printf("%s\n",cmd[i].command);
        i++;
        line = __strtok_r(NULL,enter,&saveptr);
    }
        
    
    for(int j = 0;j < i;j++){
        free(cmd[j].command);
        if(cmd[j].nargs != 0) free(cmd[j].args);
    }
    free(cmd);


    destroy(deque);
    
    free(conteudoTexto);
    fclose(texto);
    return 0;
}
    

    