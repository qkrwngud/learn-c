#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
	srand((unsigned)time(NULL));
	
	int num[10];
	int min, temp;
	
	for(int i = 0; i < 10; i ++)
	{
		num[i] = rand() % 20 + 21;
	}
	
	
	for(int i = 0; i < 4; i ++)
	{
		min = i;
		for(int j = i + 1; j < 5; j ++)
			if(num[j] < num[min]) min = j;
			
		temp = num[i];
		num[i] = num[min];
		num[min] = temp;
		
		printf("\n%d 회전\n", i + 1);
		for(int j = 0; j < 5; j ++)
			printf("%3d", num[j]);
	}
}
