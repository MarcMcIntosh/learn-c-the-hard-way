#include <stdio.h>

/* This is made to crash */

int main(int argc, char *argv[])
{
	char *test = NULL;

	for(int i = 0; i < 1000000; i++){
		printf("%c", test[i]);
	}
	
	return 0;
}
