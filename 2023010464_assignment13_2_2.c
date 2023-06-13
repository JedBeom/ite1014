#include <stdio.h>

void printString(const char* str);

int main() {
	const char* strings[3] = {"One", "Two", "Three"};

	void (*fptr)(const char* str) = printString;
	for (int i=0; i<3; i++) {
		printString(strings[i]);
	}

	return 0;
}

void printString(const char* str) {
	printf("%s\n", str);
}
