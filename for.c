#include<stdio.h>

int a;
int sum(int c){
	int d = 0;
	a +=c;
	d +=c;
	return d;
}
main(){
	int b, r;
	a = 1;
	
	for(b = 1; b <= 2; b++){
		r = sum(b);
		printf("%d %d %d\n", a, b, r);
	}
}
