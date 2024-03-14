/* Funcao objetivo segundo modelo I */
min: 
7 x72 + 7 x73 + 7 x74 + 7 x75 + 10 x102 + 
10 x103 + 10 x104 + 10 x105 + 11 x112 + 
11 x113 + 11 x114 + 11 x115;

/**
    Dicionario:
        k   : Iterador do conjunto do standard 
        K   : nº de lengths standard
        j   : Iterador do conjunto do pedida
        I   : nº de lengths pedidas
        akj : nº de peças de standard length k para pedidas j
        di  : tamanho das peças
    Método

*/

a72 x72 + a73 x73 + a74 x74 + a75 x75 >= 4;
a102 x102 + a103 x103 + a104 x104 + a105 x105 >= 5;

2 a72 + 3 a73 + 4 a74 + 5 a75 <= 13;
2 a102 + 3 a103 + 4 a104 + 5 a105 <= 10;
2 a112 + 3 a113 + 4 a114 + 5 a115 <= 11;


x72 >= 0;
x73 >= 0;
x74 >= 0;
x75 >= 0;



a72 >= 0;
a73 >= 0;
a74 >= 0;
a75 >= 0;



x102 >= 0;
x103 >= 0;
x104 >= 0;
x105 >= 0;



a102 >= 0;
a103 >= 0;
a104 >= 0;
a105 >= 0;


x112 >= 0;
x113 >= 0;
x114 >= 0;
x115 >= 0;



a112 >= 0;
a113 >= 0;
a114 >= 0;
a115 >= 0;


int a72 x72 a73 x73 a74 x74 a75 x75;