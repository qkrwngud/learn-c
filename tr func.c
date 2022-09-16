#include<stdio.h>
void tr(int m){
	int k, n;
	for(n = 1; n <= m; n++){
		for(k = 1; k <=n; k++)
			printf("♣");
		printf("\n");
	}
}
main(){
	int a;
	printf("숫자입력 : ");
	scanf("%d", &a);
	tr(a);
} 
