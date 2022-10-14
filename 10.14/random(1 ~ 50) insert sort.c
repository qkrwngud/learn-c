#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// 오름차순
main(){
	
	srand((unsigned)time(NULL));
	
	int m, n;
	int num[10];
	int temp;
	
	for(int i = 0; i < 10; i ++)
		num[i] = rand() % 50 + 1; 
		
	for(m=1;m<10;m++)
	{
		temp=num[m];
		for(n=m-1;n>-1;n--)
		{
			if(num[n]>temp)
				num[n+1] = num[n];
			else
				break;
		}
		num[n+1]=temp;
		printf("\n%d 회전\n", m);
		for(n=0;n<10;n++)
			printf("%3d", num[n]);
	}
}
