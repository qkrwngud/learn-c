#include<stdio.h>

main() {
	int a, b, c, d;
	int arr[] = {46, 52, 57, 60, 63, 64, 76};
	
	a = b = 0;
	c = 6;
	
	while(a <= 2)
	{
		a+=1;
		d = (b + c) / 2;
		b = d + 1;
	}
	printf("%d", arr[d]);
}
