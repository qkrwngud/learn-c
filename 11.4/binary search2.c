#include<stdio.h>

int a[] = {0, 40, 20, 60, 10, 30, 50, 70};
int s = 8;

int search(int x)
{
	int b = 1;
	while(b < s)
	{
		if(a[b] == x)
			return b;
		else if(a[b] > x)
			b*=2;
		else
			b = b * 2 + 1;
	}
	return -1;
}

main(){
	printf("%d", search(30));
}
