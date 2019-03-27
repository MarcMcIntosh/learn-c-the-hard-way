#ifndef _lcthw_Stack_h
#define _lcthw_Stack_h

#include "list.h"

typedef List Stack;

#define Stack_create List_create
#define Stack_destroy List_destroy
#define Stack_push List_push
#define Stack_peek List_last
#define Stack_count List_count
#define STACK_FOREACH(L, V) LIST_FOREACH(L, last, prev, V)
#define Stack_pop List_pop

#endif 
