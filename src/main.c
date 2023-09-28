#include "command_parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv){
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

    char* token;


    fread(conteudoTexto,textoSize,1,texto);

    Deque deques;
    Cmd* cmds;

    while((token = __strtok_r(conteudoTexto,"\n",&conteudoTexto))){
        cmds = parseLine(token);
        //processCommand(&deques,cmds);
    }

    conteudoTexto = NULL;
    free(conteudoTexto);

    fclose(texto);
    return 0;
}