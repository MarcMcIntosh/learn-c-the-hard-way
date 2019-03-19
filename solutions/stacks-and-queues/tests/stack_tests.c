#include "minunit.h"
#include <stack.h>
#include <assert.h>

static Stack *stack = NULL;
char *tests[] = { "test1 data", "test2 data", "test3 data" };

#define NUM_TESTS 3;

char *test_create()
{
	stack = Stack_create();
	mu_assert(stack != NULL, "Failed to create stack.");

	return NULL;
}

char *all_tests()
{
	mu_suite_start();

	mu_run_test(test_create);

	return NULL;
}

RUN_TESTS(all_tests);
