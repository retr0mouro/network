CFLAGS = -Wall -Iincludes

sources := src/main.c src/node.c src/deque.c src/command_parser.c

objects := $(sources:.c=.o)

.PHONY: all clean

EXECUTABLE := game

all: $(EXECUTABLE)

game: $(objects)
	gcc $(CFLAGS) $(objects) -o $(EXECUTABLE)

clean:
	rm -f src/*.o $(EXECUTABLE)
