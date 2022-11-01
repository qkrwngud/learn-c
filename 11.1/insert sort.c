#include<stdio.h>

main(){
	int temp;
	int d[] = {11, 44, 22, 55, 33};
	for(int i = 1; i < 4; i ++)
	{
		for(int j = i + 1; j < 5; j ++)
		{
			if(d[i] > d[j])
			{
				temp = d[i];
				d[i] = d[j];
				d[j] = temp;
			}
		}
	}
	printf("%3d", d[1]);
}
