min: 11 maior + 10 medio + 7 menor;



// O numero de contentores deve ser positivo
maior >= 0; // Limite para contentores de 11 é infinito
medio >= 0;
menor >= 0;

medio <= 5; // Limite para contentores de 10 é 5
menor <= 4; // Limite para contentores de 7 é 4


/* Combinacoes de items */

/*
menor >= 2 k2 +   k3;
menor >=   k2 +   k5;
menor >=   k3 +   k4;
*/

menor >= c1 + c2 + c3; // Todas as combinacoes com resultado 7

medio >= c4 + c5  + c6 + c7 + c8 + c9 + c10; // Todas as combinacoes com resultado 10
 
maior >= c11 + c12  + c13 + c14 + c15 + c16 + c17; // Todas as combinacoes com resultado 11

13 = 2 c1 + 1 c2 + 0 c3 + 5 c4 + 3 c5 + 2 c6 + 1 c7 + 1 c8 + 0 c9 + 0 c10 + 4 c11 + 3 c12 + 2 c13 + 1 c14 + 1 c15 + 0 c16 + 0 c17; // Soma dos items de tamanho 2 em cada combinacao
10 = 1 c1 + 0 c2 + 1 c3 + 0 c4 + 0 c5 + 2 c6 + 1 c7 + 0 c8 + 2 c9 + 0 c10 + 1 c11 + 0 c12 + 1 c13 + 3 c14 + 0 c15 + 2 c16 + 1 c17; // Soma dos items de tamanho 3 em cada combinacao
11 = 0 c1 + 0 c2 + 1 c3 + 0 c4 + 1 c5 + 0 c6 + 0 c7 + 2 c8 + 1 c9 + 0 c10 + 0 c11 + 0 c12 + 1 c13 + 0 c14 + 1 c15 + 0 c16 + 2 c17; // Soma dos items de tamanho 4 em cada combinacao
5 = 0 c1 + 1 c2 + 0 c3 + 0 c4 + 0 c5 + 0 c6 + 1 c7 + 0 c8 + 0 c9 + 2 c10 + 0 c11 + 1 c12 + 0 c13 + 0 c14 + 1 c15 + 1 c16 + 0 c17;  // Soma dos items de tamanho 5 em cada combinacao

int maior, menor, medio, c1 , c2 , c3 , c4 , c5 , c6 , c7 , c8 , c9, c10 , c11 , c12 , c13 , c14 , c15 , c16 , c17 ;

/*
target: 7
2 2 3
2 5
3 4


target: 10
2 2 2 2 2(4)
2 2 2 4(5)
2 2 3 3(6)
2 3 5 (7)
2 4 4 (8)
3 3 4(9)
5 5 (10)

target: 11
2 2 2 2 3(11)
2 2 2 5(12)
2 2 3 4(13)
2 3 3 3(14)
2 4 5(15)
3 3 5(16)
4 4 3(17)

*/


/*
medio >= 5 k2;
medio >= 3 k2 +   k4;
medio >= 2 k2 + 2 k3;
medio >=   k2 +   k3 +   k5;
medio >=   k2 + 2 k4;
medio >= 2 k3 +   k4;
medio >= 2 k5;




maior >= 4 k2 +   k3;
maior >= 3 k2 +   k5;
maior >= 2 k2 +   k3 +   k4;
maior >=   k2 + 3 k3;
maior >=   k2 +   k4 +   k5;
maior >= 2 k3 +   k5;
maior >= 2 k4 +   k3;
*/

