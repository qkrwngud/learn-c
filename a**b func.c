#include<stdio.h>
int power(int m, int n){
	if(n==0){
		return 1;
	}
	else
	{
		return m * power(m, n-1);
	}
}
main(){
	int a = 5, b = 3, sum;
	sum = power(a, b);
	printf("%d", sum);
}
// a의 b
