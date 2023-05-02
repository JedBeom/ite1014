#include <stdio.h>

int printLine(int n) {
	for (int i=1; i<=n; i++) {
		printf("%d ", i);
	}
	printf("\n");

	return 0;
}

int main() {
	int num = 0, j=0;
	scanf("%d", &num);
	for (int i=1; i<=2*num; i++) {
		j = i;
		if (i > num) {
			j = 2*num - i + 1;
		}

		printLine(j);
	}
}
