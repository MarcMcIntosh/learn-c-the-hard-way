CFLAGS = -Wall -g
.logfind:
	$(shell echo spec.md > $@)

tests: __tests__/find_word_in_text.c
	cc $(CFLAGS) $^ -o $@


all: clean .logfind ex26

clean: 
	test -f ex26 && rm ex26 
	test -f .logfind && rm .logfind
