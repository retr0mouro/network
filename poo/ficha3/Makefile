MAIN := $(patsubst ./%.java,./%.class,./Main.java)

SRC :=  $(wildcard pacote/*.java)

OBJ := $(patsubst pacote/%.java,pacote/%.class,$(SRC))

.PHONY: update exe clean cleanAll

pacote: $(OBJ)

pacote/%.class: pacote/%.java
	javac -d . $<

compile: ./Main.java
	javac Main.java

all: compile pacote
	$(compile)

exe: compile pacote
	java Main

clean: 
	rm *.class pacote/*.class