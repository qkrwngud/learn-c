#include<stdio.h>

main(){
	int a = 0, su;
	int dat[8] = {9, 32, 134, 25, 44, 82, 87};
	
	scanf("%d", &su);
	dat[7] = su;
	
	while(dat[a] != su)
		a++;
	if(a < 7)
		printf("%d번째에 있음\n", a + 1);
	else
		printf("찾을 수 없음\n");
}
