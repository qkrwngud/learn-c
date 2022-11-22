#include<stdio.h>

int main()
{
	int dit[8], k, sum = 0, wg = 1;
	char str[9];
	
	printf("2진수입력: ");
	scanf("%s", str);
	
	for(int i = 0; i < 8; i ++)
	{
		if(str[i] == '1')
		{
			dit[i] = 1;
		}
		else
		{
			dit[i] = 0;
		}
	}
	for(int i = 7; i > -1; i --)
	{
		sum = sum + wg*dit[i];
		wg = wg * 2;
	}
	printf("\n10진수는 %d", sum);
}
