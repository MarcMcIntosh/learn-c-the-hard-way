#include <darray.h>
#include <assert.h>

DArray * DArray_create(size_t element_size, size_t initial_max)
{
	DArray *array = malloc(sizeof(DArray));
	check_mem(array);
	array->max = initial_max;
	check(array->max > 0, "You must set an intial_max > 0.");

	array->contents = calloc(initial_max, sizeof(void *));
	check_mem(array->contents);

	array->end = 0;
	array->element_size = element_size;
	array->expand_rate = DEFAULT_EXPAND_RATE;

	return array;
error:
	if(array) {
		if(array->contents) { 
			free(array -> contents);
		}
	}
	return NULL;
}
