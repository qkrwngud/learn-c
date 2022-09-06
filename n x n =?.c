#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
	int a, b, dap;
	
	srand((unsigned)time(NULL));
	
	a = rand() % 9 + 1;	
	b = rand() % 9 + 1;
	
	printf("%d x %d = ", a, b);
	scanf("%d", &dap);
	if(dap == a * b)
		printf("맞습니다");
	else
		printf("틀렸습니다");
}
