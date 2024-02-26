MAIN := $(patsubst ./%.java,./%.class,./Main.java)

SRC :=  $(wildcard pacote/*.java)

OBJ := $(patsubst pacote/%.java,pacote/%.class,$(SRC))

.PHONY: update exe clean cleanAll

pacote: $(OBJ)

pacote/%.class: pacote/%.java
	javac -d . $<

update: pacote/Implementacao.java
	javac -d . pacote/Implementacao.java

compile: $(MAIN)

./%.class: ./%.java
	javac $<

exe: $(compile)
	java Main

clean: 
	rm *.class

cleanAll: 
	rm ./*.class pacote/*.class

all: compile pacote
	$(compile)