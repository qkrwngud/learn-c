#include<stdio.h>

int main()
{
	static int m[4][4] = {
		{15, 25, 35},
		{45, 55, 65},
		{75, 85, 95}
	};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m[i][3] += m[i][j];
			m[3][j] += m[i][j];
		}
	}

	printf("%d\n", m[0][3]);
	printf("%d\n", m[3][2]);
}
