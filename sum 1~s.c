#include<stdio.h>
int ssm(int k){
	if(k == 1)
		return 1;
	else
		return ssm(k-1) + k;
}
main(){
	int s;
	s = ssm(10);
	printf("%d",s);
}
//1~ s까지 더한수를 출력 
