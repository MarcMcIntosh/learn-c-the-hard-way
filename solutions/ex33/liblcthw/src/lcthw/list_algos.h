#ifndef list_algos_h
#define list_algos_h

#include <lcthw/list.h>

typedef int (*List_compare) (const char *a, const char *b);

int List_bubble_sort(List *list, List_compare compare_function);

List * List_merge(List * left, List * right, List_compare compare_function);

List *List_merge_sort(List *list, List_compare compare_function);

#endif

