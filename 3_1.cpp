#include <iostream>

using namespace std;
int main(void)
{
	int charge;
	int won500, won100, won50, won10, num;
	cout << "�Ž������� �Է��Ͻÿ�" << endl;
	cin >> charge;

	won500 = charge / 500;
	charge %= 500;
	won100 = charge / 100;
	charge %= 100;
	won50 = charge / 50;
	charge %= 50;
	won10 = charge / 10;

	num = won500 + won100 + won50 + won10;
	cout << "500�� : " << won500 << " 100�� : " << won100 << endl;
	cout << "50�� : " << won50 << " 10�� : " << won10 << endl;

	cout << "�ּ� ���� ���� : " << num << endl;

	return 0;
}