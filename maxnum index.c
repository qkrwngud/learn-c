#include<stdio.h>

main(){
// 가장큰수가 입력된 번호찾기
  int num[10], temp=-32768;
	int k = 0;
	
	for(int i = 0; i < 10; i++)
	{
		printf("%2d변수:", i + 1);
		scanf("%d", &num[i]);
		if(temp < num[i])
		{
			temp = num[i];
			k = i + 1;
		}
	}
	 
	printf("%d", k);
}
