#include<stdio.h>

int main()
{
	int left = 0, right = 0, mid = 0, a = 0;
	
	int data[] = {180, 177, 169, 157, 153, 146};
	
	right = 5;
	
	while(a < 3)
	{
		a ++;
		mid = (left + right) / 2;
		printf(" %d", data[mid]);
		left = mid + 1;
	}
} 
