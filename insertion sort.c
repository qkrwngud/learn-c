#include<stdio.h>

main(){
	int arr[10] = {12, 45, 23, 67, 34, 24, 33, 5, 99, 78};
	int temp;
	
	for(int i = 0; i < 10; i ++)
	{
		for(int j = i + 1; j < 10; j ++)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for(int i = 0; i < 10; i ++)
		printf("%3d", arr[i]);
}
