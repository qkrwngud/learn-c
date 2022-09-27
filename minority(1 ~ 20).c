#include<stdio.h>

main(){
//	소수출력 
	int m;
	static int n[21];
	
	for(int i = 2; i < 21; i ++)
	{
		if(n[i] == 0)
			printf("%3d", i);
		for(m = 2 * i; m < 21; m+=i)
			n[m] = 1;
	}
}
