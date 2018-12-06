#include <stdio.h>
#include <ctype.h>
#include "dbg.h"

int print_a_message(const char *msg)
{
	printf("A STRING: %s\n", msg);
	return 0;
}

// Note you could use pointers and function typedef to pass a functino to a loop
// typedef char * (*char_cb) (char * msg);
// int print_case(const char *msg, char_cb char_case);
// and write the loop in it, a simliar idea is done in ex29.c

int uppercase(const char *msg)
{
	int i = 0;

	// BUG \0 termination problems
	/* for(i = 0; msg[i] != \0; i++) {
		printf("%c", toupper(msg[i]));
	} */
	// Use the length
	// int msg_length = sizeof(*msg) / sizeof(char);
	int msg_length = sizeof(*msg) - 1;
	for(i = 0; msg[i] != '\0' && i < msg_length; i++) {
		printf("%c", toupper(msg[i]));
	}

	printf("\n");

	return 0;
}

int lowercase(const char *msg)
{
	int i = 0;
	int msg_length = sizeof(*msg) - 1;
	for(i = 0; msg[i] != '\0' && i < msg_length; i++) {
		printf("%c", tolower(msg[i]));
	}

	printf("\n");

	return 0;
}



int fail_on_purpose(const char *msg)
{
	return 1;
}


