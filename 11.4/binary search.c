#include<stdio.h>
	
main(){
	int m, a = 1, b = 10, d, cnt = 1;
	
	printf("입력=");
	
	scanf("%d", &m);
	
	d = (a + b) / 2;
	
	while(d != m)
	{
		if(d > m)
		{
			b = d - 1;
		}
		else
		{
			a = d + 1;
		}
		
		cnt++;
		d = (a + b)/2;  
	}
	printf("%d", cnt);
}
