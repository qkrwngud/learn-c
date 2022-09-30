#include<stdio.h>
// 버블정렬 
main(){
	int arr[4] = {8, 3, 5, 1};
	int temp;
	
	for(int i = 0; i < 3; i ++)
	{
		for(int j = i + 1; j < 4; j ++)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		for(int i = 0; i < 4; i ++)
			printf("%d\t", arr[i]);
		printf("\n");
	}
}
