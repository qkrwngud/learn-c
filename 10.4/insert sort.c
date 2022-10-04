#include<stdio.h>

main(){
	int temp, i, j;
	int a[5] = {2, 6, 1, 9, 5};
	
	for(i = 1; i < 5; i ++)
	{
		temp = a[i];
		for(j = i - 1; j >= 0; j --)
		{
			if(a[j] > temp)
				a[j + 1] = a[j];
			else
				break;
		}
		a[j + 1] = temp;
		printf("\n%d 회전\n", i);
		for(int j = 0; j < 5; j++)
			printf("%3d", a[j]);
	}
}
