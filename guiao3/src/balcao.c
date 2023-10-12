#include "balcao.h"


Cliente getCliente(Cliente * listaClientes, unsigned int cartao){
	Cliente * temp = listaClientes;
	for(int i = 0;&listaClientes[i];i++){
		if(listaClientes[i].cc == cartao) break;
		temp = &listaClientes[i];
	}
	return *temp;
}



Cliente * getListaClientes(Balcao * balcoes, unsigned int id){
	Balcao * temp = balcoes;
	for(int i = 0;&balcoes[i];i++){
		if(balcoes[i].id == id) break;
		temp = &balcoes[i];
	}
	return temp->listaClientes;
}

void addCliente(Stack * stack,unsigned int id,unsigned int cc,enum Servicos servicos){
	Cliente * novo = malloc(sizeof(struct cliente));
	
}