#include <stdio.h>

int main(void) {
	int answer = 38, correct = 0;
	int tries;

	printf("I'm thinking of a number between and including 1 to 100.\n");
	printf("Can you guess the number in 6 tries?\n");

	for (tries = 1; tries<=6; tries++) {
		int guess;
		printf("Enter guess number %d: ", tries);
		scanf("%d", &guess);

		if (guess == answer) {
			printf("That's Correct!\n");
			return 0;
		} else if (guess > answer) {
			printf("Too high!\n");
		} else {
			printf("Too low!\n");
		}
	}

	printf("Sorry, bye bye~\n");
}
