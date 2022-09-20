#include<stdio.h>

main(){
	int pr[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	int k = 0, m;
	
	scanf("%d", &m);
	
	while(1){
		if(m == 1) break;
		
		if(m % pr[k] == 0){
			printf("%3d", pr[k]);
			m = m / pr[k];
		}
		else if(m % pr[k] != 0){
			k++;
		}
	}
}
