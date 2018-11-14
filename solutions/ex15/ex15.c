#include <stdio.h>

int main(int argc, char *argv[])
{
	int ages[] = { 23, 43, 12, 89, 2 };
	char *names[] = { "Alan", "Frank", "Mary", "John", "Lisa" };


	// safely get the size of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	// first way using indexing
	for(i = 0; i < count; i++){
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}

	printf("----\n");

	// set up the pointers to start of the arrays
	
	int *cur_age = ages;
	char **cur_name = names;

	// Secondway using pointers
	
	for(i = 0; i < count; i++) {
		printf("%d: %p: %s is %d years old.\n", i, cur_name + i,
				*(cur_name + i), *(cur_age + i));
	}

	printf("---\n");

	for(i = 0; i < count; i++) {
		printf("%s is %d years old again.\n", 
				cur_name[i], cur_age[i]);
	}

	printf("---\n");

	// fourth way with pointers in a studi complex way
	
	for(cur_name = names, cur_age = ages;
			(cur_age - ages) < count;
			cur_name++, cur_age++) {
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}

	// int height = 100;
	
	// Recasting
	// int *cur_age = (int *)names;
	
	// int *cur_height = &height;

	printf("---\n");

	return 0;

}
