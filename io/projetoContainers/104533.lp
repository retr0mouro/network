min: 11 maior + 10 medio + 7 menor;



// O numero de contentores deve ser positivo
maior >= 0; // Limite para contentores de 11 é infinito
medio >= 0;
menor >= 0;

medio <= 5; // Limite para contentores de 10 é 5
menor <= 4; // Limite para contentores de 7 é 4


k2 <= 13;   // A quantidade de itens com tamanho 2 é 13;
k3 <= 10;   // A quantidade de itens com tamanho 3 é 10;
k4 <= 11;   // A quantidade de itens com tamanho 4 é 11;
k5 <= 5;    // A quantidade de itens com tamanho 5 é 5;


/* Combinacoes de items */

menor >= 2 k2 +   k3;
menor >=   k2 +   k5;
menor >=   k3 +   k4;




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





/*
target: 7
2 2 3
2 5
3 4


target: 10
2 2 2 2 2
2 2 2 4
2 2 3 3
2 3 5 
2 4 4
3 3 4
5 5 

target: 11
2 2 2 2 3
2 2 2 5
2 2 3 4
2 3 3 3
2 4 5
3 3 5
4 4 3

*/
