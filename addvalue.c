#include<stdio.h>
int addvalue(int x, int y){
	x +=3;
	y-=10;
	if (x > y)
		return x;
	else
		return y;
}
main(){
	int x, y, z;
	scanf("%d %d", &x, &y);
	z = addvalue(x, y);
	printf("%d %d %d", x, y, z);
}
