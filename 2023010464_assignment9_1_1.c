#include <stdio.h>

int main() {
	int a[5];

	for (int i=0; i<5; i++) {
		scanf("%d", a+i);
	}

	int min = a[0], max = a[0], sum = 0;
	for (int i=0; i<5; i++) {
		if (min > a[i]) min = a[i];
		if (max < a[i]) max = a[i];
		sum += a[i];
	}

	printf("min: %d\n", min);
	printf("max: %d\n", max);
	printf("sum: %d\n", sum);
}

