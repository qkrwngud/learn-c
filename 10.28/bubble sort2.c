#include<stdio.h>

main(){
	/* 
		오름차순 버블정렬 
    
    한바퀴만 돌았음
    
		41 32 26 11 55
	*/
	int arr[5] = {55, 41, 32, 26, 11};
	int temp;
	
	for(int i = 0; i < 4; i ++)
	{
			if(arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
	}
	printf("%d", arr[0]);
	
}
