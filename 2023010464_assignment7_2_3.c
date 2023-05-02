#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 45

int main(void) {
	printf("You can win the first prize at lotto !!\n");
	
	srand(time(NULL));
	
	for (int i=0; i<6; i++) {
		printf("%d ", rand() % MAX + MIN);
	}
	printf("\n");
}
