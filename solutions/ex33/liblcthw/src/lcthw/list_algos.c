#include <lcthw/list_algos.h>
#include "dbg.h"

size_t array_length(char *words[]) 
{
	size_t i = 0;
	while(words[i++]);
	return i;
}

int List_bubble_sort(List * list, List_compare compare_function)
{
	// what's the length of the array ?
	size_t number_of_elements = list->count;
	debug("Number of words given to bubble sort: %ld", number_of_elements);

	return 0;
}
