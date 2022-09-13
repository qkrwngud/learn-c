#include<stdio.h>

main(){
	
	for(int i = 1; i < 22; i ++){
		printf("---%d단---\n", i);
		for(int j = 1; j < 10; j ++){
			printf("%d X %d = %d\n", i, j, i * j);
		}
		printf("\n");
	}
}
