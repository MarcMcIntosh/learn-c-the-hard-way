#include <lcthw/list_algos.h>
#include <dbg.h>


int List_bubble_sort(List * list, List_compare compare_function)
{	// what's the length of the array ?

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
	/*
	
	LIST_FOREACH(list, first, next, curr) {
		if(curr->next != NULL) {
			int should_swap = compare_function(curr->value, curr->next->value);
			if(should_swap > 0) {
				void *temp = curr->value;
				curr->value = curr->next->value;
				curr->next->value = temp;
			}
		}
	}

	return 0;
	*/
}
