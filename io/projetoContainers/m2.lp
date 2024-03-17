/*
	Dicionário	I := 4 (d4)
			K := 3 (s3)


	S = {7,10,11};
	D = {2,3,4,5};
	R = {2,3,4,5,6,7,8,9}
	
	S n D == 0 (\fi)

	N2 = 13
	N3 = 10
	N4 = 11 
	N5 = 5
	
*/

min: 	7 y74 + 7 y75 + 
		10 y102 + 3 y103 + 10 y104 + 10 y105 + 
		11 y112 + 11 y113 + 4 y114 + 11 y115;



y74 + y75 - y103 - y114 <= 4; // Todos os cortes apartir de comprimento standard com residuo 7 excepto o cortes obtidos de cortes previos ([10,3] -> 7 | [11,4] -> 7)

y74 - y32 >= 0;



y105 + y104 + y103 + y102 <= 5; // Todos os cortes apartir de comprimento standard com residuo 7 excepto o cortes obtidos de cortes previos ([10,3] -> 7 | [11,4] -> 7)

y105 - y53 - y54 >= 0; 
y104 + y115 - y65 - y64 - y63 >= 0;
y102 + y113 - y85 - y84 - y82 >= 0;


// Cortes apartir de comprimento standard 11 são ilimitados


y112 - y95 - y93 - y92 >= 0;

y84 + y95 - y43 - y42 >= 0;





y32 + 2 y42 + y53 + y64 + y75 + y82 + y92 + y102 + y112 = 13;

y43 + y53 + 2 y63 + y74+ y85 + y93 + y103 + y113 - y32 = 10;

y54 + y64 + y74 + 2 y84 + y95 + y104 + y114 - y43 - y42 = 11;

y65 + y75 + y85 + y95 + 2 y105 + y115 - y54 - y53 = 5;

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
