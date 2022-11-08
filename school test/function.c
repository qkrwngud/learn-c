#include<stdio.h>

/*
	int a, int b는 파라미터로
	함수를 호출할때 소괄호에 값을 넣으면 순서대로 a, b에 들어간다

	ex) add(4, 1);  a = 4, b = 1;
*/


void add(int a, int b); //void는 리턴값이 없다
int sub(int a, int b); // 실수형은 리턴값이 있다
void max_min(int a, int b);
int mul(int a, int b);

int main() {
	//함수 호출

	add(4, 1); // 리턴값이 없어서 바로 출력

	int c = sub(5, 3); // sub(a, b)를 저장할 변수
	printf("sub = %d\n\n", c);

	max_min(5, 3); // max와 min 구하는 함수
	printf("\n");

	printf("mul = %d\n\n", mul(4, 2));
}


int sub(int a, int b)
{
	return a - b; // 리턴값은 sub(a, b); 가 a - b가 되는것이다
}

void add(int a, int b)
{
	printf("add = %d\n", a + b);
}

void max_min(int a, int b)
{
	if (a > b)
	{
		printf("max = %d\n", a);
		printf("min = %d\n", b);
	}
	else if (a < b)
	{
		printf("max = %d\n", b);
		printf("min = %d\n", a);
	}
	else
	{
		printf("%d == %d\n", a, b);
	}
}

int mul(int a, int b)
{
	return a * b;
}
