#include<stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void add(int a, int b, int* sum)
{
	*sum = a + b;
}

main() {
//	변수명 앞에 &를 붙여주면 주소를 보냄 
	
	int* p = 0;
	int i = 10;
	p = &i;
	
	printf("%p\n", &i);
	printf("%p\n", p);
	printf("%d\n%d\n", i, *p);


	int arr[] = {10, 20, 30, 40, 50};
	
	printf("%d %d\n", *(arr + 1), *arr);
/*	
	printf("%p\n", a);
	printf("%p\n", a + 1);
	printf("%d\n", *a);
	printf("%d\n", *(a + 1));
*/
	printf("\n");	
	
	
/*	a과 b값을 변경하려면 
	main안에 있는 a와 b의 값을
	변경하려면 a와 b의 주소값을 받아서 
	교환을 해야한다 
*/	

//	주소값받음 
	int a = 10, b = 20;
	printf("%d %d\n", a, b);
	swap(&a, &b);
	printf("%d %d\n", a, b);
	
//	그냥 a1과 b1값을 넘김 
	int a1 = 10, b1 = 20;
	swap1(a1, b1);
	printf("%d %d\n", a1, b1);
	
	
	
/*	a와 b의 값을 sum에 합해서 저장하는 함수 add 
	sum은 main에 있으므로 함수에 sum값을 넘길때 주소를 넘겨야함 
*/
	int sum = 0;
	add(a, b, &sum);
	printf("%d", sum);
}
