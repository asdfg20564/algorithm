/*
�ڿ��� n(2�̻�) �� 1�� �� ������ n���� 1�� ���ų� �������� �� k�� ������ n�� 1�� ������.
*/
#include <iostream>
using namespace std;

int main(void)
{
	int n, k, res = 0;
	cin >> n >> k;

	while (n != 1)
	{
		if (n == 1)
			break;
		if (n == 0){
			n += 1;
			res -= 1;
			break;
		}
		if (n % k == 0){
			n /= k;
			res += 1;
		}
		else {
			int temp = n % k;
			n -= temp;
			res += temp;
		}
	}
	cout << res;
	return 0;
}