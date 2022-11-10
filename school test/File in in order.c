#include<stdio.h>

int main() {
	
	// 순서대로 숫자 넣기(크기 n X n) 
	
	int n = 0, num = 1;

	scanf("%d", &n);

	int arr[n][n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[j][i] = num;
			num ++;
		}
	}
	
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
