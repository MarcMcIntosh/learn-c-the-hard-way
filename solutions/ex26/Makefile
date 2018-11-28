CFLAGS = -Wall -g

.logfind:
	$(shell echo spec.md > $@)

all: clean .logfind ex26

clean: 
	test -f ex26 && rm ex26 
	test -f .logfind && rm .logfind
