#include<stdio.h>
int p(int a, int b){
	if(a > b)
		return a - b;
	else
		return b - a;
}
main(){
	 int c, d, e;
	 scanf("%d %d", &c, &d);
	 e = p(c, d);
	 printf("%d", e);
}
