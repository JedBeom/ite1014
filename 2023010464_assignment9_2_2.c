#include <stdio.h>
#include <string.h>

int main(void) {
	char word[10];

	scanf("%s", word);

	for (int i=0; i<strlen(word); i++) {
		if (word[i] >= 'a') {
			word[i] += 'A' - 'a';
		} else {
			word[i] -= 'A' - 'a';
		}
	}

	printf("%s\n", word);
}
