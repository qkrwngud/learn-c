#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 배열 + 함수 + 정렬 + 탐색나올예정


void bubbleSort(int array[], int cnt);

int main(){
	int num[10];
	int len = 10;
	
	srand((unsigned)time(NULL));
	
	for(int i = 0; i < len; i ++)
	{
		num[i] = rand() % 100 + 1;
	}
	
	printf("초기배열");
	for(int i = 0; i < len; i ++)
	{
		printf("%3d", num[i]);
	}
	printf("\n\n");
	
	bubbleSort(num, len);
}

void bubbleSort(int array[], int cnt)
{
	int temp = 0;
	
	for(int i = 0; i < cnt - 1; i ++)
	{
		for(int j = 0; j < cnt - i - 1; j ++)
		{
			if(array[j] > array[j + 1])
			{
				if(array[j] > array[j + 1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
		}
		
		printf("%d번쨰 결과", i + 1);
		for(int j = 0; j < cnt; j ++)
		{
			printf("%3d", array[j]);
		}
		printf("\n");
	}
	
	printf("\n결과");
	for(int j = 0; j < cnt; j ++)
	{
		printf("%3d", array[j]);
	}
}
