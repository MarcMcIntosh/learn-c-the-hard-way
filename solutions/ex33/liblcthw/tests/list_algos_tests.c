#include "minunit.h"
#include <lcthw/list_algos.h>
#include <assert.h>
#include <string.h>

char *values[] = { "XXXX", "1234", "abcd", "xjvef", "NDSS" };

#define NUM_VALUES 5

void print_list(List * list) {
	LIST_FOREACH(list, first, next, curr) {
		// printf("%s, ", curr->value);
		printf("%p, ", curr->value);
	}
	printf("\n");
}

List *create_words()
{
	int i = 0;
	List *words = List_create();

	for(i = 0; i < NUM_VALUES; i++) {
		List_push(words, values[i]);
	}

	return words;
}

int is_sorted(List * words)
{
	LIST_FOREACH(words, first, next, curr) {
		if(curr->next && strcmp(curr->value, curr->next->value) > 0) {
			debug("%s %s", (char *)curr->value, (char *)curr->next->value);
			return 0;
		}
	}
	return 1;
}

char *test_bubble_sort()
{
	List *words = create_words();

	// should work on a list that needs sorting, 
	// is (List_compare) a type?
	
	// print_list(words);

	int rc = List_bubble_sort(words, (List_compare) strcmp);
	// print_list(words);
	mu_assert(rc == 0, "Bubble sort failed");
	mu_assert(is_sorted(words), "Words are not sorted after bubble sort.");

	// should work on an alrady sorted list
	rc = List_bubble_sort(words, (List_compare) strcmp);
	mu_assert(rc == 0, "Bubble sort of already sorted list failed");
	mu_assert(is_sorted(words), "Words should be sorted if already bubble sorted.");

	List_destroy(words);

	// should work on an empty list
	words = List_create(words);
	rc = List_bubble_sort(words, (List_compare) strcmp);
	mu_assert(rc == 0, "Bubble sort failed on empty list.")
	mu_assert(is_sorted(words), "Words should be sorted if empty");

	List_destroy(words);

	return NULL;
}

char *test_merge_sort()
{
	List *words = create_words();


	List *res = List_merge_sort(words, (List_compare) strcmp);
	mu_assert(is_sorted(res), "Words are not sorted after merge sort.");
	
	
	List *res2 = List_merge_sort(res, (List_compare) strcmp);
	mu_assert(is_sorted(res), "Should still be sorted after merge sort.");
	
	List_destroy(res2);
	List_destroy(res);
	
	List_destroy(words);

	return NULL;
}


char *all_tests()
{
	mu_suite_start();
	
	mu_run_test(test_bubble_sort);
	mu_run_test(test_merge_sort);

	return NULL;
}

RUN_TESTS(all_tests);


