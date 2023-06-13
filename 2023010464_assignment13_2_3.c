#include <stdio.h>

void printArray(char** arr, int len);
int swap(char*** arr);

int main(void) {
	const char* arr[2] = {"aaa", "bbb"};
	printArray(&arr, 2);
	swap(arr);
	printArray(&arr, 2);
}

void printArray(char** arr, int len) {
	printf("Array ");
	for (int i=0; i<len; i++) {
		printf("[%d]:%s, ", i, arr[i]);
	}
	printf("\n");
}

int swap(char*** arr) {
	char* tmp;
	tmp = *arr;
	*arr = *(arr+1);
	*(arr+1) = tmp;
	return 0;
}
