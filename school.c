#include<stdio.h>

main(){
	int num = 0;
	printf("정수를 입력하세요 : ");
	scanf("%d", &num);	
	if (num % 2 == 0){
		printf("even\n");
		printf("%d", num - 2);
	}
	else{
		printf("odd\n");
		printf("%d", num + 3);
	}	
}
