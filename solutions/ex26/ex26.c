#include <stdio.h>
#include "dbg.h"


int main(int argc, char *argv[])
{
	check(argc > 2, "No string provided");
	return 0;
error:
	return 1;

}
