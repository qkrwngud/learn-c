#include<stdio.h>
// 최대공약수
main(){
	int x, y, temp;
	
	scanf("%d %d", &x, &y);
	
	while(1)
	{
		temp = x % y;
		x = y;
		y = temp;
		
		if(y == 0)
			break;
	}
	printf("최대 공약수 => %d\n", x);
}
