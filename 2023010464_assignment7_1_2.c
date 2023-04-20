#include <stdio.h>

int main() {
	char c;

	while (1) {
		scanf(" %c", &c);
		
		if ('A' <= c && c <= 'Z') {
			c += 'a' - 'A';
		} else if ('a' <= c && c <= 'z') {
			c -= 'a' - 'A';
		} else if ('0' <= c && c <= '9') {
			c = c;
		} else {
			printf("exit\n");
			return 0;
		}

		printf("-> %c\n", c);
	}
}
