#include <stdio.h>

int main(void) {
	double a = 1.23456789, b = 0.0000123456789;

	printf("1) %.10f %.10f\n", a, b);
	printf("2) %e %e\n", a, b);
	printf("3) %E %E\n", a, b);
	printf("4) %g %g\n", a, b);
	printf("5) %G %G\n", a, b);
}
