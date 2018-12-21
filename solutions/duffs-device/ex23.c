#include <stdio.h>
#include <string.h>
#include "dbg.h"

int normal_copy(char *from, char *to, int count)
{
	// copies one string to another,  
	int i = 0;

	for(i = 0;  i < count ; i++) {
		to[i] = from[i];
	}

	return i;
}

int duffs_device(char *from, char *to, int count) 
{
		// this would be 0.875 at least, or 0 for an int; 
	int n = (count + 7) / 8;

	switch(count % 8) {
		case 0:
			// full block of 8
			do {
				// No break statement, so these a number of times after the case is met
				*to++ = *from++;
				case 7:
				*to++ = *from++;
				case 6:
				*to++ = *from++;
				case 5:
				*to++ = *from++;
				case 4:
				*to++ = *from++;
				case 3:
				*to++ = *from++;
				case 2:
				*to++ = *from++;
				case 1:
				*to++ = *from++;
				// debug("Chunk %d", n);
			} while (--n > 0);
	}
	return count;
}


int zeds_device(char *from, char *to, int count)
{
	{
		int n = (count + 7) / 8;

		debug("n starts: %d, count %d, count%%8: %d", n, count, count % 8);

		switch(count % 8) {
			case 0:
again: *to++ = *from++;
			
			case 7:
       			*to++ = *from++;
			case 6:
			*to++ = *from++;
			case 5:
			*to++ = *from++;
			case 4:
			*to++ = *from++;
			case 3:
			*to++ = *from++;
			case 2:
			*to++ = *from++;
			case 1:
			*to++ = *from++;
			debug("Last case: n=%d", n);
			if(--n > 0) {
				debug("Going again, n=%d",n);
				goto again;
			}
		}
	}

	return count;
}

int valid_copy(char *data, int count, char expects)
{
	int i = 0;
	for (i = 0; i < count; i++) {
		if(data[i] != expects) {
			log_err("[%d] %c != %c", i, data[i], expects);
			return 0;
		}
	}

	return 1;
}

int main(int argc, char *argv[])
{
	char from[1000] = { 'a' };
	char to[1000] = { 'c' };

	int rc = 0;

	// set up the from and to the have some stuff;
	memset(from, 'x', 1000);

	// set it to a failure mode
	memset(to, 'y', 1000);
	check(valid_copy(to, 1000, 'y'), "Not initaialized right");

	// use normal copy
	// rc = normal_copy(from, to, 1000);
	// check(rc == 1000, "Normal copy failed");
	// check(valid_copy(to, 1000, 'x'), "Normal copy failed");

	// reset
	memset(to, 'y', 1000);

	// duffs version
	rc = duffs_device(from, to, 1000);
	check(rc == 1000, "Duff's device failed: %d", rc);
	check(valid_copy(to, 1000, 'x'), "Duff's devied failed copy.");

	// reset
	memset(to, 'y', 1000);

	// zeds verions
	
	// rc = zeds_device(from, to, 1000);
	// check(rc == 1000, "Zed's device failed: %d", rc);
	// check(valid_copy(to, 1000, 'x'), "Zed's device failed copy.");

	return 0;

error:
	// used by check
	return 1;
}
