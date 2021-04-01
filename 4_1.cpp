/*
N*N 크기의 공간에서 (1,1)에서 L, R, U, D 대로 이동한 결과를 출력한다. 단 N*N을 벗어나는 이동은 무시한다.*/
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
	// 답지가 대단하다
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