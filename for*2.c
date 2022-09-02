#include<stdio.h>

main(){
	int i, j, s;
	for(i=10; i<=50; i+=10){
		for(j=1; j<=i; j++){
			s+=j;
		}
		printf("sum(%d) = %d\n", i, s);
		s=0;
	}
}
