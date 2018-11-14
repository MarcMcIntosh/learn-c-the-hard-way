#include <stdio.h>

int main(int argc, char *argv[])
{

	if (argc == 1) {
		printf("Not enough argumentsi\n");
	} else if (argc > 1 && argc < 4) {
		printf("Here are your arguments.\n");

		for (int i = 0; i < argc; i++) {
			printf("%s\n", argv[i]);
		}
		
	} else {
		printf("you have to many arguments\n");
	}

	return 0;


}
