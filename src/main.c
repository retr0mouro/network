#include "command_parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char* conteudoTexto = malloc(textoSize * sizeof(char));
    if(!conteudoTexto){
        perror("Alocação de memória falhou");
        fclose(texto);
        return 1;
    }

    char* token = malloc(50 * sizeof(char));


    fread(conteudoTexto,textoSize,1,texto);

    //Deque deques;
    Cmd* cmds = malloc(sizeof(struct cmd));
    cmds->command = NULL;
    cmds->args = NULL;
    cmds->nargs = 0;

    while((token = __strtok_r(conteudoTexto,enter,&conteudoTexto))){
        char * transf = cmds->command;
        char* temp = malloc(100 * sizeof(char)); 
        transf = getCommand(cmds,token);
        printf("%s\n",token);
        //strcpy(transf,temp);
        printf("%sabc\n\n\n",cmds->command);
        free(temp);
        //processCommand(&deques,cmds);
    }

    //conteudoTexto = NULL;
    
    /*
        !!!!!!MEMORY LEAK!!!!!!
        FALTA FAZER FREE DO conteudoTexto!!!!!!!!
    */
    //free(conteudoTexto);



    free(cmds);
    free(token);

    fclose(texto);
    return 0;
}