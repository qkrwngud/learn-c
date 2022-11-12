#include<stdio.h>
//오름차순 정렬(버블)후 num값 찾고 위치 

void func(int arr[], int num);

main(){
	int arr[] = {5, 3, 7, 1, 8, 4, 2};
	int num = 5;
	
	func(arr, num);
}

void func(int arr[], int num)
{
	int temp = 0;
	
	for(int i = 0; i < 6; i ++)
	{
		for(int j = i + 1; j < 7; j ++)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	for(int i = 0; i < 7; i ++)
	{
		printf("%3d", arr[i]);
	}
	
	for(int i = 0; i < 7; i ++)
	{
		if(arr[i] == num)
		{
			printf("\n%d번째", i);
		}
	}
	
}
