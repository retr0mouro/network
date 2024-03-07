CFLAGS: -Wall -g 

ps: src/ps.c
	gcc -o $@ $< $(CFLAGS)

sequencia: src/sequencia.c
	gcc -o $@ $^ $(CFLAGS)

concurrencia: src/concurrencia.c
	gcc -g -o $@ $^ $(CFLAGS)


all: ps sequencia concurrencia

.PHONY: all clean


clean: 
	rm ps sequencia concurrencia
