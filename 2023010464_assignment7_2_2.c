#include <stdio.h>

int addTotal(int n) {
	int sum = 0;
	for (int i=1; i<=n; i++) {
		sum += i;
	}
	return sum;
}

int gMul = 1;

void mulTotal(int n) {
	for (int i=1; i<=n; i++) {
		gMul *= i;
	}
}

int main(void) {
	int n;
	scanf("%d", &n);

	printf("addTotal(): %d\n", addTotal(n));
	mulTotal(n);

	printf("gMul: %d\n", gMul);

	return 0;
}
