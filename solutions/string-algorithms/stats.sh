#!/usr/bin/env bash


[ -e times.log ] && rm times.log;


for i in 1 2 3 4 5 6 7 8 9 10; do

	echo "RUN --- $i" >> times.log;
	echo "Running $i";
	./tests/string_algos_tests 2>&1 | grep COUNT >> times.log;
done

# Rscript -e 'times <- read.table("times.log", header=T); summary(times)'
