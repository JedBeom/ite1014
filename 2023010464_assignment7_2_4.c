#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE_MIN 1
#define RANGE_MAX 1000

int main() {
	int min = RANGE_MAX, max = RANGE_MIN;
	int num = 0;
	
	srand(time(NULL));
	for (int i=0; i<10; i++) {

		num = rand() % RANGE_MAX + RANGE_MIN;
		printf("%d ", num);
		
		if (num > max) {
			max = num;
		}

		if (num < min) {
			min = num;
		}
	}

	printf("\n");
	printf("Maximum number is %d\n", max);
	printf("Minimum number is %d\n", min);
}
