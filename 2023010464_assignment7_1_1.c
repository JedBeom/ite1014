#include <stdio.h>

int main() {
	int i, n, multiply;
	double d;
	
	scanf("%d %lf", &i, &d);
	
	multiply = 2;
	for (n=1; n<=3; n++) {
		printf("%10d", i*multiply);
		multiply *= 2;
	}
	printf("\n");

	multiply = 2;
	for (n=1; n<=3; n++) {
		printf("%10.2f", d*multiply);
		multiply *= 2;
	}
	printf("\n");
}
