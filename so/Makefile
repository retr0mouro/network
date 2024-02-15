
SRC1 = $(wildcard guiao1/*.c)

OBJ1 = $(SRC1:.c=.o)

CFLAGS = -Wall -g 

.PHONY: guiao1 all compile cat cp clean cout

all : compile

cat : $(compile)
	gcc $(CFLAGS) -o mycat guiao1/mycat.o

cp : $(compile)
	gcc $(CFLAGS) -o mycp guiao1/mycp.o

compile : $(OBJ1)

clean : 
	rm -f guiao1/*.o mycat mycp 

cout : 
	rm -f mycat mycp
