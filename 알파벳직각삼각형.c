#include<stdio.h>
#include<string.h>

main(){
	int a, b, k;
	char ch[30] = "abcde";
	k = strlen(ch);
//	층수(5층) 
	for(a = 0; a <= k -1; a++){
//		각층에 어떤것을 출력할지(문자열의 맨 뒤에서부터 값을 가져오기) 
		for(b = k -a -1; b <= k -1; b++){
			printf("%c", ch[b]);
		}
		printf("\n");
	}
}
