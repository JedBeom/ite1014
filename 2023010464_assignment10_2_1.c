#include <stdio.h>

void square(double *pd);

int main() {
	double dvar;
	scanf("%lf", &dvar);

	square(&dvar);
	printf("%.6f\n", dvar);

	return 0;
}

void square(double *pd) {
	*pd *= *pd;
}
