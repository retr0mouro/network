/*

	* Definição dos conjuntos standard, demanda e residual *

	S = {7,10,11};
	D = {2,3,4,5};
	R = {2,3,4,5,6,7,8,9}
	

	* Definição das quantidades dos elementos do conjunto demanda *
	
	N2 = 13
	N3 = 10
	N4 = 11 
	N5 = 5
	
*/

/* Função objetivo 	(1)*/

min: 	7 y74 + 7 y75 + 								// Soma dos produtos dos custos unitários dos cortes de pecas de tamanho 7 com o número de cortes do mesmo tipo 
		10 y102 + 3 y103 + 10 y104 + 10 y105 + 			// Soma dos produtos dos custos unitários dos cortes de pecas de tamanho 10 com o número de cortes do mesmo tipo
		11 y112 - 7 y92 + 11 y113 + 4 y114 + 11 y115;	// Soma dos produtos dos custos unitários dos cortes de pecas de tamanho 11 com o número de cortes do mesmo tipo


/* Restrições relativamente à contagem de items colocados sobre a (2.1)*/

y74 - y32 >= 0; 					// Todos os cortes para comprimento 4 com resíduo de 3 apartir de um standard subtraindo todos os cortes dos resíduos 3  
y105 - y53 - y54 >= 0; 				// O número de cortes com comprimento 5 devem ser obtidos apartir de um comprimento standard, ou seja retiram-se os cortes sobre resíduos de tamanho 5 
y104 + y115 - y65 - y64 - y63 >= 0; // O número de cortes com comprimento 6 devem ser obtidos apartir de um comprimento standard, ou seja retiram-se os cortes sobre resíduos de tamanho 6 
y102 + y113 - y85 - y84 - y82 >= 0; // O número de cortes com comprimento 8 devem ser obtidos apartir de um comprimento standard, ou seja retiram-se os cortes sobre resíduos de tamanho 8 
y112 - y95 - y93 - y92 >= 0;		// O número de cortes com comprimento 9 devem ser obtidos apartir de um comprimento standard, ou seja retiram-se os cortes sobre resíduos de tamanho 9 
y84 + y95 - y43 - y42 >= 0;			// O número de cortes com comprimento 4 devem ser obtidos apartir de um comprimento standard, ou seja retiram-se os cortes sobre resíduos de tamanho 4 








/* Restrições relativamente à quantidade de contentores (2.2) */


y74 + y75 - y103 - y114 <= 4; 	// O número de contentores de tamanho 7 não deve exceder 4 (exceptua-se os casos em que 7 é resíduo)
y105 + y104 + y103 + y102 <= 5; // O número de contentores de tamanho 10 não deve exceder 5 (não ha casos a exceptuar)

// Cortes apartir de comprimento standard 11 são ilimitados





/* Restrições relativamente a quantidade de pedidos (2.3) */

y32 + 2 y42 + y53 + y64 + y75 + y82 + y92 + y102 + y112 = 13;		// Soma de todos os cortes que satisfazem o pedido de tamanho 2, excepto os resíduos que seram cortados com tamanho 2

y43 + y53 + 2 y63 + y74+ y85 + y93 + y103 + y113 - y32 = 10;		// Soma de todos os cortes que satisfazem o pedido de tamanho 3, excepto os resíduos que seram cortados com tamanho 3

y54 + y64 + y74 + 2 y84 + y95 + y104 + y114 - y43 - y42 = 11;		// Soma de todos os cortes que satisfazem o pedido de tamanho 4, excepto os resíduos que seram cortados com tamanho 4

y65 + y75 + y85 + y95 + 2 y105 + y115 - y54 - y53 = 5;				// Soma de todos os cortes que satisfazem o pedido de tamanho 5, excepto os resíduos que seram cortados com tamanho 5





/* Todas as variáveis sao números inteiros e devem ser maiores ou iguais a 0 (2.4) */ 

y42 >= 0;
y82 >= 0;
y92 >= 0;
y102 >= 0;
y112 >= 0;
y43 >= 0;
y53 >= 0;
y63 >= 0;
y93 >= 0;
y103 >= 0;
y113 >= 0;
y32 >= 0;
y54 >= 0;
y64 >= 0;
y74 >= 0;
y84 >= 0;
y104 >= 0;
y114 >= 0;
y65 >= 0;
y75 >= 0;
y85 >= 0;
y95 >= 0;
y105 >= 0; 
y115 >= 0;




int y42 y82 y92 y102 y112 y43 y53 y63 y93 y103 y113 y32 y54 y64 y74 y84 y104 y114 y65 y75 y85 y95 y105 y115;
