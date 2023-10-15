#include <stdio.h> 
#include <stdlib.h>
#include "balcao.h"
#include "stack.h"

int main(int argc, char **argv){

    Cliente database[5];

    Balcao balcao1;

    initClientes(database);
    initBalcoes(&balcao1,database);


    printaBalcao(&balcao1);



    return 0;
}
