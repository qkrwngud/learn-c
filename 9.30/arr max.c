#include<stdio.h>
// 각 배열의 줄마다 최댓값을 모두 구함 
main(){
	int num[3][5] = {
	{2, 6, 4, 3, 1},
	{3, 4, 2, 8, 7},
	{5, 7, 3, 1, 2}
	};
	
	int s = 0, m;
	
	for(int i = 0; i < 3; i++)
	{
		m = 0;
		for(int j = 0; j < 5; j++)
		{
			if(num[i][j] > m)
				m = num[i][j];
		}
		s+=m;
	}
	printf("%d", s);
}
