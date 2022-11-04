#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
	srand((unsigned)time(NULL));
	
	int a, left, right, mid, num, random_num;
	int d[9];
	
	// 중복값제거 
	for(int i = 0; i < 8; i ++)
	{
		random_num = rand() % 100 + 1;
		if(i != 0)
		{
			for(int j = 0; j <  i + 1; j ++)
			{
				if(random_num == d[j])
				{
					random_num = rand() % 100 + 1;
					j = -1;
				}
			}
		}
		d[i] = random_num;
	}
	num = rand() % 100 + 1;
	 
	
	
	printf("d배열값: ");
	for(int i = 0; i < 9; i ++)
	{
		printf("%d  ", d[i]);
	} 
	printf("\n num값 %d\n", num);
	
	
	left = a = 0;
	right = 8;
	
	
	while(1)
	{
		if(right - left > -1)
		{
			a++;
			mid = (left + right) / 2;
			
			if(num == d[mid])
			{
				printf("%d번째에 있음\n", mid + 1);
				printf("%d번 수행\n", a);
				break;
			}
			if(num > d[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}
		else
		{
			printf("찾을수 없음\n");
			break;
		}
	}
}
