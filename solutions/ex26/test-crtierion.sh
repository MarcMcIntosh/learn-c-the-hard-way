#!/usr/bin/env bash
cc -Wall -g -lcriterion __tests__/criterion_test.c  -o criterion_test && ./criterion_test
