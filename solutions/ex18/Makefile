CFLAGS= -Wall -g

_FILE_NAME:=$(shell echo $(CURDIR) | sed 's:.*/::')

all: clean $(_FILE_NAME) test

test:
	gdb --batch --ex run --ex bt --ex q --args $(_FILE_NAME) 4 1 3 5 6 2

clean: 
	rm -f $(_FILE_NAME)

