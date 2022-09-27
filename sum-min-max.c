#include<stdio.h>

main(){
	int a, b, s;
	int dt[7] = {18, 29, 14, 7, 3, 17, 8};
	
	a = b = s = dt[0];
	
	for(int i = 1; i < 7; i ++)
	{
		s+=dt[i];
		if(a < dt[i])
			a = dt[i];
		if(b > dt[i])
			b = dt[i];
	}
	printf("%3d", s-a-b);
}
// sum(dt) - min(dt) - max(dt)
