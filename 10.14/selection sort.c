#include<stdio.h>

main(){
	// 메모리를 많이 먹음
	int a, b, min, temp;
	
	int c[5] = {5, 2, 8, 3, 1};
	
	for(a = 0; a < 4; a ++)
	{
		min=a;
		for(b = a + 1; b < 5; b ++)
		{
			if(c[b] < c[min]) min = b;
		}
		temp = c[a];
		c[a] = c[min];
		c[min]=temp;
		
		printf("\n%d회전\n", a + 1);
		for(b = 0; b < 5; b ++)
			printf("%3d", c[b]);
	}
}
