#include<stdio.h>

main(){
	int a = 0, su;
	int data[7] = {9, 32, 134, 25, 44, 82, 87};
	
	scanf("%d", &su);
	
	while(a < 7 && data[a] != su)
		a++;
		
	if(a < 7)
		printf("%d번째에 있음\n", a + 1);
	else
		printf("찾을수없음");
}
