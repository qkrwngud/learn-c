#include<stdio.h>

int main()
{
	int a[2][3] = { 1, 2, 3, 4, 5, 6 };
	int b[2][3] = { 10, 9, 8, 3, 2, 1 };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 2; j > -1; j--)
		{
			b[i][j] %= a[i][j];
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
}
