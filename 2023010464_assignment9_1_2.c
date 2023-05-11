#include <stdio.h>

int main() {
	int i, a[5], tmp;

	for (i=0; i<5; i++) {
		scanf("%d", a+i);
	}
	
	for (i=0; i<5/2; i++) {
		tmp = *(a+i) ;
		*(a+i) = *(a+4-i);
		*(a+4-i) = tmp;
	}

	for (i=0; i<5; i++) {
		printf("%d ", *(a+i));
	}
	printf("\n");
}
		
