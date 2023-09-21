#include <stdio.h>

int main() {

	int accumulator = 0;
	char input;

	for (;;) {
		printf(">> ");
		scanf("%s", &input);
		if (accumulator == 256 || accumulator == -1) {
			accumulator = 0;
		}

		if (input == 'i') {
			accumulator++;
		} else if (input == 'd') {
			accumulator--;
		} else if (input == 's') {
			accumulator *= accumulator;
		} else if (input == 'o') {
			printf("%d\n", accumulator);
		} else {
			printf("Invalid input detected, use only 'i', 'd', 's', and 'o'\n");
			return 1;
		}

	}
	return 0;
}