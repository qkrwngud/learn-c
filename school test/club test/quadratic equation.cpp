#include<iostream>
#include<cmath>

using namespace std;
// 이차방정식
int main() {

	cout << "ax² + bx + c = 0\n";

	double a = 0, b = 0, c = 0;

	cout << "a입력: ";
	cin >> a;

	cout << "b입력: ";
	cin >> b;

	cout << "c입력: ";
	cin >> c;

	const double discriminant = b * b - 4 * a * c;

	const double root = sqrt(discriminant);

	cout << endl;

	if (a == 0)
	{
		cout << "x = " << -(c / b);
	}
	else if (discriminant > 0)
	{
		cout << "서로 다른 두근\nx = " << (-b + root) / (2 * a) << " or " << "x = " << (-b - root) / (2 * a);
	}
	else if (discriminant == 0)
	{
		cout << "중근\nx = " << (-b + root) / (2 * a);
	}
	else
	{
		cout << "근이 없음";
	}
	cout << endl;
}
