#include<stdio.h>

main(){
	int arr[10] = {12, 45, 23, 67, 34, 24, 33, 5, 99, 78};
	int temp;
//	삽입정렬 
	for(int i = 1; i < 10; i ++)
	{
		for(int j = i; j > 0; j --)
		{
			if(arr[j - 1] > arr[j])
			{
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for(int i = 0; i < 10; i ++)
		printf("%3d", arr[i]);
}
