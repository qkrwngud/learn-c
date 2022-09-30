#include<stdio.h>

main(){
	int a, n;
	scanf("%d", &n);
	a = 2;
	while(n / 2 >= a)
	{
		if(n % a == 0)
		{
			printf("%3d", a);
			n /=a;
		}
		else
			a++;
	}
	printf("%3d", n);
}
// 소인수분해
