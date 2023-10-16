#include <stdio.h> 
#include <stdlib.h>
#include "balcao.h"
#include "stack.h"

int main(int argc, char **argv){

    Cliente database[5];

    Balcao balcao1;

    initClientes(database);
    initBalcoes(&balcao1,database);

    if(!balcao1.servicos.waitline) printf("Nao ha fila\n");

    addCliente(&balcao1,22340,12344,balcao1.servicos);
    
    printaBalcao(&balcao1);

    stackDestroy(balcao1.servicos.waitline);

    return 0;
}
