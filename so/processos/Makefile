ps: src/ps.c
	gcc -o $@ $<

sequencia: src/sequencia.c
	gcc -o $@ $^


all: ps sequencia

.PHONY: all clean


clean: 
	rm ps sequencia
