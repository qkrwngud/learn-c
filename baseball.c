#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
	int x, y, z, a, b, c, count;
	
	srand((unsigned)time(NULL));
	x = rand() % 9 + 1;	
	y = rand() % 9 + 1;
	z = rand() % 9 + 1;
	printf("숫자 3개 입력(1 ~ 9)\n");
	scanf("%d %d %d", &a, &b, &c);
	int A[3] = {x, y, z}; 
	int B[3] = {a, b, c};
	
	for(int i = 0; i < 3; i ++){
		if(A[i] == B[i])
			count++;
	}
	if(count == 3)
		printf("홈런!");
	
	else if(count == 2)
		printf("볼");
	else
		printf("스트라이크");
			
}
