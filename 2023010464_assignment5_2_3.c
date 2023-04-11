#include <stdio.h>

int main(void) {
	int num, i, j;

	printf("Height : ");
	scanf("%d", &num);

	for (i=0; i<num; i++) {
		for (j=num-i; j>0; j--) {
			printf("*");
		}
		printf("\n");
	}
}
