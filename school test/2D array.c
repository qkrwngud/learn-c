#include<stdio.h>

int main() {

	int arr1[2][3]; // 선언

	/*
		앞에 숫자 => 세로길이
		뒤에 숫자 => 가로길이
		
		ex)  0 0 0
	             0 0 0
	*/


	// 선언과 동시에 초기화
	int arr[2][3] = {
		{11, 22, 33},
		{44, 55, 66}
	};
	int arr2[2][3] = {11, 22, 33, 44, 55, 66};

	//배열값 출력
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
		}
	}
	printf("\n\n");


	//예제


	//최댓값구하기
	int max = 0; // 최댓값을 저장할 변수

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
			}
		}
	}
	printf("max = %d\n\n", max);


	//배열의 특정위치의 값 출력 arr[1][1] = 5
	printf("arr[1][1] = %d\n", arr[1][1]);

	//합   arr[0][0] = 1   arr[1][0] = 4
	printf("arr[0][0] + arr[1][0] = %d\n\n", arr[0][0] + arr[1][0]);


	//짝수인값만 더하기
	int sum = 0; //합을 저장할 변수
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] % 2 == 0) // 2를 3으로 바꾸면 홀수의 합
			{
				sum += arr[i][j];
			}
		}
	}
	printf("sum = %d\n\n", sum); // 출력
}
