/*
구구단의 단수를 입력받고, 해당하는 단수를
모두 출력한다.
*/
#include <stdio.h>

int main(void) {
    int dan, i;
    while(1) {
        printf("단수를 입력하시오 : \n");
        scanf("%d", &dan);

        printf("**********%d단**********\n", dan);
        for (i=1; i<10; i++) {
            printf("%d*%d= %d\n", dan, i, dan*i);
        }
        printf("***********************\n");
    }
}
