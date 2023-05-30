#include <stdio.h>
#include <string.h>

int palindrome(const char* str, int start, int end);

int main(void) {
	char str[10];
	scanf("%s", str);

	int len = strlen(str);
	printf("%d\n", palindrome(str, 0, len-1));
	return 0;
}

int palindrome(const char* str, int start, int end) {
	if (start == end) return 1;
	if (str[start] != str[end]) return 0;

	return palindrome(str, start+1, end-1);
}
