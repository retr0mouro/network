CFLAGS = -Wall -Iincludes -g

sources := src/main.c src/stack.c src/balcao.c

objects := $(sources:.c=.o)

.PHONY: all clean

EXECUTABLE := game

all: $(EXECUTABLE)

game: $(objects)
	gcc $(CFLAGS) $(objects) -o $(EXECUTABLE)

clean:
	rm -f src/*.o $(EXECUTABLE)
