#include <stdio.h>
#include <string.h>

int isAlpha(const char a);

int main(void) {
	char line[21];

	scanf("%s", line);
	int len = strlen(line);

	for (int i=0; i<len; i++) {
		while (!isAlpha(line[i])) {
			for (int j=i; j<len; j++) {
				line[j] = line[j+1];
			}

			len -= 1;
			if (i == len) break;
		}
	}

	printf("%s\n", line);

	return 0;
}

int isAlpha(const char a) {
	return ('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z');
}
