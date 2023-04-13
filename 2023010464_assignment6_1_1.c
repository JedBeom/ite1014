#include <stdio.h>

int main(void) {
	int pass, fail;
	pass = 0;
	fail = 0;

	for (int i=0; i<10; i++) {
		int result;
		printf("Enter result (1 = pass, 2 = fail) :\n");
		scanf("%d", &result);

		if (result == 1) {
			pass++;
		} else {
			fail++;
		}
	}

	printf("Passed = %d\nFailed = %d\n", pass, fail);
}
