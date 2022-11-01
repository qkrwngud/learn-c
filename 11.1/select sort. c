#include<stdio.h>

main(){
	int m, temp;
	int c[] = {1, 2, 8, 3, 4, 7};
	
	for(int i = 2; i < 5; i ++)
	{
		m = i;
		for(int j = i + 1; j < 6; j ++)
		{
			if(c[j] < c[m]) m = j;
		}
		temp = c[i];
		c[i] = c[m];
		c[m] = temp;
	}
	for(int i = 0; i < 6; i ++)
		printf("%3d", c[i]);
}
