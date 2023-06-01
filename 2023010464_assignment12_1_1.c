#include <stdio.h>
#include <string.h>
#include <math.h>

int convertDigit(char* num, int n, int k);
int atoiRange(const char str[], int start, int end);
int isPrime(int n);
int solution(int n, int k);

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);

	printf("%d\n", solution(n, k));
	return 0;
}

int solution(int n, int k) {
	char str[21];
	convertDigit(str, n, k);

	int len = strlen(str);
	int start = 0, cursor = 0, primeCount = 0;

	for (; cursor <= len; cursor++) {
		if (str[cursor] == '0' || str[cursor] == '\0') {
			int num = atoiRange(str, start, cursor); // num = int(str[start:cursor])
			if (isPrime(num)) {
				primeCount++;
			}
			start = cursor+1;
		}
	}

	return primeCount;
}

int isPrime(int n) {
	if (n < 2) return 0;

	for (int i=2; i<n; i++) {
		if (n%i==0) {
			return 0;
		}
	}

	return 1;
}

int atoiRange(const char str[], int start, int end) {
	char substr[21]; // 이 함수가 반복 호출될 때 이전에 사용하던 값을 그대로 쓰는듯
					 // 21: 20 is the length of binary number converted from 1,000,000

	strncpy(substr, str+start, end-start); // strncpy does not insert null terminator
	substr[end-start] = '\0'; // insert '\0' to the end of substr
							  // substr = str[start:end]

	int len = strlen(substr), num = 0;
	for (int i=0; i<len; i++) { // num = int(substr)
		num += (substr[i]-'0') * (int)pow(10, len-i-1);
	}

	return num;
}

int convertDigit(char* num, int n, int k) {
	int index = 0, tmp;

	while (n>0) { // add remainders to num
		num[index] = n%k +'0';
		n /= k;
		index++;
	}
	num[index] = '\0'; // add null terminator to the end of num

	int len = strlen(num);
 	for (index = 0; index < (len/2); index++) { // num.reverse()
		tmp = num[index];
		num[index] = num[len-index-1];
		num[len-index-1] = tmp;
	}

	return 0;
}
