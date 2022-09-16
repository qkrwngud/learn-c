#include<stdio.h>
int a, b, c;

int fun(int b, int c){
	a +=10;
	b +=10;
	c +=10;
	return a;
}

main(){
	int a=3, b=5, c = 7;
	a = fun(b, c);
	printf("%2d %2d %2d\n", a, b, c);
}
