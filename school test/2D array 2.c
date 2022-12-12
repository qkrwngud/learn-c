#include<stdio.h>

// 기말 3~4번문제

int main()
{
	int n = 1;
	int num[3][3] = { 0, };

	for (int i = 0; i < 3; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 2; j > -1; j--)
			{
				num[i][j] = n;
				n++;
			}
		}
		else
		{
			for (int j = 0; j < 3; j++)
			{
				num[i][j] = n;
				n++;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", num[i][j]);
		}
		printf("\n");
	}
	printf("%d", n);
}
