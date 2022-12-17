#include<stdio.h>

int main()
{
	int cnt = 0, num = 0;
	
	scanf_s("%d", &num);

	for (int i = 2; i < num + 1; i++)
	{
		cnt = 0;
	
		for (int j = 2; j < i + 1; j++)
		{
			if (i % j == 0)
			{
				cnt++;
			}
		}

		if (cnt == 1)
		{
			printf("%d ", i);
		}

	}
}
