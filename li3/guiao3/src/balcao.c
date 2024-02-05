#include "balcao.h"
#include <stdlib.h>
#include <string.h>

static Cliente database[5];

static Balcao balcao1;

void initClientes(){
	database[0].nome = "Jipow";
	database[0].cc = 12340;
	database[0].date.tm_year = 20;
	database[0].morada = "Rua 1"; 

	database[1].nome = "Ferrero";
	database[1].cc = 12341;
	database[1].date.tm_year = 20;
	database[1].morada = "Rua 2"; 

	database[2].nome = "QJM";
	database[2].cc = 12343;
	database[2].date.tm_year = 20;
	database[2].morada = "Rua 3"; 

	database[3].nome = "Narps";
	database[3].cc = 12344;
	database[3].date.tm_year = 20;
	database[3].morada = "Rua 4"; 

	database[4].nome = "Suci";
	database[4].cc = 12345;
	database[4].date.tm_year = 20;
	database[4].morada = "Rua 5"; 
}

void initBalcoes(){
	balcao1.nome = "01";
	balcao1.id = 22340;
	balcao1.local = "Braga";
	balcao1.horario1[0].tm_hour = 9; 
	balcao1.horario1[1].tm_hour = 17; 
	balcao1.listaClientes = NULL;
	balcao1.servicos = NULL;
}

Cliente getCliente(unsigned int cartao){
	for(int i = 0;i < 5;i++){
		if(database[i].cc == cartao) return database[i];
	}
}

Cliente * getListaClientes(unsigned int id){
	if(balcao1.id == id) return balcao1.listaClientes;
}

void addCliente(unsigned int id,unsigned int cc,Servico servico){
	if(balcao1.id == id){
		if(!balcao1.servicos){
			balcao1.servicos = malloc(sizeof(struct servico));
			balcao1.servicos->nome = malloc(sizeof(char) * strlen(servico.nome));
			strcpy(balcao1.servicos->nome,servico.nome);
			balcao1.servicos->waitline.top = NULL;
		}
		if(!strcmp(balcao1.servicos->nome,servico.nome)){
			Cliente * novo = malloc(sizeof(struct cliente));
			*novo = getCliente(cc);
			stackPush(&balcao1.servicos->waitline,&novo);
		}
	}
}

Cliente * removeCliente(Stack * stack){
	return (Cliente *) (stackPop(stack));
}

int prioridade80(Cliente * cliente){
		return cliente->date.tm_year >= 80;
}