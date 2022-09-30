#include<stdio.h>
// Greatest Common Divisor = GCD
// 최대공약수
main(){
	int x, y, temp;
	scanf("%d %d", &x, &y);
	
	while(1)
	{
		if(y > x)
		{
			temp = x;
			x = y;
			y = temp;
		}
		x-=y;
		if(x == 0)
		{
			printf("%d", y);
			break;
		}
	}
}
