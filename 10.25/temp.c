#include<stdio.h>

main(){
	int temp;
	int k[5] = {51, 9, 22, 6, 15};
	
	for(int i = 1; i < 4; i ++)
	{
		for(int j = i + 1; j < 5; j ++)
		{
			if(k[i] < k[j])
			{
				temp = k[i];
				k[i] = k[j];
				k[j] = temp;
			}
		}
	}
	printf("%d", k[3]);
}
