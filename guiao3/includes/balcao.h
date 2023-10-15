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

void initClientes(Cliente * database);

void initBalcoes(Balcao * balcao1, Cliente * database);

Cliente getCliente(Cliente * database, unsigned int cc);

Cliente * getListaClientes(Balcao * balcao1,unsigned int id);

void addCliente(Balcao * balcao1, unsigned int id,unsigned int cc,Servico servico);

Cliente * removeCliente(Stack * stack);

int prioridade80(Cliente * cliente);

void printaBalcao(Balcao * balcao1);

#endif
