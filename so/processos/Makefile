sources := ./src

deps := ./libs

libs := $(deps)/$(wildcard *.h)

cflags := -Wall -g  

src := $(sources)/$(wildcard *.c);

obj := $(patsubst $(sources)/%.c,$(sources)/%.o,$(src))

compile: $(obj)

%.o: %.c $(deps)
	gcc -c -o $@ $< $(cflags)

ps: $(obj)
	gcc -o $@ $(src)/ps.o

clean: 
	rm $(sources)/*.o