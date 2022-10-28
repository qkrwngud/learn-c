#include<stdio.h>

main(){
	// 삽입정렬 
	int a, b, t;
	int d[] = {32, 55, 21, 19, 54, 33};
	
	for(a = 1; a < 6; a ++)
	{
		t = d[a];
		b = a - 1;
		
		while(b > -1 && t > d[b])
		{
			d[b + 1] = d[b];
			b--;
		}
		d[b + 1] = t;
	}
	printf("%d", d[1]);
}
