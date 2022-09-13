#include<stdio.h>

int mingyul(int a){
	int sum = 1;
	for(int i = 1; i < a + 1; i++){
		sum *= i;
	}
	return sum;
}
main(){
	int a;
	scanf("%d", &a);
	printf("%d", mingyul(a));
}
