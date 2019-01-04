#include <stdlib.h>
#include <mergesort.h>
#include <dbg.h>

void merge(void *dest[], size_t start, size_t mid, size_t end, size_t size, int (*cmp) (const void *, const void *))
{
	size_t left = start;
	size_t right = mid + 1;
	
	while(left < mid || right < end) {
		int diffrence = cmp(dest[left], dest[right]);

		if(diffrence <= 0) {
			size_t s = size;
			do {
				void * tmp = *(dest + left);
				dest[left++] = *(dest + right);
				dest[right++] = tmp;
			} while (--s > 0);
		}
		
	}
}

void split(void *dest, size_t start, size_t end, size_t size, int (*cmp) (const void *, const void *))
{
	if(start >= end) { return; }

	int mid = (start + (end - start)) / 2;

	// left
	
	split(dest, start, mid, size, cmp);
	
	// right
	split(dest, mid + 1, end, size, cmp);

	merge(dest, start, mid, end, size, cmp);
}

// sort cmp is strcmp
int mergesort (void *contents, size_t count, size_t size, int (*cmp) (const void *, const void * ))
{
	// https://codereview.stackexchange.com/questions/131407/mergesort-algorithm-in-c
	// https://www.geeksforgeeks.org/merge-sort/

	// if(count <= 1) { return 0; }

	char *base_ptr = (char *) contents;

	
	/*
	printf("Mergesort contents given\n");

	for(size_t i = 0; i < count; i++) {
		char *el = contents[i];
		printf("contents[%ld]: %s", i, el);
	// get and print contents some how
	}
	split(contents, 0, count, size, cmp);
	*/
	return 0;
}
