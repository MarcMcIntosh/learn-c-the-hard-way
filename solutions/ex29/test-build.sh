#!/usr/bin/bash
make &&\
	./build/ex29_tests ./libex29.so print_a_message "hello there" \
	./build/ex29_tests ./libex29.so uppercase "hello there"\
	./build/ex29_tests ./libex29.so lowercase "HELLO tHeRe"

