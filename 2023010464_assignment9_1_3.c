#include <stdio.h>

int main() {
	int i;
	double a[5];

	for (i=0; i<5; i++) {
		scanf("%lf", a+i);
	}

	double *parr = a;

	for (i=0; i<5; i++) {
		*(parr+i) *= 2;
	}
	
	double sum = 0;
	for (i=0; i<5; i++) {
		printf("%f ", *(parr+i));	
		sum += *(parr+i);
	}
	printf("\n");
	printf("sum: %f\n", sum);
}
