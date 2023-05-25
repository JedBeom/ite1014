#include <stdio.h>

void getSumDiff(int a, int b, int* pSum, int* pDiff);

int main() {
int a, b;
int pSum, pDiff;
scanf("%d %d", &a, &b);
getSumDiff(a, b, &pSum, &pDiff);
printf("sum: %d\n", pSum);
printf("diff: %d\n", pDiff);
return 0;
}


void getSumDiff(int a, int b, int* pSum, int* pDiff) {
*pSum = a+b;
*pDiff = a-b;
}