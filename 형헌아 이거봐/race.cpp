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

//����
void ATM();

void ATMIN();
void ATMOUT(); 

// �ֽ� �����ֱ� 
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
		::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); //��üȭ�� 
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

	





int keyControl(){ //Ű���� ��Ʈ�� 
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
				*x = w; // �÷��̾� ��ǥ�� ����  
				*y = h; 
				printf(BG_COLOR(244,196,173) FG_COLOR(0,0,0)"\"" RESET);
			}else if(temp == 'J'){
				*x = w; // ������  
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
				printf(BG_COLOR(230,223,200)" " RESET);//���̺��� �������� 
			}else if(temp == 'f'){
				printf(BG_COLOR(212,200,156)" " RESET);//���̺����߰� 
			}else if(temp == 'g'){
				printf(BG_COLOR(203,188,135)" " RESET);//���̺����ణ��ο� 
			}else if(temp == 'h'){
				printf(BG_COLOR(184,164,92)" " RESET);//���̺�������ο� 
			}else if(temp == 'i'){
				printf(BG_COLOR(153,102,51)" " RESET);//������ 
			}else if(temp == 'j'){
				printf(BG_COLOR(87,58,29)" " RESET);//��ũ������ 
			}else if(temp == 'k'){
				printf(BG_COLOR(146,208,80)" " RESET);//���� 
			}else if(temp == 'l'){
				printf(BG_COLOR(0,116,52)" " RESET);//�������ʷ� 
			}else if(temp == 'm'){
				printf(BG_COLOR(168,70,50) FG_COLOR(170,170,170) "#" RESET);//������ �ణ��ο� 
			}else if(temp == 'n'){
				printf(BG_COLOR(125,52,37) FG_COLOR(120,120,120) "#" RESET);//������ ��ο� 
			}else if(temp == 'o'){
				printf(BG_COLOR(217,144,129) FG_COLOR(255,255,255) " " RESET);//������  �� 
			}else if(temp == 'p'){
				printf(BG_COLOR(244,196,173) FG_COLOR(0,0,0)" " RESET);
			}else if(temp == '='){
				printf(BG_COLOR(239,211,0) FG_COLOR(0,0,0) "=" RESET);//yellow
			}else if(temp == 'H'){
				printf(BG_COLOR(0,185,226) FG_COLOR(0,0,0) "H" RESET);//window
			}else if(temp == '&'){
				printf(BG_COLOR(0,185,226) FG_COLOR(255,255,255) "@" RESET);//��(��Ż) 
			}else if(temp == 'D'){
				printf(BG_COLOR(0,185,226) FG_COLOR(255,255,255) "@" RESET);//��(��Ż) 
			}else if(temp == 'A'){
				printf(BG_COLOR(6,136,21)  " " RESET);//���� �� �ʷ�, k�� �Բ� ��� 
			}else if(temp == 'S'){
				printf(BG_COLOR(6,136,21)  "@" RESET);//���� �� �ʷ�, k�� �Բ� ��� 
			}else if(temp == '#'){
				printf(BG_COLOR(197,85,63) FG_COLOR(255,255,255) "#" RESET);//��(��) 
			}else if(temp == '%'){
				printf(BG_COLOR(129,86,43) FG_COLOR(0,0,0) "\"" RESET);//���� npc 
			}else if(temp == '^'){
				printf(BG_COLOR(68,35,2) FG_COLOR(0,0,0) "\"" RESET);//���� npc 
			}else if(temp == '$'){
				printf(BG_COLOR(68,35,2) FG_COLOR(0,0,0) "\"" RESET);//����� 
			}else if(temp == '*'){
				printf(BG_COLOR(210,210,210) FG_COLOR(239,211,0) "$" RESET);//����� 
			}else if(temp == '+'){
				printf(BG_COLOR(0,0,0) FG_COLOR(87,58,29) "/" RESET);//���� 
			}else if(temp == '|'){
				printf(BG_COLOR(0,0,0) FG_COLOR(255,255,255) "|" RESET);//������ 
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
				printf(BG_COLOR(153,102,51)" " RESET);//������ 
			}
			else if(temp == 'L'){
				printf(BG_COLOR(153,102,51)" " RESET);//������ 
			}
			else if(temp == 'A'){
				printf(BG_COLOR(153,102,51)" " RESET);//������ 
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
	}else if(mapObject == '%'){ //��������, ���� 
		market();
	}else if(mapObject == '^'){ //£����������, ���� 
		if(fishing == true)
		{
			gLoop(2);
		}
		else
		{
			gotoxy(2, 49);
			cout << "���˴븦 ��ÿ�";
			Sleep(300);
			gotoxy(2, 49);
			cout << "                    ";
		}
	}else if(mapObject == '$'){ //���������� 
		sellfish();
	}else if(mapObject == 'D'){ //������ �����¹� 
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
	printf("��ġ: %02d, %02d" , *x, *y); // x, y �� ��� 
	

}

void showmoney(/*int mymoney*/)
{
	gotoxy(121, 52);
	printf("                  ");
	gotoxy(121, 52);
	cout << "�ܾ�:" << mymoney;
	
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		mymoney = 100000000; //�ӽ� �׽�Ʈ 
	
	gotoxy(121, 47);
	printf("                  ");
	gotoxy(121, 47);
	cout << "����:" << Account;
	
}

int market()
{
	//system("cls");
	
    int item, num; // �Է¹����� 
    
    const int arr1[6] = {400, 450, 450, 400, 500, 400}; // ���ݹ迭
	
	// ��ǰ ��� ���߿� �ٽ� ���� 
	
	gotoxy(2, 48);
	cout << "1. ����: " << arr1[0]  << "��\t\t";
	gotoxy(22, 48);
    cout << "2. ������: " << arr1[1] << "��" << endl;
    
    gotoxy(2, 49);
    cout << "3. ��������: " << arr1[2]  << "��\t\t";
    gotoxy(22, 49);
	cout << "4. ������: " << arr1[3] << "��" << endl;
	
	gotoxy(2, 50);
	cout << "5. �ζ�: " << arr1[4] << "��| ���� ����: " << !lottoticket << "\t\t";
	gotoxy(32, 50);
    cout << "6. ���˴�: " << arr1[5] << "��| ���� ����: " << !fishing << endl;
    
    // �Է¹ޱ� 
    gotoxy(48, 48);
    cout << "��ȣ �Է�: ";
	cin >> item;
    Sleep(200);
    gotoxy(48, 48);
    cout << "                                        ";
    
    
    gotoxy(48, 48);
    cout << "����: ";
    cin >> num;
    Sleep(200);
    gotoxy(48, 48);
    cout << "                                        ";
    
	if(item == 5)
		num = 1;
	if(item == 6)
		num = 1;
		
    // ���Ÿ� ������ ���� ��� 
	if(item == 6 && fishing == true)
	{
		gotoxy(48, 49);
		cout << "���� ������ ����" << endl;
	}
	else if(item == 5 && lottoticket == true)
	{
		gotoxy(48, 49);
		cout << "���� ������ ����" << endl;
	}
	else if(arr1[item - 1] * num <= mymoney )
	{
		mymoney -= arr1[item - 1] * num;
		gotoxy(48, 49);
		cout << "�ٱ��� �Ϸ�� | �ܵ�: " << mymoney;
	}
	
	
	// ���������� �ִ� ��ǰ�� ��� sssss
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
    cout << "�Ա� ��� ����: ";
    cin >> str;
    gotoxy(2, 49);
    cout << "                        ";
    if(str == "�Ա�" || str == "in")
        ATMIN();
    if(str == "���" || str == "out")
	    ATMOUT();
}

void ATMIN()
{
	int coin;

	gotoxy(2, 49);
	
	cout << "�Ա�: ";
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
		cout << "�ܾ�Ȯ��";
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
	
	cout << "���: ";
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
		cout << "�ܾ� ����" << endl;
		Sleep(300);
	}
	gotoxy(2, 49);
	cout << "                                     \n\n";
	cout << "                                            ";
}

void showstock()
{
	srand((unsigned)time(NULL));
	
	// ���� 
	const float sik[4] = {1.2, 1.5, 1.8, 0.5};
	
	string inout;
	gotoxy(25, 48);
	cout << "�ż� �ŵ� ����: ";
	cin >> inout;
	
	Sleep(100);
	gotoxy(25, 48);
	cout << "                                 ";
	
	string whatstock;
	
	if(inout == "�ż�")
	{
		if(stockshow == false)
		{
			int num;
			gotoxy(2, 48);
			cout << moneyname[0] << "  " << moneyname[1] << "  " << moneyname[2];
			gotoxy(2, 49);
			cout << bankMoney[0] << "  " << bankMoney[1] << "  " << bankMoney[2];
			gotoxy(25, 48);
			cout << "������ �����Ұ��ΰ�: ";
			cin >> whatstock;
			gotoxy(25, 48);
			cout << "                                            ";
			gotoxy(25, 48);
			cout << "����: ";
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
	if(inout == "�ŵ�")
	{
		if(stock_index != -1 && stock_num != -1)
		{
			gotoxy(25, 48);
			cout << "����: ";
			cin >> a;
			
			if(stock_num >= a)
			{
				stock_num -= a;
				mymoney += bankMoney[stock_index] * a;
			}
			else
			{
				gotoxy(25, 50);
				cout << "����";
				Sleep(200);
			}
			
		}
		else
		{
			gotoxy(25, 49);
			cout << "�ż��� ���� �Ͻÿ�";
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
		cout << moneyname[stock_index] << ": " << stock_num << "��";
		
		gotoxy(121, 50);
		cout << "                                                          ";
		gotoxy(121, 50);
		cout << "���� " << bankMoney[stock_index] << "��";
		Sleep(200);
	}
	else
	{
		gotoxy(121, 49);
		cout << moneyname[stock_index] << ": " << stock_num << "��";
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
            cout << "����⸦ ��������";
            Sleep(300);
            gotoxy(2, 49);
            cout << "                     ";
            break;
            
        default:
            fish_price = fish_price * fish;
            gotoxy(2, 49);
            cout << "����� �Ǹ� �Ϸ�: " << fish << "����";
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
				cout << "�������� �ζǸ� ��ÿ�";
				Sleep(300);
				gotoxy(2, 49);
				cout << "                         ";
				break;
			
			case 1:
				gotoxy(2, 49);
				cout << "�ζ� ��÷!(1��)";
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
		cout << "100������ �־�� Ȯ�ΰ���";
		Sleep(400);
		gotoxy(2, 49);
		cout << "                              ";
	}
}

void titleDraw(){ //Ÿ��Ʋ  
/*int x=59, y=10;
gotoxy(x,y+1);
	printf(BG_COLOR(244,196,173) FG_COLOR(0,0,0) "dddddddddd\n");
	gotoxy(x,y+2);
	printf("�Ƣơ��������          �Ƣơ����          �Ƣơ������  �Ƣơ��������\n");
	gotoxy(x,y+3);
	printf("�Ƣơ��          �Ƣơ��  �Ƣơ��      �Ƣơ��  �Ƣơ��              �Ƣơ��\n");
	gotoxy(x,y+4);
	printf("�Ƣơ��          �Ƣơ��  �Ƣơ��      �Ƣơ��  �Ƣơ��              �Ƣơ��\n");
	gotoxy(x,y+5);
	printf("�Ƣơ��������      �Ƣơ��      �Ƣơ��  �Ƣơ��              �Ƣơ��\n");
	gotoxy(x,y+6);
	printf("�Ƣơ��������      �Ƣơ��������  �Ƣơ��              �Ƣơ��������\n");
	gotoxy(x,y+7);
	printf("�Ƣơ��  �Ƣơ��          �Ƣơ��������  �Ƣơ��              �Ƣơ��������\n");
	gotoxy(x,y+8);
	printf("�Ƣơ��  �Ƣơ��          �Ƣơ��      �Ƣơ��  �Ƣơ��              �Ƣơ��\n");
	gotoxy(x,y+9);
	printf("�Ƣơ��      �Ƣơ��      �Ƣơ��      �Ƣơ��  �Ƣơ��              �Ƣơ��\n");
	gotoxy(x,y+10);
	printf("�Ƣơ��      �Ƣơ��      �Ƣơ��      �Ƣơ��  �Ƣơ��              �Ƣơ��\n");
	gotoxy(x,y+11);
	printf("�Ƣơ��          �Ƣơ��  �Ƣơ��      �Ƣơ��      �Ƣơ������  �Ƣơ��������\n");
	gotoxy(x,y+12);
	printf("�Ƣơ��          �Ƣơ��  �Ƣơ��      �Ƣơ��      �Ƣơ������  �Ƣơ��������\n");
	gotoxy(89,y+15);
	printf("�ܡܡܡܡܡ�  �ܡܡܡܡܡ�\n");
	gotoxy(89,y+16);
	printf("          ��            ��\n"); 
	gotoxy(89,y+17);
	printf("�ܡܡܡܡܡ�  �ܡܡܡܡܡ�\n");
	gotoxy(89,y+18);
	printf("��            ��          \n");
	gotoxy(89,y+19);
	printf("�ܡܡܡܡܡ�  �ܡܡܡܡܡ�\n");
*/
}


int menuDraw(){ //���� �޴� ������ 
	int y = 25;
	gotoxy(94, 25);
	printf("��  Press to Start ");
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
                    printf("�����̽��ٸ� ���� �����ϼ���.");
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

	int gamemenuDraw(){ //�ڵ��� �̸�����  
	int x=63, y=28;
	system("cls");
	gotoxy(30,4); 
	printf("�츮 ���ֿ���.\n");
	Sleep(150);
	gotoxy(30,6); 
	printf("�ʿ��� �������� �ʾҾ����� �� �Ҿƺ�� ��� ����׷��� ȸ���̾��ܴ�.\n");
	Sleep(150);
	gotoxy(30,8);
	printf("�ʴ� ���� ������ �İ����̱⿡ ����׷��� �ʿ��� ��ӵ� �����̶���.\n");
	Sleep(150);
	gotoxy(30,10);
	printf("�׷��� �� ����, �ʰ� ���� ����׷��� �������� �� �ִ� �׸��� ���� �����غ��� ����\n");
	Sleep(150);
	gotoxy(30,12);
	printf("�ʿ��� �������� 1���� ���� ����ܴ�.\n");
	Sleep(150);
	gotoxy(30,14);
	printf("1���� ���� ���� �ȴٸ� �츮 ȸ�� ������ ����� �� ���̾�.\n");
	Sleep(150);
	gotoxy(30,16);
	printf("������ 1���� ���� ���Ѵٸ� 1���� ���� �츮 ����׷쿡�� �����ְ�����, ȸ�縦 ���������� ���� ���̶���.\n");
	Sleep(150);
	gotoxy(30,18);
	printf("�װ� �� ���� ���� �츮�� ����׷��� �������� �� �ֱ⸦ �ٶ���...\n");
	Sleep(150);
	gotoxy(30,20);
	printf("-�Ҿƹ�����\n");
	Sleep(150); 
	gotoxy(53,y);
	printf("������ ����");
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
