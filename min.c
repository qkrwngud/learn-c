#include<stdio.h>

main(){
	int b, m = 32767;
	
	int a[6] = {82, 13, 54, 66, 48, 78};
	
	for(b = 0; b < 6; b++)
	{
		if(a[b] < m)
			m = a[b];
	}
	printf("%d", m);
}
