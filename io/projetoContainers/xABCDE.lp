min: 11 maior + 10 medio + 7 menor;


//max: x + A + B + C + D + E;





int maior, medio, menor;


// Restrições para os algarismos de xABCDE


/*
    x pode possuir os valores de 0 ou 1;
*/
//bin x;

/*
*   k1 depende da paridade de B
*/
k1 = B % 2;


// k2 depende da paridade de C, somando ou não 6 ao valor base C + 2
cAux = C % 2;
k2 = C + 2 + (cAux * 6);


// k3 depende da paridade de D 
k3 = D % 2;


// k4 depende da paridade de E, somando ou não 6 ao valor base E + 2
eAux = E % 2;
k4 = E + 2 + (eAux * 6);











// Quantidade disponível dos contentores de comprimento 10 é B + 1
medio <= B + 1;



// Quantidade disponível dos contentores de comprimento 7 é D + 1
menor <= D + 1;