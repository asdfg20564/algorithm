/*
�� 1~8, �� a~h������ 8*8 ũ���� ������ ����Ʈ�� �ִ�. ����Ʈ�� ���� 2ĭ �� ���� 1ĭ or ����2ĭ �� ���� 1ĭ �̵��� �����ϴ�.
���� ������ ���� ���� ���� �� Ư�� ��ġ�� �־����� �� �̵��� �� �ִ� ����� ���� ���Ͻÿ�. 
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