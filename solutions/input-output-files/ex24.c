#include <stdio.h>
#include "dbg.h"

#define MAX_DATA 100

typedef enum EyeColour {
	BLUE_EYES, GREEN_EYES, BROWN_EYES,
	BLACK_EYES, OTHER_EYES
} EyeColour;

const char *EYE_COLOUR_NAMES[] = {
	"Blue", "Green", "Brown",
	"Black", "Other"
};

typedef struct Person {
	int age;
	char first_name[MAX_DATA];
	char last_name[MAX_DATA];
	EyeColour eyes;
	float income;
} Person;

int main(int argc, char *argv[])
{
	Person you = {.age = 0 };
	// int i = 0;
	// pointer for input
	char *in = NULL;

	printf("What's your first name? ");
	in = fgets(you.first_name, MAX_DATA - 1, stdin);
	check(in != NULL, "Failed to read first name.");

	printf("What's you last name? ");
	in = fgets(you.last_name, MAX_DATA - 1, stdin);
	check(in != NULL, "Failed to read last name.");

	printf("How old are you? ");
	int rc = fscanf(stdin, "%d", &you.age);
	check(rc > 0, "You have to enter a number.");

	// Where is OTHER_EYES
	printf("What colour are your eyes:\n");
	for(int i = 0; i <= OTHER_EYES; i++) {
		printf("%d) %s\n", i + 1, EYE_COLOUR_NAMES[i]);
	}
	printf("> ");

	int eyes = -1;
	rc = fscanf(stdin, "%d", &eyes);
	check(rc > 0, "You have to enter an number");

	you.eyes = eyes - 1;
	check(you.eyes <= OTHER_EYES && you.eyes >= 0, "Do it right, that's not an option");

	printf("How much do you make an hour? ");
	rc = fscanf(stdin, "%f", &you.income);
	check(rc > 0, "Enter a floating point number.");

	printf("-------RESULTS-------\n");

	printf("First name: %s", you.first_name);
	printf("Last name: %s", you.last_name);
	printf("Age: %d\n", you.age);
	printf("Eyes: %s\n", EYE_COLOUR_NAMES[you.eyes]);
	printf("Income: %f\n", you.income);

	return 0;

error:
	return -1;

}
