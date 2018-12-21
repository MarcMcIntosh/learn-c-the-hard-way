#include "stdio.h"
#include "../minunit.h"
#include "../src/find_word_in_text.c"

// reading https://lwn.net/Articles/558106/
// http://www.jera.com/techinfo/jtns/jtn002.html

int tests_run = 0;

static char * test_find_word_in_text() {

	mu_assert("Find word in text returns 0 for non-match", find_word_in_text("foo", "bar") == 0);
	return 0;
}


static char * all_tests() {
	mu_run_test(test_find_word_in_text);
	return 0;
}

int main(int argc, char *argv[]) {
	char *result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
	} else {
		printf("ALL TESTS PASSED\n");
	}

	printf("Tests run: %d\n", tests_run);

	return result != 0;
}



