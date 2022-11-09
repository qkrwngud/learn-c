#include<stdio.h>

int main() {
	
	/*
		A □□□□   =>  B □□
		  □□□□         □□
		                   □□
						   □□
	*/

	int A[2][4] = { 1,2,3,4,5,6,7,8 };
	int B[4][2] = { 0, };

	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 2; i++)
		{
			B[j][i] = A[i][j];
		}
	}
		
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
}
