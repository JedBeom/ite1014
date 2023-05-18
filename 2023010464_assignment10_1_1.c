#include <stdio.h>
#include <string.h>

int isPalindrome(const char str[]);

int main(void) {
	char str[10];
	scanf("%s", str);

	printf("%d\n", isPalindrome(str));
}

int isPalindrome(const char str[]) {
	int len = strlen(str);
	for (int i=0; i<len; i++) {
		if (str[i] != str[len-i-1]) return 0;
	}

	return 1;
}

