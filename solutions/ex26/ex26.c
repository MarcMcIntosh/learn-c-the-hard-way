#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

int main(int argc, char *argv[])
{
	// check will print out message and goto error if first paremter is flase
	check(argc > 1, "No string provided");

	FILE *file = fopen(".logfind", "r");
	check(file, "Failed to open file");
	return 0;
error:
	return 1;

}
