#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <mmsystem.h>
#include<string>

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

void showmoney();

void gLoop(int);
void move(int*, int*, int, int);
int keyControl();

void titleDraw();
int menuDraw();
int gamemenuDraw();
int market();
void mapDraw(int*, int*);

void gotoxy(int x, int y);
void init();
void uiDraw(int*, int*);

void sellfish();
void checklotto();

//은행
void ATM();

void ATMIN();
void ATMOUT(); 

// 주식 보여주기 
float jkmoney[3] = {10000, 20000, 30000};
void showstock();
int fish = 0;

int mymoney = 10000;
bool fishing = false;
bool lottoticket = false;
bool stockshow = false;
int Account = 0;
bool lc = false;
int stock_index, stock_num;

float bankMoney[3] = {10000, 20000, 30000};
const string moneyname[3] = {"stock1", "stock2", "stock3"};

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
			}else if(temp == 'J'){
				*x = w; // 낚싯찌  
				*y = h; 
				printf(BG_COLOR(0,0,0) FG_COLOR(255,255,255)"J" RESET);
			}else if(temp == 'O'){
				printf(BG_COLOR(0,112,192) " " RESET);
			}else if(temp == 'B'){
				printf(BG_COLOR(0,0,0) " " RESET);
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
			}else if(temp == 'e'){
				printf(BG_COLOR(230,223,200)" " RESET);//아이보리 젤밝은거 
			}else if(temp == 'f'){
				printf(BG_COLOR(212,200,156)" " RESET);//아이보리중간 
			}else if(temp == 'g'){
				printf(BG_COLOR(203,188,135)" " RESET);//아이보리약간어두움 
			}else if(temp == 'h'){
				printf(BG_COLOR(184,164,92)" " RESET);//아이보리개어두움 
			}else if(temp == 'i'){
				printf(BG_COLOR(153,102,51)" " RESET);//갈색쓰 
			}else if(temp == 'j'){
				printf(BG_COLOR(87,58,29)" " RESET);//다크갈색쓰 
			}else if(temp == 'k'){
				printf(BG_COLOR(146,208,80)" " RESET);//연두 
			}else if(temp == 'l'){
				printf(BG_COLOR(0,116,52)" " RESET);//개찐한초록 
			}else if(temp == 'm'){
				printf(BG_COLOR(168,70,50) FG_COLOR(170,170,170) "#" RESET);//적갈색 약간어두움 
			}else if(temp == 'n'){
				printf(BG_COLOR(125,52,37) FG_COLOR(120,120,120) "#" RESET);//적갈색 어두움 
			}else if(temp == 'o'){
				printf(BG_COLOR(217,144,129) FG_COLOR(255,255,255) " " RESET);//적갈색  밝 
			}else if(temp == 'p'){
				printf(BG_COLOR(244,196,173) FG_COLOR(0,0,0)" " RESET);
			}else if(temp == '='){
				printf(BG_COLOR(239,211,0) FG_COLOR(0,0,0) "=" RESET);//yellow
			}else if(temp == 'H'){
				printf(BG_COLOR(0,185,226) FG_COLOR(0,0,0) "H" RESET);//window
			}else if(temp == '&'){
				printf(BG_COLOR(0,185,226) FG_COLOR(255,255,255) "@" RESET);//문(포탈) 
			}else if(temp == 'D'){
				printf(BG_COLOR(0,185,226) FG_COLOR(255,255,255) "@" RESET);//문(포탈) 
			}else if(temp == 'A'){
				printf(BG_COLOR(6,136,21)  " " RESET);//해초 겉 초록, k와 함께 사용 
			}else if(temp == 'S'){
				printf(BG_COLOR(6,136,21)  "@" RESET);//해초 겉 초록, k와 함께 사용 
			}else if(temp == '#'){
				printf(BG_COLOR(197,85,63) FG_COLOR(255,255,255) "#" RESET);//돌(벽) 
			}else if(temp == '%'){
				printf(BG_COLOR(129,86,43) FG_COLOR(0,0,0) "\"" RESET);//상점 npc 
			}else if(temp == '^'){
				printf(BG_COLOR(68,35,2) FG_COLOR(0,0,0) "\"" RESET);//낚시 npc 
			}else if(temp == '$'){
				printf(BG_COLOR(68,35,2) FG_COLOR(0,0,0) "\"" RESET);//은행원 
			}else if(temp == '*'){
				printf(BG_COLOR(210,210,210) FG_COLOR(239,211,0) "$" RESET);//은행원 
			}else if(temp == '+'){
				printf(BG_COLOR(0,0,0) FG_COLOR(87,58,29) "/" RESET);//낚싯 
			}else if(temp == '|'){
				printf(BG_COLOR(0,0,0) FG_COLOR(255,255,255) "|" RESET);//낚싯줄 
			}else if(temp == '<'){
				printf( BG_COLOR(0,112,192) FG_COLOR(239,114,69)"<" RESET);//fish
			}else if(temp == '>'){
				printf( BG_COLOR(0,112,192) FG_COLOR(239,114,69)">" RESET);//fish
			}else if(temp == 'Y'){
				printf( BG_COLOR(255,192,0) " " RESET);//goldfish
			}else if(temp == 'W'){
				printf( BG_COLOR(255,255,0) " " RESET);//goldfish
			}
			else if(temp == 'P'){
				printf(BG_COLOR(153,102,51)" " RESET);//갈색쓰 
			}
			else if(temp == 'L'){
				printf(BG_COLOR(153,102,51)" " RESET);//갈색쓰 
			}
			else if(temp == 'A'){
				printf(BG_COLOR(153,102,51)" " RESET);//갈색쓰 
			}
		}
		printf("\n");
	}

}

void gLoop(int mapCode){
	int x, y;
	
	int playing = 1;
	
	if(mapCode == 0) {
		memcpy(tempMap, gamemap1, sizeof(tempMap));
	} else if(mapCode == 1) {
		memcpy(tempMap, gamemap2, sizeof(tempMap));
	} else if(mapCode == 2) {
		memcpy(tempMap, gamemap3, sizeof(tempMap));
	}
	
	mapDraw(&x, &y);
	
	while(playing){
		
		uiDraw(&x, &y);
		showmoney(/*&mymoney*/);
		
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

	

	Sleep(30);

	
	if (mapObject == '0'){
	
		gotoxy(*x, *y);
		printf(BG_COLOR(0,0,0)" " RESET);//black
	
		gotoxy(*x + _x, *y + _y);
		printf(BG_COLOR(244,196,173) FG_COLOR(0,0,0) "\"" RESET);
	
		*x += _x;
		*y += _y;
	}else if (mapObject == 'O'){
	
		gotoxy(*x, *y);
		printf(BG_COLOR(46,23,0) FG_COLOR(0,0,0)"/" RESET);//black
	
		gotoxy(*x + _x, *y + _y);
		printf(BG_COLOR(0,112,192) FG_COLOR(255,255,255) "J" RESET);
	
		*x += _x;
		*y += _y;
	}
	else if(mapObject == '&'){
		gLoop(1);
	}else if(mapObject == '%'){ //갈색남자, 상점 
		market();
	}else if(mapObject == '^'){ //짙은갈색남자, 낚시 
		if(fishing == true)
		{
			gLoop(2);
		}
		else
		{
			gotoxy(2, 49);
			cout << "낚싯대를 사시오";
			Sleep(300);
			gotoxy(2, 49);
			cout << "                    ";
		}
	}else if(mapObject == '$'){ //연갈색남자 
		sellfish();
	}else if(mapObject == 'D'){ //밖으로 나가는문 
		gLoop(0);
	}else if(mapObject == '*'){ //ATM
		showstock();
		
	}else if(mapObject == '<'){ //ATM
		fish++;
		gLoop(0);
		
		
	}else if(mapObject == '>'){ //ATM
		fish++;
		gLoop(0);

		
	}else if(mapObject == 'Y'){ //ATM
		fish += 20;
		gLoop(0);

		
	}
	else if(mapObject == 'L'){
		checklotto();
	}	
	else if(mapObject == 'A'){
		ATM();
	}
}



void uiDraw(int* x, int* y){

	gotoxy(2, 47);
	printf("위치: %02d, %02d" , *x, *y); // x, y 값 출력 
	

}

void showmoney(/*int mymoney*/)
{
	gotoxy(121, 52);
	printf("                  ");
	gotoxy(121, 52);
	cout << "잔액:" << mymoney;
	
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		mymoney = 100000000; //임시 테스트 
	
	gotoxy(121, 47);
	printf("                  ");
	gotoxy(121, 47);
	cout << "통장:" << Account;
	
}

int market()
{
	//system("cls");
	
    int item, num; // 입력받을수 
    
    const int arr1[6] = {400, 450, 450, 400, 500, 400}; // 가격배열
	
	// 상품 출력 나중에 다시 정리 
	
	gotoxy(2, 48);
	cout << "1. 여눈: " << arr1[0]  << "원\t\t";
	gotoxy(22, 48);
    cout << "2. 도란검: " << arr1[1] << "원" << endl;
    
    gotoxy(2, 49);
    cout << "3. 도란방패: " << arr1[2]  << "원\t\t";
    gotoxy(22, 49);
	cout << "4. 도란링: " << arr1[3] << "원" << endl;
	
	gotoxy(2, 50);
	cout << "5. 로또: " << arr1[4] << "원| 남은 개수: " << !lottoticket << "\t\t";
	gotoxy(32, 50);
    cout << "6. 낚싯대: " << arr1[5] << "원| 남은 개수: " << !fishing << endl;
    
    // 입력받기 
    gotoxy(48, 48);
    cout << "번호 입력: ";
	cin >> item;
    Sleep(200);
    gotoxy(48, 48);
    cout << "                                        ";
    
    
    gotoxy(48, 48);
    cout << "개수: ";
    cin >> num;
    Sleep(200);
    gotoxy(48, 48);
    cout << "                                        ";
    
	if(item == 5)
		num = 1;
	if(item == 6)
		num = 1;
		
    // 구매를 성공과 실패 출력 
	if(item == 6 && fishing == true)
	{
		gotoxy(48, 49);
		cout << "남은 수량이 없음" << endl;
	}
	else if(item == 5 && lottoticket == true)
	{
		gotoxy(48, 49);
		cout << "남은 수량이 없음" << endl;
	}
	else if(arr1[item - 1] * num <= mymoney )
	{
		mymoney -= arr1[item - 1] * num;
		gotoxy(48, 49);
		cout << "☆구매 완료☆ | 잔돈: " << mymoney;
	}
	
	
	// 한정개수가 있는 상품의 경우 sssss
	if(item == 5)
	{
		if(lottoticket == false)
		{
			lottoticket = true;
			lc = true;
		}
	}
	if(item == 6)
	{
		if(fishing == false)
		{
			fishing = true;
		}
	}


	Sleep(1000);
	gotoxy(2, 48);
	cout << "                                                                                        \n";
	cout << "                                                                                        \n";
	cout << "                                                                                                     \n";
	cout << "                                                                                            ";
}

void ATM()
{
	string str;

    gotoxy(2, 49);
    cout << "입금 출금 선택: ";
    cin >> str;
    gotoxy(2, 49);
    cout << "                        ";
    if(str == "입금" || str == "in")
        ATMIN();
    if(str == "출금" || str == "out")
	    ATMOUT();
}

void ATMIN()
{
	int coin;

	gotoxy(2, 49);
	
	cout << "입금: ";
	cin >> coin;
	if(coin <= mymoney)
	{
		Account += coin;
		mymoney -= coin;
		Sleep(200);
	}
	else
	{
		gotoxy(2, 50);
		cout << "잔액확인";
		Sleep(200);
	}
	gotoxy(2, 49);
	cout << "                                         ";
	gotoxy(2, 50);
	cout << "                        ";
}

void ATMOUT()
{

	int coin;

	gotoxy(2, 49);
	
	cout << "출금: ";
	cin >> coin;
	
	if(Account >= coin)
	{
		Account -= coin;
		mymoney += coin;
		Sleep(100);
	}
	else
	{
		gotoxy(2, 51);
		cout << "잔액 부족" << endl;
		Sleep(300);
	}
	gotoxy(2, 49);
	cout << "                                     \n\n";
	cout << "                                            ";
}

void showstock()
{
	srand((unsigned)time(NULL));
	
	// 배율 
	const float sik[4] = {1.2, 1.5, 1.8, 0.5};
	
	string inout;
	gotoxy(25, 48);
	cout << "매수 매도 선택: ";
	cin >> inout;
	
	Sleep(100);
	gotoxy(25, 48);
	cout << "                                 ";
	
	string whatstock;
	
	if(inout == "매수")
	{
		if(stockshow == false)
		{
			int num;
			gotoxy(2, 48);
			cout << moneyname[0] << "  " << moneyname[1] << "  " << moneyname[2];
			gotoxy(2, 49);
			cout << bankMoney[0] << "  " << bankMoney[1] << "  " << bankMoney[2];
			gotoxy(25, 48);
			cout << "무엇을 구매할것인가: ";
			cin >> whatstock;
			gotoxy(25, 48);
			cout << "                                            ";
			gotoxy(25, 48);
			cout << "개수: ";
			cin >> num;
			gotoxy(25, 48);
			cout << "                        ";
			 
			stock_num +=num;
			
			for(int i = 0; i < 3; i ++)
				if(whatstock == moneyname[i])
					stock_index = i;

			stockshow = true;
			
			mymoney -= (bankMoney[stock_index] * stock_num);
		}
	}
	
	
	int a;
	if(inout == "매도")
	{
		if(stock_index != -1 && stock_num != -1)
		{
			gotoxy(25, 48);
			cout << "개수: ";
			cin >> a;
			
			if(stock_num >= a)
			{
				stock_num -= a;
				mymoney += bankMoney[stock_index] * a;
			}
			else
			{
				gotoxy(25, 50);
				cout << "오류";
				Sleep(200);
			}
			
		}
		else
		{
			gotoxy(25, 49);
			cout << "매수를 먼저 하시오";
			Sleep(300);
		}
	}
	
	int random = rand() % 5;
	
	if(stock_num > 0)
	{
		bankMoney[stock_index] *= sik[random];
		
		gotoxy(121, 49);
		cout << "                                                          ";
		gotoxy(121, 49);
		cout << moneyname[stock_index] << ": " << stock_num << "개";
		
		gotoxy(121, 50);
		cout << "                                                          ";
		gotoxy(121, 50);
		cout << "개당 " << bankMoney[stock_index] << "원";
		Sleep(200);
	}
	else
	{
		gotoxy(121, 49);
		cout << moneyname[stock_index] << ": " << stock_num << "개";
		Sleep(100);
		gotoxy(121, 49);
		cout << "                                                          ";
		gotoxy(121, 50);
		cout << "                                                          ";
	}
	gotoxy(2, 48);
	cout << "                                                                                \n";
	cout << "                                                                                \n";
	cout << "                                                                            ";
	
	stockshow = false;
}


void sellfish()
{
    srand((unsigned)time(NULL));
    
    int fish_price(50000);
    
    float fishxn[3] = {2.0, 1.5, 0.5};
    
    int random = rand() % 3;
    
    fish_price = fish_price * fishxn[random];
    
    switch(fish)
    {
        case 0:
            gotoxy(2, 49);
            cout << "물고기를 잡으세요";
            Sleep(300);
            gotoxy(2, 49);
            cout << "                     ";
            break;
            
        default:
            fish_price = fish_price * fish;
            gotoxy(2, 49);
            cout << "물고기 판매 완료: " << fish << "마리";
            mymoney += fish_price;
            Sleep(300);
            gotoxy(2, 49);
            cout << "                                          ";
            fish = 0;
            break;
    }
}

void checklotto()
{
	if(mymoney >= 1000000 && lc == true)
	{
		switch(lottoticket)
		{
			case 0:
				gotoxy(2, 49);
				cout << "상점에서 로또를 사시오";
				Sleep(300);
				gotoxy(2, 49);
				cout << "                         ";
				break;
			
			case 1:
				gotoxy(2, 49);
				cout << "로또 당첨!(1억)";
				mymoney += 100000000;
				Sleep(300);
				gotoxy(2, 49);
				cout << "                         ";
				lottoticket = true;
				lc = false;
				break;
		}
	}
	else
	{
		gotoxy(2, 49);
		cout << "100만원이 있어야 확인가능";
		Sleep(400);
		gotoxy(2, 49);
		cout << "                              ";
	}
}

void titleDraw(){ //타이틀  
/*int x=59, y=10;
gotoxy(x,y+1);
	printf(BG_COLOR(244,196,173) FG_COLOR(0,0,0) "dddddddddd\n");
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
*/
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

			case SUBMIT: {
				if (y == 25) {
                for (int i = 0; i < 3; i++)
                {
                    gotoxy(98, 25);
                    printf("                              ");
                    Sleep(100);
                    gotoxy(98, 25);
                    printf("스페이스바를 눌러 시작하세요.");
                    Sleep(100);
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
	int x=63, y=28;
	system("cls");
	gotoxy(30,4); 
	printf("우리 손주에게.\n");
	Sleep(150);
	gotoxy(30,6); 
	printf("너에게 말해주지 않았었지만 이 할아비는 사실 주헌그룹의 회장이었단다.\n");
	Sleep(150);
	gotoxy(30,8);
	printf("너는 나의 유일한 후계자이기에 주헌그룹은 너에게 상속될 예정이란다.\n");
	Sleep(150);
	gotoxy(30,10);
	printf("그러나 그 전에, 너가 과연 주헌그룹을 물려받을 수 있는 그릇이 될지 시험해보기 위해\n");
	Sleep(150);
	gotoxy(30,12);
	printf("너에게 유산으로 1억의 빚을 남겼단다.\n");
	Sleep(150);
	gotoxy(30,14);
	printf("1억의 빚을 갚게 된다면 우리 회사 측에서 사람이 올 것이야.\n");
	Sleep(150);
	gotoxy(30,16);
	printf("하지만 1억을 갚지 못한다면 1억의 빚은 우리 주헌그룹에서 갚아주겠지만, 회사를 물려주지는 않을 것이란다.\n");
	Sleep(150);
	gotoxy(30,18);
	printf("네가 꼭 빚을 갚고 우리의 주헌그룹을 물려받을 수 있기를 바란다...\n");
	Sleep(150);
	gotoxy(30,20);
	printf("-할아버지가\n");
	Sleep(150); 
	gotoxy(53,y);
	printf("▶빚을 갚자");
	Sleep(150);


	
	while(1){
		int n=keyControl();
		switch(n){

		
			
			case SUBMIT: {
				return 0;
			}
		}
	}
}
