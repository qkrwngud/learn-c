#include<stdio.h>
// 약수구하기
main(){
	int x;
	scanf("%d", &x);
	
	for(int i = 1; i < x; i ++)
	{
		if(x % i == 0)
			printf("약수: %d\n", x / i);
	}
	printf("약수: 1");
}
