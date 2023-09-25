CFLAGS = -Wall

sources := aula1.c node.c deque.c

objects := $(sources:.c=.o)

.PHONY: all clean

EXECUTABLE := game

all: $(EXECUTABLE)

game: $(objects)
	gcc $(CFLAGS) $(objects) -o $(EXECUTABLE)

clean:
	rm -f *.o $(EXECUTABLE)
