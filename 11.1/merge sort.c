#include<stdio.h>

main(){
	// 두 배열을 비교해서 오름차순 정렬
	// 345678
	int a[3] = {3, 6, 7};
	int b[3] = {4, 5, 8};
	int c[6];
	
	int m = 0, n = 0, p = 0;
	
	while(m < 3 && n < 3)
	{
		if(a[m] < b[n])
		{
			c[p] = a[m];
			p++;
			m++;
		}
		else
		{
			c[p] = b[n];
			p++;
			n++;
		}
	}
	while(m < 3)
	{
		c[p] = a[m];
		p++;
		m++;
	}
	while(n < 3)
	{
		c[p] = b[n];
		p++;
		n++;
	}
	
	for(int i =0; i < 6; i ++)
	{
		printf("%3d", c[i]);
	}
}
