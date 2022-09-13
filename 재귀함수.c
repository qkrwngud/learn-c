#include<stdio.h>
 
long fac(int da){
	if(da == 1)
		return 1;
	else
		return da * fac(da - 1);
}
main(){
	int a = 60;
	long re;
	re = fac(a);
	printf("%ld", re);
}
