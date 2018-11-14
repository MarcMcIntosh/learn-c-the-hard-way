CFLAGS= -Wall -g

_FILE_NAME:=$(shell echo $(CURDIR) | sed 's:.*/::')

all: clean $(_FILE_NAME) test

test:
	gdb --batch --ex run --ex bt --ex q --args $(_FILE_NAME)

clean: 
	rm -f $(_FILE_NAME)

