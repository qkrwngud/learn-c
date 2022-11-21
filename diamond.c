#include<stdio.h>

int main() {
    int num = 0;

    scanf_s("%d", &num);

    // 다이아몬드(제일 위에 for문 뺴고 안에는 동일)

    for (int i = 0; i < num; i++) 
    {
        for (int j = i; j < num - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i * 2; j++)
        {
            printf("*");
        }
        printf("\n");

    }
    for (int i = num - 2; i > -1; i--) 
    {
        for (int j = i; j < num - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i * 2; j++)
        {
            printf("*");
        }
        printf("\n");

    }
}
