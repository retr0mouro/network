#ifndef BALCAO_H
#define BALCAO_H 

#include "stack.h"
#include <time.h>

typedef struct cliente
{
	unsigned int cc;
	char *nome;
	time_t data;
	char *morada;

} Cliente;

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


Cliente getCliente(Cliente * listaClientes, unsigned int cc);

Cliente * getListaClientes(unsigned int id);

void addCliente(Stack * stack,unsigned int id,unsigned int cc,enum Servicos servicos);

Cliente * removeCliente(Stack * stack);

int * prioridade80(Stack * stack);

#endif