#ifndef BALCAO_H
#define BALCAO_H 

#include "stack.h"
#include <time.h>

enum Servicos{
	CC,
	SS,
	GALP
};

typedef struct balcao
{
	unsigned int id;
	char * nome;
	char * local;
	struct tm horario1[2];
	struct cliente * listaClientes;
	struct stack waitline;
	enum Servicos servicos;
} Balcao;

#endif