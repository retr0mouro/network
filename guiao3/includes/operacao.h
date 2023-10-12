#ifndef OPERACAO_H
#define OPERACAO_H

#include "cliente.h"
#include "stack.h"
#include "balcao.h"

Cliente getCliente(Cliente * listaClientes, unsigned int cc);

Cliente * getListaClientes(unsigned int id);

void addCliente(unsigned int id,unsigned int cc,enum Servicos servicos);

#endif