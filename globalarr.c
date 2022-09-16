#include<stdio.h>
int d[2] = {0,};
// 전역변수인 배열에 함수로 값을 추가한후 메인에서 출력 
void Func2(int a, int b){ 
	int k = 0;
	
	while(a != 0){
		d[k] = a % b;
		a = a/ b;
		k++;
	}
}
main(){
	int m = 1;
	Func2(7, 3);
	while(m >= 0){
		printf("%d", d[m]);
		m--;
	}
}
