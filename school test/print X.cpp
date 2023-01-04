#include<iostream>
using namespace std;


int main()
{
	int left= 0, right = 10;

	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			if (j == left)
			{
				cout << "□";
			}
			else if (j == right)
			{
				cout << "□";
			}
			else
			{
				cout << "  ";
			}
		}
		left++;
		right--;
		cout << '\n';
	}


	return 0;
}
