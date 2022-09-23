#include<stdio.h>

main(){
	int arr[10] = {12, 45, 23, 67, 34, 24, 33, 5, 99, 78};
	int max;
	
	for(int i = 0; i < 10; i ++)
	{
		if(arr[i] > max)
			max = arr[i];
	}
	printf("%d", max);
	
}
