#ifndef _mergesort_h
#define _mergesort_h

// borrowed from https://www.codecogs.com/library/computing/c/stdlib.h/qsort.php?alias=mergesort

int mergesort (void *contents, size_t count, size_t size, int (*cmp) (const void *, const void * ));

#endif
