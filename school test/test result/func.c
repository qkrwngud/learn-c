#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int get_rand();
void binary_search(int search, int num[], int cnt);

int main() {
	
  //함수 + 이진탐색 + 선택정렬
  
	int num[10] = { 0, };
	int search_num = get_rand();
	int temp = 0, select = 0;
	
	srand((unsigned)time(NULL));
	
	//랜덤값넣고 출력 
	for (int i = 0; i < 10; i++)
	{
		num[i] = get_rand();
	}
	printf("초기배열 :");
	for (int i = 0; i < 10; i++)
	{
		printf("%3d ", num[i]);
	}
	
	//정렬 
	for (int i = 0; i < 9; i++)
	{
		select = i;
		for (int j = i + 1; j < 10; j++)
		{
			if (num[j] < num[select]) select = j;
		}
		temp = num[i];
		num[i] = num[select];
		num[select] = temp;
	}


	//출력 
	printf("\n정렬된 배열:");
	for (int i = 0; i < 10; i++)
	{
		printf("%3d", num[i]);
	}
	
	binary_search(search_num, num, 10);
}

int get_rand()
{
	return rand() % 100 + 1;
}

void binary_search(int search, int num[], int cnt)
{
	int mid = 0, left = 0, right = 0, search_num = 0;

	right = cnt - 1;
	
	printf("\n찾는수: %d\n", search);

	while (right >= left)
	{
		mid = (left + right) / 2;

		if (search < num[mid])
		{
			right = mid - 1;
		}
		
		else if (search > num[mid])
		{
			left = mid + 1;
		}
		
		else if (search == num[mid])
		{
			printf("%d는 %d번째에 있음\n", search, mid + 1);
			printf("%d번째 만에 찾음\n", search_num + 1);
			break;
		}
		
		search_num++;
		
	}
	
	if(right < left)
	{
		printf("찾는 수 없음");
	}
	
}
