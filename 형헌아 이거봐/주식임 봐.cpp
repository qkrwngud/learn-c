#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<string>

using namespace std;

float jkmoney[3] = {10000, 20000, 30000};


void stock()
{	
	srand((unsigned)time(NULL));
	
	int random[3];
	
	// 주식 돈 배열 
	
	float updown[3] = {0, };
	
	// 배율 
	const float sik[] = {1.2, 1.5, 1.8, 0.5, 1.0, 0.2, 0.8};                                       
	
	for(int i = 0; i < 3; i ++)
	{
		random[i] = rand() % 7;
		updown[i] = (jkmoney[i] * sik[random[i]]) - jkmoney[i];
		jkmoney[i] *= sik[random[i]];
	}
	
	//바뀐 금액|오르거나 내려간 금액|▲▼n%
	for(int i = 0; i < 3; i ++)
	{
		if(updown[i] >= 0)
			printf("stock%d: %.1f  |  %.1f  | ▲%.1f%\n\n", i + 1, jkmoney[i], updown[i], sik[random[i]]);
		else if(updown[i] < 0)
			printf("stock%d: %.1f  |  %.1f  | ▼%.1f%\n\n", i + 1, jkmoney[i], updown[i], sik[random[i]]);
	}
	Sleep(7000);
	system("cls");
	
}

main(){
	while(1)
		stock();
}
