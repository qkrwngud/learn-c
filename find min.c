#include<stdio.h>

main(){
	int arr[10] = {12, 45, 23, 67, 34, 24, 33, 5, 99, 78};
	int min;
	
	min = arr[0];
	
	for(int i = 0; i < 10; i ++)
	{
		if(arr[i] < min)
			min = arr[i];
	}
	printf("%d", min);
}
