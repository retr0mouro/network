
SRC1 = $(wildcard ficheiros/*.c)

OBJ1 = $(SRC1:.c=.o)

CFLAGS = -Wall -g 

.PHONY: guiao1 all compile cat cp pessoas clean cout

all : $(compile)

pessoas : $(compile)
	gcc $(CFLAGS) -o pessoas ficheiros/pessoas.o

cat : $(compile)
	gcc $(CFLAGS) -o mycat ficheiros/mycat.o

cp : $(compile)
	gcc $(CFLAGS) -o mycp ficheiros/mycp.o

compile : $(OBJ1)

clean : 
	rm -f ficheiros/*.o mycat mycp 

cout : 
	rm -f mycat mycp
