#include<stdio.h>

//틀렸음

int prime(int i);

int main() {

	int sum = 0;

	for (int i = 1; i < 6; ++i)
	{
		sum += prime(i); // 1 ~ 5
	}
	
	printf("%d", sum);
}

int prime(int i)
{
	int j = 0;

	for (j = 2; j < i; ++ j)
	{
		if (i % j == 0)
		{
			break;
		}
	}
	if (i == j)
	{
		return i;
	}
	else
	{
		return 0;
	}
}
