CFLAGS= -Wall -g -DNDEBUG

ex22.o: ex22.c
	cc $(CFLAGS) -c -o $@ $< 

ex22_main: ex22.o 
	cc $(CFLAGS) $@.c $< -o $@

all: clean ex22_main

clean:
	rm -f *.o ex22_main
