#ifndef list_algos_h
#define list_algos_h

#include <lcthw/list.h>

typedef int (*List_compare) (const char *a, const char *b);

int List_bubble_sort(char *words[], List_compare compare_function);
int List_merge_sort(char *words[], List_compare compare_function);

#endif

