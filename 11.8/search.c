#include<stdio.h>

main(){
	int a, num;
	
	int d[7] = {22, 19, 32, 12, 53, 24, 32};
	a = 0;
	
	scanf("%d", &num);
	while(d[a] !=num)
	{
		a++;
	}
	if(a <= 6)
	{
		printf("%d번째에 있음\n", a + 1);
	}
}
