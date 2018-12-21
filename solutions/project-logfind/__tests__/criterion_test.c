#include <criterion/criterion.h>
#include "../src/find_word_in_text.c"

Test(misc, failing) {
	cr_expect(find_word_in_text("foo", "bar") == 0, "Should return 0 on no match");
}

