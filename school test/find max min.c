#include<stdio.h>
#include<stdlib.h>
#include<time.h>


// 2차원 배열

int main() {

	// 랜덤(1 ~ 10) 으로 배열값넣고 최댓값과 최솟값찾기

	srand((unsigned)time(NULL));

	int arr[5][5] = {0, };
	int max = 0, min = 100;


	//랜덤으로 배열값채우기
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] = rand() % 10 + 1;
			printf("%2d", arr[i][j]); // 배열 출력 
		}
		printf("\n");
	}

	// 최댓값과 최솟값 찾기
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
			}
			if (arr[i][j] < min)
			{
				min = arr[i][j];
			}
		}
	}
	printf("max = %d\n", max);
	printf("min = %d\n", min);
}
