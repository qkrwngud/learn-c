#include<stdio.h>

main(){
	int a[5] = {15, 12, 28, 13, 7};
	int k = 1, m;
	
	m = a[0];
	
	while(k < 5)
	{	
		if(m < a[k])
		{
			m = a[k];
		}
		k++;
	}
	printf("%d", m);
}
