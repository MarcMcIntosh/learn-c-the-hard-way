CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
LDFLAGS=$(OPTLIBS)
## Add undefined behavour checker
CFLAGS += -fsanitize=undefined

## DEFAULT PREFIX  ?=
PREFIX?=/usr/local

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

TARGET=build/liblcthw.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# Build target
# all: $(TARGET) $(SO_TARGET) tests
all: $(TARGET) tests

dev: CFLAGS= -g -Wall -Isrc -Wall -Wextra -fsanitize=undefined $(OPTFLAGS)
dev: all

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

OS=$(shell uname -s)
ifeq ($(OS),Linux)
	LDLIBS= -lbsd -L./build -lm
endif

## $(SO_TARGET): $(TARGET) $(OBJECTS)
##	$(CC) -shared -o $@ $(OBJECTS)

build:
	@mkdir -p build
	@mkdir -p bin

# The unit tests
.PHONY: tests
tests: LDLIBS += $(TARGET)
tests: $(TESTS)
	sh ./tests/runtests.sh

valgrind:
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)


# The Cleaner
clean: 
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`

# The install
install: all
	install -d $(DESTDIR) $(TESTS)
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

# The checker
check:
	@echo Files with potentually dangeriouse functions.
	@egrep '[^_.>a-zA_Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)' $(SOURCES) || true


