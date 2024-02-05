	Operaçoes:
		*Consultar informação cliente (fornecer num de cc)
		*Consultar lista de clientes de um balcao (fornecer id)
		*Adicionar um cliente a uma fila de espera num balcao (fornecer id do balcao, num cc cliente, nome do serviço)
		*Num serviço, chamar/remover primeiro cliente da fila (fornecer id do balcao, nome do serviço)


	Cliente
		-num cartao cidadao
		-nome
		-data
		-morada

	Balcao
		-id
		-nome
		-localizaçao
		-horario atendimento
		-lista Clientes
		-fila de espera para cada serviço (prioridade +80 anos)
