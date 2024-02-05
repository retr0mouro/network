#ifndef BALCAO_H
#define BALCAO_H 

#include "stack.h"
#include <time.h>


typedef struct cliente
{
	unsigned int cc;
	char *nome;
	struct tm date;
	char *morada;

} Cliente;

typedef struct servico{
	char* nome;
	struct stack waitline;
} Servico;

typedef struct balcao
{
	unsigned int id;
	char * nome;
	char * local;
	struct tm horario1[2];
	struct cliente * listaClientes;
	struct servico * servicos;
} Balcao;

void initClientes();

void initBalcoes();

Cliente getCliente(unsigned int cc);

Cliente * getListaClientes(unsigned int id);

void addCliente(unsigned int id,unsigned int cc,Servico servico);

Cliente * removeCliente(Stack * stack);

int prioridade80(Cliente * cliente);

#endif