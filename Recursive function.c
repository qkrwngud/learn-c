#include<stdio.h>
// 각자리수의 합을 구하는 함수
int pp(int n){
	if(n ==0)
		return 0;
	else
		return pp(n/10) + n% 10;
}

main(){
	int num;
	scanf("%d", &num);
	printf("%3d", pp(num));
}
