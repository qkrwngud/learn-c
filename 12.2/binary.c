#include<stdio.h>
#include<string.h>

// 2진수 -> 8진수

int main()
{
	char str[101];
	
	int dit[101], num[30], mm = 1, k, cnt, sum = 0, n = 0, loop = 0;
	
	printf("2진수 입력: ");
	scanf("%s", &str);
	cnt = strlen(str);
	
	for( k = 0; k < cnt; k ++)
	{
		if(str[k] == '1')
			dit[k] = 1;
		else
			dit[k] = 0;
	}
	
	for(k = cnt - 1; k > -1; k --)
	{
		sum+= mm * dit[k];
		mm*= 2;
		loop++;
		
		if(loop % 3 == 0)
		{
			num[n] = sum;
			n++;
			sum = 0, mm = 1, loop = 0;
		}
	}
	
	if(loop % 3 != 0)
	{
		num[n] = sum;
	}
	else
	{
		n--;
	}
	for(k = n; k > -1; k --)
	{
		printf("%3d", num[k]);
	}
	
}
