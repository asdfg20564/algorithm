#include <iostream>

using namespace std;
int main(void)
{
	int charge;
	int won500, won100, won50, won10, num;
	cout << "거스름돈을 입력하시오" << endl;
	cin >> charge;

	won500 = charge / 500;
	charge %= 500;
	won100 = charge / 100;
	charge %= 100;
	won50 = charge / 50;
	charge %= 50;
	won10 = charge / 10;

	num = won500 + won100 + won50 + won10;
	cout << "500원 : " << won500 << " 100원 : " << won100 << endl;
	cout << "50원 : " << won50 << " 10원 : " << won10 << endl;

	cout << "최소 동전 개수 : " << num << endl;

	return 0;
}