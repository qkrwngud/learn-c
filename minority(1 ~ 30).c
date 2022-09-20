#include<stdio.h>

main(){
	int a, b, su[31];
	
	for(a = 0; a <= 30; a++)
		su[a] = 0;
	for(a = 2; a <= 30; a++)
	{
		if(su[a] == 0){
			printf("%3d", a);
			for(b = 2; b * a <= 30; b++)
				su[a * b] = 1;
		}
	}
}
