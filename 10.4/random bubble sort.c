#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// 가장 뒤에서부터 정렬됨
main(){
	
	srand((unsigned)time(NULL));
// static은 배열의 값을 전부 0으로 초기화
	static int arr[10];
	int temp;
	
	for(int i = 0; i < 10; i ++)
	{
		arr[i] = rand() % 50 + 1;
	}
	
	printf("초기값\n");
	
	for(int i = 0; i < 10; i ++)
	{
		printf("%3d", arr[i]);
	}
	printf("\n\n");
	for(int i = 0; i < 10; i ++)
	{
		for(int j = i + 1; j < 10; j ++)
		{
			if(arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	printf("정렬후\n");
	
	for(int i = 0; i < 10; i ++)
	{
		printf("%3d", arr[i]);
	}
	
	
}
