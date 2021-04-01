/*
N*N ũ���� �������� (1,1)���� L, R, U, D ��� �̵��� ����� ����Ѵ�. �� N*N�� ����� �̵��� �����Ѵ�.*/
#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int x = 1, y = 1, i = 0;
	char move[100] = { 0, };
	char temp = cin.get();

	while(i < 100){
		char input;

		input = cin.get();
		if (input == '\n')
			break;
		else if (input != ' ')
		{
			move[i] = input;
			i++;
		}
			
	}
	// ������ ����ϴ�
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };
	char type[4] = { 'L','R','U','D' };

	for (int j = 0; j < i; j++) {
		int after_x, after_y;
		for (int k = 0; k < 4; k++) {
			if (move[j] == type[k]) {
				after_x = x + dx[k];
				after_y = y + dy[k];
				break;
			}
		}
		if (after_x <1 || after_x > n || after_y < 1 || after_y > n)
			continue;
		x = after_x;
		y = after_y;
	}
	//result
	cout << x << " " << y;
	return 0;
}