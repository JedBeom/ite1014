#include <stdio.h>

int main() {
	int n, squared, i;
	squared = 1;
	i = 0;

	printf("input number : ");
	scanf("%d", &n);

	while (i<10) {
		squared *= n;
		printf("%d\t", squared);
		i++;
	}
	printf("\n");
}
