#include<stdio.h>

main(){
	// 선택정렬 
	int num, temp;
	
	char chHole;
	char HL[] = {'A', 'B', 'C', 'D', 'E', 'F'};
	int KG[] = {35, 20, 17, 9, 42, 23};
	
	for(int i = 0; i < 5; i ++)
	{
		num = i;
		for(int j = i + 1; j < 6; j ++)
		{
			if(KG[j] > KG[num])
				num = j;
		}
    // 숫자변경
		temp = KG[i];
		KG[i] = KG[num];
		KG[num] = temp;
		// 숫자에 맞게 문자도 변경
		chHole = HL[i];
		HL[i] = HL[num];
		HL[num] = chHole;
	}
  
	// 출력
	for(int i = 0; i < 6; i ++)
	{
		printf("%2c", HL[i]);
	}
}
