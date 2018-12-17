#include <lcthw/list_algos.h>
#include <dbg.h>

int List_bubble_sort(List * list, List_compare compare_function)
{	// what's the length of the array ?

	// see: https://en.wikipedia.org/wiki/Bubble_sort
	int should_sort = 1;

	while(should_sort) {

		should_sort = 0;

		LIST_FOREACH(list, first, next, curr) {
			if(curr->next != NULL) {
				int should_swap = compare_function(curr->value, curr->next->value);
				if(should_swap > 0) {
					void *temp = curr->value;
					curr->value = curr->next->value;
					curr->next->value = temp;
					// reset should_sort;
					should_sort = 1;
				}
			}
		}
	}

	return 0;
}

List *List_merge_sort(List * list, List_compare compare_function)
{
	// List *result = NULL;
	return list;

}

/*
List * List_merge(List * left, List * right, List_compare compare_function)
{
	List *result = List_create();
	void * val = NULL;

	// debug("Sorting\n\tLeft: %s\n\tRight: %s", left, right);

	while(List_count(left) > 0 || List_count(right) > 0) {
		int count_left = List_count(left);
		int count_right = List_count(right);

		if (count_left > 0 && count_right > 0) {
			void * first_left = List_first(left);
			void * first_right = List_first(right);

			if (compare_function(first_left, first_right)) {
				val = List_shift(left);
			} else {
				val = List_shift(right);
			}

			List_push(result, val);
		} else if (count_left > 0) {
			val = List_shift(left);
			List_push(result, val);
		} else if (count_right > 0) {
			val = List_shift(right);
			List_push(result, val);
		}
	}

	return result;
}


List * List_merge_sort(List * list, List_compare compare_function)
{
	if (List_count(list) <= 1) {
		return list;
	}

	List * left = List_create();
	List * right = List_create();

	int middle_of_list = List_count(list) / 2;

	LIST_FOREACH(list, first, next, curr) {
		if(middle_of_list > 0) {
			List_push(left, curr->value);
		} else {
			List_push(right, curr->value);
		}
		middle_of_list--;
	}

	List * left_sorted = List_merge_sort(left, compare_function);
	List * right_sorted = List_merge_sort(right, compare_function);



	if (left_sorted != left) {
		List_destroy(left);
	}

	if (right_sorted != right) {
		List_destroy(right);
	}

	return List_merge(left_sorted, right_sorted, compare_function);
}

*/
