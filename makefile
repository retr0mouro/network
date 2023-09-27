CFLAGS = -Wall

sources := aula2/main.c aula1/node.c aula1/deque.c aula2/command_parser.c

objects := $(sources:.c=.o)

.PHONY: all clean

EXECUTABLE := game

all: $(EXECUTABLE)

game: $(objects)
	gcc $(CFLAGS) $(objects) -o $(EXECUTABLE)

clean:
	rm -f *.o $(EXECUTABLE)
