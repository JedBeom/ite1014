#include <stdio.h>

int main(void) {
	int cnt = 0;
	char c;
	while (1) {
		scanf("%c", &c);
		if (c == '\n') break;
		cnt += 1;
	}

	printf("%d\n", cnt);
}
