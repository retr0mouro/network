#ifndef CLIENTE_H
#define CLIENTE_H 

#include <time.h>

typedef struct cliente
{
	unsigned int cc;
	char *nome;
	time_t data;
	char *morada;

} Cliente;

unsigned int getCC(Cliente * cliente);

#endif