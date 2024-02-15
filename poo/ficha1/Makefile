CC = javac
RUNNER = java
SOURCES = $(wildcard *.java)
OBJ = $(SOURCES:.java=.class)

.PHONY: all compile first second clean

all: compile

compile: $(OBJ)

%.class: %.java
    $(CC) $<

first: compile
    $(RUNNER) TestePrograma

second: compile
    $(RUNNER) lastPart

clean:
    rm $(OBJ)
