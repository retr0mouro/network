CC = gcc
CFLAGS = -Wall -g

.PHONY: pessoas clean

pessoas: pessoas.o person.o
	$(CC) -o $@ $^ $(CFLAGS) 

person.o: person.c person.h
	$(CC) -c $< $(CFLAGS)

pessoas.o: pessoas.c person.h
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o pessoas pessoas.db

