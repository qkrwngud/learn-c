#include<stdio.h>

int main(){
	int score[5][6] = {0, };

	//입력 
	for(int i = 0; i < 5; i ++)
	{
		printf("%d번째 학생 점수\n", i + 1);
		
		for(int j = 0; j < 4; j ++)
		{
			scanf("%d", &score[i][j]);
			
			// 합계 
			score[i][4] += score[i][j];
		}
	}
	
	// 평균 
	for(int i = 0; i < 5; i ++)
	{
		score[i][5] = score[i][4] / 4;
	}
	
	printf("\t국어\t영어\t수학\t프로\t합계\t평균\n");
	
	for(int i = 0; i < 5; i ++)
	{
		printf("%d번\t", i + 1);
		for(int j = 0; j < 6; j ++)
		{
			printf("%4d\t", score[i][j]);
		}
		printf("\n");
	}
}
