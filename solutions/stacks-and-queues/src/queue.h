#ifndef _lcthw_Queue_h
#define _lcthw_Queue_h

#include "list.h"

typedef List Queue;

#define Queue_create List_create
#define Queue_destroy List_destroy
#define Queue_send List_unshift
#define Queue_peek List_last
#define Queue_count List_count
#define STACK_FOREACH(list, V) LIST_FOREACH(list, last, prev, V)
#define Queue_recv List_pop

#endif 
