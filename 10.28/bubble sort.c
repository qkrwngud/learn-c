#include<stdio.h>

main(){
  // 버블정렬
	int temp, cnt = 0, tag = 1;
	int a[5] = {54, 43, 11, 24, 45};
	
	while(tag == 1)
	{
		tag = 0;
		for(int i = 0; i < 4; i ++)
		{
			if(a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				tag = 1;
			}
		}
		cnt++;
	}
	for(int i = 0; i < 5; i ++)
	{
		printf("%3d", a[i]);
	}	printf("\n");
	printf("%d", cnt);
}
