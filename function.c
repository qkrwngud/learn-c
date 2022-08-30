#include<stdio.h>
int max(int p, int q){
	if(p > q)
		return p;
	else
		return q;
}
main(){
	int a = 5, b = 3, m;
	m = max(a, b);
	printf("%d", m);
}
