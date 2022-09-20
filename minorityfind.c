#include<stdio.h>

main(){
	int k, m = 2;
	
	scanf("%d", &k);
	while(1){
		
		if(k <= m){
			printf("k는 소수이다");
			break;
		}
		
		else if(k % m == 0){
			printf("k는 소수가 아니다");
			break;
		}
		
		else
			m ++;
	}
}
