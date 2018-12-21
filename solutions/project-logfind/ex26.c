#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

int main(int argc, char *argv[])
{
	// check will print out message and goto error if first paremter is flase
	check(argc > 1, "No string provided");

	FILE *config_file = fopen(".logfind", "r");
	check(config_file, "Failed to open file");

	// Read the file line by line

	return 0;
error:
	return 1;

}
