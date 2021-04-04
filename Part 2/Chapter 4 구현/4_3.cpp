/*
행 1~8, 열 a~h까지의 8*8 크기의 정원에 나이트가 있다. 나이트는 수직 2칸 후 수평 1칸 or 수평2칸 후 수직 1칸 이동이 가능하다.
정원 밖으로 나갈 수는 없을 때 특정 위치가 주어졌을 때 이동할 수 있는 경우의 수를 구하시오. 
*/
#include <iostream>
using namespace std;

int main(void)
{
	string input_data;

	cin >> input_data;

	int row = input_data[0] - 'a';
	int col = input_data[1] - '1';
	int dx[8] = { -2, -2 ,-1,-1,1,1,2,2 };
	int dy[8] = { 1,-1,2,-2,2,-2,1,-1 };
	int res = 0;

	for (int i = 0; i < 8; i++) {
		int after_x = col + dx[i];
		int after_y = row + dy[i];

		if (after_x < 0 || after_x > 8 || after_y < 0 || after_y > 8)
			continue;

		res++;
	}
	cout << res;
	return 0;
}