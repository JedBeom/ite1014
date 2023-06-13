#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool in(char* str, char** list, int len);

int main(void) {
	char* words[10];
	char input[20];
	int i, wordnum;
	for (i=0; i<10; i++) {
		printf("Enter a word (Enter 'end' to quit): ");
		scanf("%s", input);
		
		if (!strcmp(input, "end")) {
			break;
		}

		if (in(input, words, i)) {
			printf("This word already exists. Please enter another word.\n");
			i--;
			continue;
		}

		words[i] = malloc(sizeof(char)*20);
		strcpy(words[i], input);
	}
	wordnum = i;

	printf("%d words in the list:\n", wordnum);
	for (i=0; i<wordnum; i++) {
		printf("%s ", words[i]);
	}
	printf("\n");

	for (;;) {
		printf("Enter a word to search (Enter 'end' to quit): ");
		scanf("%s", input);

		if (!strcmp(input, "end")) {
			break;
		}

		if (in(input, words, wordnum)) {
			printf("This word is in the list.\n");
		} else {
			printf("This word is NOT in the list.\n");
		}
	}
		
	return 0;
}

bool in(char* str, char** list, int len) {
	int i;
	for (i=0; i<len; i++) {
		if (!strcmp(str, *(list+i))) {
			return true;
		}
	}
	return false;
}
