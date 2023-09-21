#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	int accumulator = 0;

	if (argc != 2) {
		printf("Please provide a text file as the second argument\n");
		return 1;
	}

	FILE* filePointer = fopen(argv[1], "r");

	if (filePointer == NULL) {
		printf("Error Opening File\n");
		return 1;
	}

	char cString[255];
	while (fscanf(filePointer, "%s", cString) == 1) {
		//
	}

	fclose(filePointer);

	for (int i = 0; cString[i] != '\0'; i++) {
		if (accumulator == 256 || accumulator == -1) {
			accumulator = 0;
		}

		if (cString[i] == 'i') {
			accumulator++;
		} else if (cString[i] == 'd') {
			accumulator--;
		} else if (cString[i] == 's') {
			accumulator *= accumulator;
		} else if (cString[i] == 'o') {
			printf("%d\n", accumulator);
		} else {
			printf("Invalid input detected, use only 'i', 'd', 's', and 'o'\n");
			printf("%s", cString[i]);
			return 1;
		}

	}
	return 0;
}