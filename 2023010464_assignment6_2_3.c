#include <stdio.h>

int main() {
	int i, j, blank, star;
	
	for (i=0; i<9; i++) {
		j = i;
		if (i>4) {
			j = 8 - j; // reverse
		}

		for (blank=0; blank<(4-j); blank++) {
			printf(" ");
		}
		for (star=0; star<(2*j+1); star++) {
			printf("*");
		}
		printf("\n");
	}
}
