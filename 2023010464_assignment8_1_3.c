#include <stdio.h>

int ncr(int n, int r) {
	if (r == 1) {
		return n;
	}
	if (n == r) {
		return 1;
	}

	return ncr(n-1, r-1) + ncr(n-1, r);
}

int main(void) {
	int n, r;
	scanf("%d %d", &n, &r);

	printf("%d\n", ncr(n, r));
}
