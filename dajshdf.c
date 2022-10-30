#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <mmsystem.h>

#include "cful.h"
#include "maap.h"

#pragma comment(lib, "user32")
#pragma comment(lib,"winmm.lib")

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

using namespace std;

void money(int *mymoney);

void gLoop(int);
void move(int*, int*, int, int);
int keyControl();

void titleDraw();
int menuDraw();
int gamemenuDraw();
void mapDraw(int*, int*);

void gotoxy(int x, int y);
void init();
void uiDraw(int*, int*);




int main () {
		::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); //전체화면 
    init();

    while(1){
		titleDraw();
		int menuCode = menuDraw();
		if(menuCode == 0){
			int n = gamemenuDraw();
			
			if(n == 0) {
			gLoop(0);
		}else if(n == 1){
		}   gLoop(1);
	}else if(menuCode == 1){
		return 0;
	}else if(menuCode == 2){
		
	}
	system("cls");

	int keyCode = keyControl();

	return 0;

}	

}

	





int keyControl(){ //키보드 컨트롤 
	char temp = getch();
	
	if(temp == 'w' || temp == 'W'){
		return UP;
	} else if(temp == 'a' || temp == 'A'){
		return LEFT;
	} else if(temp == 's' || temp == 'S'){
		return DOWN;
	} else if(temp == 'd' || temp == 'D'){
		return RIGHT;
	} else if(temp == ' ' || temp == ' '){ 
		return SUBMIT;
	} 
		
	}


void init(){
	
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);

}




void mapDraw(int* x, int* y){
	system("cls");
	int h, w;
	for(h=0; h<50; h++){
		for(w=0; w<190; w++){
			char temp = tempMap[h][w];
			if(temp == '0'){
				printf(BG_COLOR(0,0,0)" " RESET);//black
			}else if(temp == '1'){
				printf(BG_COLOR(255,0,0)" " RESET);//red
			}else if(temp == '@'){
				*x = w; // 플레이어 좌표값 저장  
				*y = h; 
				printf(BG_COLOR(244,196,173) FG_COLOR(0,0,0)"\"" RESET);
			}else if(temp == '2'){
				printf(BG_COLOR(239,114,69)" " RESET);//orange
			}else if(temp == '3'){
				printf(BG_COLOR(239,211,0)" " RESET);//yellow
			}else if(temp == '4'){
				printf(BG_COLOR(30,181,0)" " RESET);//green
			}else if(temp == '5'){
				printf(BG_COLOR(0,185,226)" " RESET);//cyan
			}else if(temp == '6'){
				printf(BG_COLOR(0,113,226)" " RESET);//blue
			}else if(temp == '7'){
				printf(BG_COLOR(24,35,226)" " RESET);//dark blue
			}else if(temp == '8'){
				printf(BG_COLOR(136,0,0)" " RESET);//purple
			}else if(temp == '9'){
				printf(BG_COLOR(255,255,255)" " RESET);//white
			}else if(temp == 'a'){
				printf(BG_COLOR(204,204,204)" " RESET);//light gray, a~d=concrete wall(gray)
			}else if(temp == 'b'){
				printf(BG_COLOR(173,173,173)" " RESET);//gray
			}else if(temp == 'c'){
				printf(BG_COLOR(127,127,127)" " RESET);//dark gray
			}else if(temp == 'd'){
				printf(BG_COLOR(239,239,239)" " RESET);//very light gray
			}
			
		}
		printf("\n");
	}

}

void gLoop(int mapCode){
	int mymoney = 100;
	int x, y;
	
	int playing = 1;
	
	if(mapCode == 0) {
		memcpy(tempMap, gamemap1, sizeof(tempMap));
	} else if(mapCode == 1) {
		memcpy(tempMap, gamemap2, sizeof(tempMap));
	}
	
	mapDraw(&x, &y);
	
	while(playing){
		
		uiDraw(&x, &y);
		money(&mymoney);
		switch(keyControl()){
			case UP:
				move(&x, &y, 0, -1);
				break;
				
			case DOWN:
				move(&x, &y, 0, 1);
				break;
				
			case RIGHT:
				move(&x, &y, 1, 0);
				break;
				
			case LEFT:
				move(&x, &y, -1, 0);
				break;

		}
	}
}

void move(int* x, int* y, int _x, int _y){
	
	char mapObject = tempMap[*y + _y][*x + _x];
	
	if (mapObject == '0'){
	
		gotoxy(*x, *y);
		printf(BG_COLOR(0,0,0)" " RESET);//black
	
		gotoxy(*x + _x, *y + _y);
		printf(BG_COLOR(244,196,173) FG_COLOR(0,0,0) "\"" RESET);
	
		*x += _x;
		*y += _y;
	}
}


void uiDraw(int* x, int* y){

	gotoxy(40, 60);
	printf("위치: %02d, %02d" , *x, *y); // x, y 값 출력 
	

}

void money(int* mymoney)
{
	gotoxy(66, 60);
	printf("                  ");
	gotoxy(66, 60);
	cout << *mymoney;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		*mymoney += 100; 
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		*mymoney -= 100;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		*mymoney *=2;
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		*mymoney = 100;
		
	Sleep(110);
}





void titleDraw(){ //타이틀  
int x=59, y=10;
gotoxy(x,y+1);
	printf("▒▒■■■■■■■■          ▒▒■■■■          ▒▒■■■■■■  ▒▒■■■■■■■■\n");
	gotoxy(x,y+2);
	printf("▒▒■■■■■■■■          ▒▒■■■■          ▒▒■■■■■■  ▒▒■■■■■■■■\n");
	gotoxy(x,y+3);
	printf("▒▒■■          ▒▒■■  ▒▒■■      ▒▒■■  ▒▒■■              ▒▒■■\n");
	gotoxy(x,y+4);
	printf("▒▒■■          ▒▒■■  ▒▒■■      ▒▒■■  ▒▒■■              ▒▒■■\n");
	gotoxy(x,y+5);
	printf("▒▒■■■■■■■■      ▒▒■■      ▒▒■■  ▒▒■■              ▒▒■■\n");
	gotoxy(x,y+6);
	printf("▒▒■■■■■■■■      ▒▒■■■■■■■■  ▒▒■■              ▒▒■■■■■■■■\n");
	gotoxy(x,y+7);
	printf("▒▒■■  ▒▒■■          ▒▒■■■■■■■■  ▒▒■■              ▒▒■■■■■■■■\n");
	gotoxy(x,y+8);
	printf("▒▒■■  ▒▒■■          ▒▒■■      ▒▒■■  ▒▒■■              ▒▒■■\n");
	gotoxy(x,y+9);
	printf("▒▒■■      ▒▒■■      ▒▒■■      ▒▒■■  ▒▒■■              ▒▒■■\n");
	gotoxy(x,y+10);
	printf("▒▒■■      ▒▒■■      ▒▒■■      ▒▒■■  ▒▒■■              ▒▒■■\n");
	gotoxy(x,y+11);
	printf("▒▒■■          ▒▒■■  ▒▒■■      ▒▒■■      ▒▒■■■■■■  ▒▒■■■■■■■■\n");
	gotoxy(x,y+12);
	printf("▒▒■■          ▒▒■■  ▒▒■■      ▒▒■■      ▒▒■■■■■■  ▒▒■■■■■■■■\n");
	gotoxy(89,y+15);
	printf("●●●●●●  ●●●●●●\n");
	gotoxy(89,y+16);
	printf("          ●            ●\n");
	gotoxy(89,y+17);
	printf("●●●●●●  ●●●●●●\n");
	gotoxy(89,y+18);
	printf("●            ●          \n");
	gotoxy(89,y+19);
	printf("●●●●●●  ●●●●●●\n");

}

int menuDraw(){ //메인 메뉴 선택지 
	int y = 25;
	gotoxy(94, 25);
	printf("▶  Press to Start ");
	gotoxy(74, y+1);
	printf("A spcial button for those who without courage");
	while(1){
		int n = keyControl();
		switch(n){
			case UP: {
				if(y > 25){
					gotoxy(94-16, y);
					printf("  ");
					gotoxy(94, --y);
					printf("▶");
					
			  
				}
				break;
			}
			case DOWN: {
				if(y < 26) {
					gotoxy(94, y);
					printf("  ");
					gotoxy(94-16, ++y);
					printf("▶");
				}
				break;
			}
			case SUBMIT: {
				if (y == 25) {
                for (int i = 0; i < 3; i++)
                {
                    gotoxy(98, 25);
                    printf("              ");
                    Sleep(100);
                    gotoxy(98, 25);
                    printf("Press to Start");
                    Sleep(100);
                }
				Sleep(500);
            }

            else {
                for (int i = 0; i < 3; i++)
                {
                    gotoxy(32, 26); // 글귀에 알맞게 좌표변경
                    printf("                    Loser                     ");
                    Sleep(110);
                    gotoxy(32, 26);
                    printf("A spcial button for those who without courage ");
                    Sleep(110);
                }
                Sleep(500);
            }
				return y - 25;
			}
			
			
	}
	}
	
}







void gotoxy(int x, int y){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int gamemenuDraw(){ //자동차 미리보기  
	int x=63, y=18;
	system("cls");
	gotoxy(0,0); 
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	Sleep(50);
	gotoxy(0,1); 
	printf("■                                                          ■\n");
	Sleep(50);
	gotoxy(0,2);
	printf("■       _______________________                            ■\n");
	Sleep(50);
	gotoxy(0,3);
	printf("■      /||     ＼               ＼                         ■\n");
	Sleep(50);
	gotoxy(0,4);
	printf("■     / ||       ＼               ＼                       ■\n");
	Sleep(50);
	gotoxy(0,5);
	printf("■    /  ||         '----____________'----____              ■\n");
	Sleep(50);
	gotoxy(0,6);
	printf("■   |   |￣￣￣￣￣|        '----____________'----____     ■\n");
	Sleep(50);
	gotoxy(0,7);
	printf("■   |   | ￣       |              ■■＼〓〓======〓〓＼   ■\n");
	Sleep(50);
	gotoxy(0,8);
	printf("■   |□□□□□□□□□□□□□□□□□|□□□□□□□□|  ■\n");
	Sleep(50);
	gotoxy(0,9);
	printf("■   ＼  / ＼                / ＼       |  ■■=RACE=■■|  ■\n");
	Sleep(50);
	gotoxy(0,10);
	printf("■     ＼|○|＼ □□□□□□/|○|＼□□/_□□□□□□□□/  ■\n");
	Sleep(50);
	gotoxy(0,11);
	printf("■       ＼_/_/ ￣￣￣￣￣￣ ＼_/_/￣￣  ￣￣￣＼_/_/￣￣   ■\n");
	Sleep(50);
	gotoxy(0,12);
	printf("■   ◁                                                ▷   ■\n");
	Sleep(50);
	gotoxy(0,13);
	printf("■                                                          ■\n");
	Sleep(50);
	gotoxy(0,14);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	
	Sleep(50); //차 세부사항 
	gotoxy(x+1,1);
	printf("Sprinter Trueno GT-APEX [AE86]\n");
	Sleep(50);
	gotoxy(x+1,2);
	printf("구동방식/변속단:FR/5단\n");
	Sleep(50);
	gotoxy(x+1,3);
	printf("엔진:4A-GEU\n");
	gotoxy(x+1,4);
	printf("엔진형식:1.6L 자연흡기직렬 4기통\n");
	Sleep(50);
	gotoxy(x+1,5);
	printf("마력:130hp\n");
	Sleep(50);
	gotoxy(x+1,6);
	printf("토크:15.2kg.m\n");
	Sleep(50);
	gotoxy(x+1,4);
	printf("엔진형식:1.6L 자연흡기직렬 4기통\n");
	Sleep(50);
	gotoxy(x+1,5);
	printf("마력:130hp\n");
	Sleep(50);
	gotoxy(x+1,6);
	printf("토크:15.2kg.m\n");
	Sleep(50);
	

	gotoxy(53,y);
	printf("▶RACE!");
	Sleep(50);
	gotoxy(55,y+1);
	printf("EVEN MORE TERRIFYING RACE!!!!");
	Sleep(50);
	gotoxy(55,y+2);
	printf("main menu");
	
	while(1){
		int n=keyControl();
		switch(n){
			case UP:{
				if(y>18){
					gotoxy(53,y);
					printf("  ");
					gotoxy(53,--y);
					printf("▶");
				}
				break;
			}
			
			case DOWN: {
				if(y<20) {
					gotoxy(53,y);
					printf("  ");
					gotoxy(53,++y);
					printf("▶");
				}
				break;
			}
			
			case SUBMIT: {
				return 0;
			}
		}
	}
}
	










	





